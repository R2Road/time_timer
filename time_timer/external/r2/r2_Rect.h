#pragma once

#include <algorithm>
#include <cmath>

#include "r2_Point.h"
#include "r2_Size.h"

namespace r2
{
	template<typename T>
	class Rect
	{
	public:
		using ElementT = T;
		using MyPointT = r2::Point<T>;
		using MySizeT = r2::Size<T>;
		using MyT = Rect<T>;

		static const MyT& GetZero()
		{
			static const MyT rect_zero( 0, 0, 0, 0 );
			return rect_zero;
		}

		Rect() : mOrigin( 0, 0 ), mSize( 0, 0 )
		{}
		explicit Rect( const ElementT x, const ElementT y, const ElementT width, const ElementT height ) : mOrigin( x, y ), mSize( width, height )
		{}
		explicit Rect( const MyPointT origin, const MySizeT size ) : mOrigin( origin ), mSize( size )
		{}
		explicit Rect( const MyPointT origin, const ElementT width, const ElementT height ) : mOrigin( origin ), mSize( width, height )
		{}
		explicit Rect( const ElementT x, const ElementT y, const MySizeT size ) : mOrigin( x, y ), mSize( size )
		{}
		explicit Rect( const MyPointT origin ) : mOrigin( origin ), mSize( 0, 0 )
		{}
		explicit Rect( const MySizeT size ) : mOrigin( 0, 0 ), mSize( size )
		{}
		explicit Rect( const MyPointT point1, const MyPointT point2 )
		{
			Set( point1, point2 );
		}

		bool operator==( const MyT& rhs ) const
		{
			return mOrigin == rhs.GetOrigin() && mSize == rhs.GetSize();
		}
		MyT& operator= ( const MyT& other )
		{
			Set( other.mOrigin.GetX(), other.mOrigin.GetY(), other.mSize.GetWidth(), other.mSize.GetHeight() );
			return *this;
		}

		inline bool Equals( const MyT& rect ) const
		{
			return ( mOrigin.Equals( rect.mOrigin ) && mSize.equals( rect.mSize ) );
		}

		//
		//
		//
		inline void Set( const ElementT x, const ElementT y, const ElementT width, const ElementT height )
		{
			mOrigin.Set( x, y );
			mSize.Set( width, height );
		}
		inline void Set( const MyPointT point1, const MyPointT point2 )
		{
			Set(
				std::min( point1.GetX(), point2.GetX() )
				, std::min( point1.GetY(), point2.GetY() )
				, std::max( point1.GetX(), point2.GetX() ) - std::min( point1.GetX(), point2.GetX() )
				, std::max( point1.GetY(), point2.GetY() ) - std::min( point1.GetY(), point2.GetY() )
			);
		}

		//
		//
		//
		inline void SetOrigin( const ElementT x, const ElementT y )
		{
			mOrigin.Set( x, y );
		}
		inline void SetOrigin( const MyPointT point )
		{
			mOrigin = ( point );
		}
		inline void MoveOrigin( const ElementT move_x, const ElementT move_y )
		{
			mOrigin.Add( move_x, move_y );
		}

		//
		//
		//
		inline void SetSize( const ElementT width, const ElementT height )
		{
			mSize.Set( width, height );
		}
		inline void SetSize( const MySizeT size )
		{
			mSize = ( size );
		}
		inline void ChangeSize( const ElementT change_w, const ElementT change_h )
		{
			mSize.Add( change_w, change_h );
		}

		//
		//
		//
		inline const MyPointT& GetOrigin() const
		{
			return mOrigin;
		}
		inline const MySizeT& GetSize() const
		{
			return mSize;
		}
		inline ElementT GetMaxX() const
		{
			return mOrigin.GetX() + mSize.GetWidth();
		}
		inline ElementT GetMidX() const
		{
			return mOrigin.GetX() + ( mSize.GetWidth() / 2 );
		}
		inline ElementT GetMinX() const
		{
			return mOrigin.GetX();
		}
		inline ElementT GetMaxY() const
		{
			return mOrigin.GetY() + mSize.GetHeight();
		}
		inline ElementT GetMidY() const
		{
			return mOrigin.GetY() + ( mSize.GetHeight() / 2 );
		}
		inline ElementT GetMinY() const
		{
			return mOrigin.GetY();
		}
		inline ElementT GetWidth() const
		{
			//
			// Summury
			// - default size is "1"
			//
			// Example
			// - size 4, 3
			//  @***	- "@" is origin
			//  ****	- "*" is size
			//  ****
			//
			return std::abs( mSize.GetWidth() ) + 1;
		}
		inline ElementT GetHeight() const
		{
			return std::abs( mSize.GetHeight() ) + 1;
		}
		inline ElementT GetWide() const
		{
			return GetWidth() * GetHeight();
		}
		inline double GetDiagonalLength() const
		{
			return std::sqrt( ( GetWidth() * GetWidth() ) + ( GetHeight() * GetHeight() ) );
		}

		//
		//
		//
		bool ContainsPoint( const MyPointT& point ) const
		{
			bool bRet = false;

			if( point.GetX() >= GetMinX() && point.GetX() <= GetMaxX()
				&& point.GetY() >= GetMinY() && point.GetY() <= GetMaxY() )
			{
				bRet = true;
			}

			return bRet;
		}
		bool ContainsPoint( const ElementT x, const ElementT y ) const
		{
			bool bRet = false;

			if( x >= GetMinX() && x <= GetMaxX()
				&& y >= GetMinY() && y <= GetMaxY() )
			{
				bRet = true;
			}

			return bRet;
		}

		//
		//
		//
		MyPointT Distance( const MyPointT& point ) const
		{
			return Distance( point.GetX(), point.GetY() );
		}
		MyPointT Distance( const ElementT x, const ElementT y ) const
		{
			if( ContainsPoint( x, y ) )
			{
				return MyPointT::GetZero();
			}

			return MyPointT(
				std::min( std::abs( GetMinX() - x ), std::abs( GetMaxX() - x ) )
				, std::min( std::abs( GetMinY() - y ), std::abs( GetMaxY() - y ) )
			);
		}

		//
		//
		//
		bool IntersectsRect( const MyT& rect ) const
		{
			return !(
				GetMaxX() < rect.GetMinX()
				|| rect.GetMaxX() < GetMinX()
				|| GetMaxY() < rect.GetMinY()
				|| rect.GetMaxY() < GetMinY()
			);
		}
		bool ContainsRect( const MyT& rect ) const
		{
			return !(
				GetMinX() > rect.GetMinX()
				|| GetMaxX() < rect.GetMaxX()
				|| GetMinY() > rect.GetMinY()
				|| GetMaxY() < rect.GetMaxY()
			);
		}

		//
		//
		//
		void Merge( const MyT& rect )
		{
			const ElementT minX = std::min( GetMinX(), rect.GetMinX() );
			const ElementT minY = std::min( GetMinY(), rect.GetMinY() );
			const ElementT maxX = std::max( GetMaxX(), rect.GetMaxX() );
			const ElementT maxY = std::max( GetMaxY(), rect.GetMaxY() );
			Set( minX, minY, maxX - minX, maxY - minY );
		}

		//
		//
		//
		MyT UnionWithRect( const MyT & rect ) const
		{
			ElementT thisLeftX = GetMinX();
			ElementT thisRightX = GetMaxX();
			ElementT thisTopY = GetMinY();
			ElementT thisBottomY = GetMaxY();

			if( thisRightX < thisLeftX )
			{
				std::swap( thisRightX, thisLeftX );   // This rect has negative width
			}

			if( thisBottomY < thisTopY )
			{
				std::swap( thisTopY, thisBottomY );   // This rect has negative height
			}

			ElementT otherLeftX = rect.GetMinX();
			ElementT otherRightX = rect.GetMaxX();
			ElementT otherTopY = rect.GetMinY();
			ElementT otherBottomY = rect.GetMaxY();

			if( otherRightX < otherLeftX )
			{
				std::swap( otherRightX, otherLeftX );   // Other rect has negative width
			}

			if( otherBottomY < otherTopY )
			{
				std::swap( otherTopY, otherBottomY );   // Other rect has negative height
			}

			ElementT combinedLeftX = std::min( thisLeftX, otherLeftX );
			ElementT combinedRightX = std::max( thisRightX, otherRightX );
			ElementT combinedTopY = std::min( thisTopY, otherTopY );
			ElementT combinedBottomY = std::max( thisBottomY, otherBottomY );

			return MyT( combinedLeftX, combinedTopY, combinedRightX - combinedLeftX, combinedBottomY - combinedTopY );
		}

		//
		//
		//
		MyT IntersectsWithRect( const MyT & rect ) const
		{
			ElementT thisLeftX = GetMinX();
			ElementT thisRightX = GetMaxX();
			ElementT thisTopY = GetMinY();
			ElementT thisBottomY = GetMaxY();

			if( thisRightX < thisLeftX )
			{
				std::swap( thisRightX, thisLeftX );   // This rect has negative width
			}

			if( thisBottomY < thisTopY )
			{
				std::swap( thisTopY, thisBottomY );   // This rect has negative height
			}

			ElementT otherLeftX = rect.GetMinX();
			ElementT otherRightX = rect.GetMaxX();
			ElementT otherTopY = rect.GetMinY();
			ElementT otherBottomY = rect.GetMaxY();

			if( otherRightX < otherLeftX )
			{
				std::swap( otherRightX, otherLeftX );   // Other rect has negative width
			}

			if( otherBottomY < otherTopY )
			{
				std::swap( otherTopY, otherBottomY );   // Other rect has negative height
			}

			ElementT combinedLeftX = std::max( thisLeftX, otherLeftX );
			ElementT combinedRightX = std::min( thisRightX, otherRightX );
			ElementT combinedTopY = std::max( thisTopY, otherTopY );
			ElementT combinedBottomY = std::min( thisBottomY, otherBottomY );

			return MyT( combinedLeftX, combinedTopY, combinedRightX - combinedLeftX, combinedBottomY - combinedTopY );
		}

	private:
		MyPointT mOrigin;
		MySizeT mSize;
	};
}
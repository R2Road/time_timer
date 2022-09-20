#pragma once

#include <algorithm>
#include <limits>
#include <type_traits>

#include "r2_Assert.h"

namespace r2
{
	template<typename T>
	class Timer
	{
	public:
		static_assert(
			std::is_same<float, T>::value
			|| std::is_same<double, T>::value
			, "r2::Timer - Not Allowed Type"
			);
		using ValueT = T;
		const ValueT ValueMAX = std::numeric_limits<ValueT>::max();
		const ValueT ValueZERO = static_cast<ValueT>( 0 );
		const ValueT ValueONE = static_cast<ValueT>( 1 );

		Timer() :
			mAlive( false )
			, mLimitTime( ValueZERO )
			, mElapsedTime( ValueZERO )
		{}
		Timer( const ValueT limit_time ) :
			mAlive( false )
			, mLimitTime( limit_time )
			, mElapsedTime( ValueZERO )
		{}
		Timer( const ValueT limit_time, const bool on_timer ) :
			mAlive( on_timer )
			, mLimitTime( limit_time )
			, mElapsedTime( ValueZERO )
		{}

		//
		//
		//
		void Start()
		{
			mElapsedTime = ValueZERO;
			mAlive = true;
		}
		void Stop()
		{
			mAlive = false;
		}
		void Clear()
		{
			mElapsedTime = ValueZERO;
			mAlive = false;
		}

		//
		//
		//
		void Flip()
		{
			mElapsedTime = std::min( mElapsedTime, mLimitTime );
			mElapsedTime = mLimitTime - mElapsedTime;
		}
		void KeepGoing()
		{
			mAlive = true;
		}

		//
		//
		//
		void SetLimitTime( const ValueT new_limit_time )
		{
			mLimitTime = new_limit_time;
		}
		void IncreaseLimitTime( const ValueT additional_time )
		{
			mLimitTime += additional_time;
		}

		//
		//
		//
		bool Update( const ValueT dt )
		{
			if( !mAlive )
			{
				return false;
			}

			R2ASSERT( dt <= ( ValueMAX - mElapsedTime ), "" );

			mElapsedTime += dt;

			if( mLimitTime <= mElapsedTime )
			{
				mAlive = false;
			}

			return mAlive;
		}

		//
		//
		//
		bool IsAlive() const
		{
			return mAlive;
		}
		bool IsDie() const
		{
			return !IsAlive();
		}
		ValueT GetElapsedTime() const
		{
			return mElapsedTime;
		}
		ValueT GetLimitTime() const
		{
			return mLimitTime;
		}

		//
		//
		//
		ValueT GetElapsedTimeRate() const
		{
			if( mElapsedTime >= mLimitTime )
			{
				return ValueONE;
			}
			else
			{
				return ( ValueZERO >= mLimitTime ? ValueZERO : mElapsedTime / mLimitTime );
			}
		}
		ValueT GetElapsedTimeInverseRate() const
		{
			return 1.f - GetElapsedTimeRate();
		}
		const ValueT GetElapsedTimePureRate() const
		{
			return ( ValueZERO >= mLimitTime ? ValueZERO : mElapsedTime / mLimitTime );
		}

	private:
		bool mAlive;
		ValueT mLimitTime;
		ValueT mElapsedTime;
	};
}

#pragma once

#include "r2base_Component.h"

#include "r2/r2_PointInt.h"

namespace r2component
{
	class TransformComponent : public r2base::Component<TransformComponent>
	{
	public:
		TransformComponent( r2base::Node& owner_node );

		//
		// Getter
		//
		r2::PointInt GetPosition() const
		{
			return mPosition;
		}
		int32_t GetPositionX() const
		{
			return mPosition.GetX();
		}
		int32_t GetPositionY() const
		{
			return mPosition.GetY();
		}
		int32_t GetZ() const
		{
			return mZOrder;
		}

		//
		// Setter
		//
		void SetPosition( const int32_t new_x, const int32_t new_y )
		{
			mPosition.Set( new_x, new_y );
		}
		void SetPosition( const float new_x, const float new_y )
		{
			mPosition.Set( static_cast<int>( new_x ), static_cast<int>( new_y ) );
		}
		void SetPosition( const r2::PointInt new_position )
		{
			mPosition = new_position;
		}
		void SetPositionX( const r2::PointInt::ValueT new_x )
		{
			mPosition.SetX( new_x );
		}
		void SetPositionY( const r2::PointInt::ValueT new_y )
		{
			mPosition.SetY( new_y );
		}
		void SetZ( const int32_t new_z_order )
		{
			mZOrder = new_z_order;
		}

	private:
		r2::PointInt mPosition;
		int32_t mZOrder;
	};
}
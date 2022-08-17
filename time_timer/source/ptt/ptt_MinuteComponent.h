#pragma once

#include "r2bix/r2base_Component.h"

namespace ptt
{
	class NumberComponent;

	class MinuteComponent : public r2base::Component<MinuteComponent>
	{
	public:
		MinuteComponent( r2base::Node& owner_node );

		//
		//
		//
		void SetNumberComponent( ptt::NumberComponent* const number_component_10_min, ptt::NumberComponent* const number_component_1_min )
		{
			mNumberComponent_10_Minute = number_component_10_min;
			mNumberComponent_1_Minute = number_component_1_min;
		}
		void SetMinute( const int new_minute_10_0_to_9, const int new_minute_1_0_to_9 );

	private:
		ptt::NumberComponent* mNumberComponent_10_Minute;
		ptt::NumberComponent* mNumberComponent_1_Minute;
	};
}
#include "ptt_MinuteComponent.h"

#include "r2/r2_Assert.h"

#include "ptt/ptt_NumberComponent.h"

namespace ptt
{
	MinuteComponent::MinuteComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
		, mNumberComponent_10_Minute( nullptr )
		, mNumberComponent_1_Minute( nullptr )
	{}

	std::unique_ptr<MinuteComponent> MinuteComponent::Create( r2base::Node& owner_node )
	{
		std::unique_ptr<MinuteComponent> ret( new ( std::nothrow ) MinuteComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}

	void MinuteComponent::SetMinute( const int new_minute_10_0_to_9, const int new_minute_1_0_to_9 )
	{
		R2ASSERT( 0 <= new_minute_10_0_to_9 && new_minute_10_0_to_9 < 10, "" );
		R2ASSERT( 0 <= new_minute_1_0_to_9 && new_minute_1_0_to_9 < 10, "" );

		mNumberComponent_10_Minute->SetNumber( new_minute_10_0_to_9 );
		mNumberComponent_1_Minute->SetNumber( new_minute_1_0_to_9 );
	}
}
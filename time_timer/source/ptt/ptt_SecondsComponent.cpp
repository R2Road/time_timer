#include "ptt_SecondsComponent.h"

#include "r2bix/r2base_Node.h"

namespace ptt
{
	SecondsComponent::SecondsComponent( r2base::Node& owner_node ) : r2base::Component<SecondsComponent>( owner_node )
		, mLastSeconds( 0 )
	{}

	void SecondsComponent::Toggle( const int new_seconds_0_to_9 )
	{
		if( new_seconds_0_to_9 == mLastSeconds )
		{
			return;
		}

		mLastSeconds = new_seconds_0_to_9;

		GetOwnerNode().SetVisible( !GetOwnerNode().IsVisible() );
	}
}
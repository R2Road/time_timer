#include "ptt_SecondsComponent.h"

#include "r2bix/r2base_Node.h"

namespace ptt
{
	SecondsComponent::SecondsComponent( r2base::Node& owner_node ) : r2base::Component<SecondsComponent>( owner_node )
		, mbFlag( owner_node.IsVisible() )
	{}

	void SecondsComponent::Toggle( const int64_t seconds )
	{
		const bool new_flag = seconds & 1;

		if( new_flag == mbFlag )
		{
			return;
		}

		mbFlag = new_flag;

		GetOwnerNode().SetVisible( mbFlag );
	}
}
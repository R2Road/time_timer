#include "ptt_SecondsComponent.h"

#include "r2bix/r2base_Node.h"

namespace ptt
{
	SecondsComponent::SecondsComponent( r2base::Node& owner_node ) : r2base::Component<SecondsComponent>( owner_node )
	{}

	void SecondsComponent::Toggle()
	{
		GetOwnerNode().SetVisible( !GetOwnerNode().IsVisible() );
	}
}
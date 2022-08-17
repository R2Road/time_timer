#include "r2component_TransformComponent.h"

namespace r2component
{
	TransformComponent::TransformComponent( r2base::Node& owner_node ) : r2base::Component<TransformComponent>( owner_node )
		, mPosition()
		, mZOrder( 0 )
	{}
}
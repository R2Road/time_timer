#include "r2component_CustomTextureComponent.h"

namespace r2component
{
	CustomTextureComponent::CustomTextureComponent( r2base::Node& owner_node ) : r2base::Component<CustomTextureComponent>( owner_node )
		, mTexture( 1, 1, ' ')
	{}
}
#include "r2node_LabelMNode.h"

#include "r2base_Director.h"
#include "r2component_CustomTextureComponent.h"
#include "r2component_TextureRenderComponent.h"
#include "r2component_LabelSComponent.h"

namespace r2node
{
	r2base::NodeUp LabelMNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			r2component::CustomTextureComponent* custom_texture_component = ret->AddComponent<r2component::CustomTextureComponent>();
			r2component::TextureRenderComponent* texture_render_component = ret->AddComponent<r2component::TextureRenderComponent>();
			r2component::LabelSComponent* label_component = ret->AddComponent<r2component::LabelSComponent>();

			label_component->SetCustomTextureComponent( custom_texture_component );
			label_component->SetTextureRenderComponent( texture_render_component );

			texture_render_component->SetTexture( custom_texture_component->GetTexture() );
		}

		return ret;
	}
}
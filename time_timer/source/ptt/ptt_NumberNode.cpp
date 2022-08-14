#include "ptt_NumberNode.h"

#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "ptt/ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp NumberNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			auto frame_animation_component = ret->AddComponent<r2component::TextureFrameAnimationComponent>();
			auto frame_render_component = ret->AddComponent<r2component::TextureFrameRenderComponent>();

			frame_animation_component->SetTextureFrameRenderComponent( frame_render_component );
		}

		return ret;
	}
}
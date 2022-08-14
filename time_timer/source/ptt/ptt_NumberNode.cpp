#include "ptt_NumberNode.h"

#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "ptt_NumberComponent.h"

namespace ptt
{
	r2base::NodeUp NumberNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			auto frame_render_component = ret->AddComponent<r2component::TextureFrameRenderComponent>();
			frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "number_0" ) );

			auto frame_animation_component = ret->AddComponent<r2component::TextureFrameAnimationComponent>();
			frame_animation_component->SetTextureFrameRenderComponent( frame_render_component );
			frame_animation_component->LoadAnimation( ptt::TextureFrameAnimationTable::GetInstance().Get( 1 ) );

			auto number_component = ret->AddComponent<ptt::NumberComponent>();
			number_component->SetTextureFrameAnimationComponent( frame_animation_component );
		}

		return ret;
	}
}
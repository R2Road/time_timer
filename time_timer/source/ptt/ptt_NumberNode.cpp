#include "ptt_NumberNode.h"

#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_DebugConfig.h"
#include "ptt_NumberComponent.h"
#include "ptt_TextureFrameAnimationTable.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp NumberNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			//
			// Setup
			//
			{
				auto frame_render_component = ret->AddComponent<r2component::TextureFrameRenderComponent>();
				frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "number_0" ) );

				auto frame_animation_component = ret->AddComponent<r2component::TextureFrameAnimationComponent>();
				frame_animation_component->SetTextureFrameRenderComponent( frame_render_component );
				frame_animation_component->LoadAnimation( ptt::TextureFrameAnimationTable::GetInstance().Get( 1 ) );

				auto number_component = ret->AddComponent<ptt::NumberComponent>();
				number_component->SetTextureFrameAnimationComponent( frame_animation_component );
			}

			//
			// Debug
			//
			if( ptt::Config::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>();
			}
		}

		return ret;
	}
}
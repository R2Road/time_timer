#include "ptt_ChangeIndicatorNode.h"

#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_DebugConfig.h"
#include "ptt_TextureFrameAnimationTable.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp ChangeIndicatorNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			//
			// Setup
			//
			{
				{
					auto arrow_node = ret->AddChild<r2base::Node>();

					//
					arrow_node->GetComponent<r2component::TransformComponent>()->SetPositionY( -6 );

					//
					auto texture_frame_render_component = arrow_node->AddComponent<r2component::TextureFrameRenderComponent>();

					//
					auto texture_frame_animation_component = arrow_node->AddComponent<r2component::TextureFrameAnimationComponent>();
					texture_frame_animation_component->LoadAnimation( ptt::TextureFrameAnimationTable::GetInstance().Get( 2 ) );

					//
					texture_frame_animation_component->SetTextureFrameRenderComponent( texture_frame_render_component );
					texture_frame_animation_component->RunAnimation_Repeat( r2animation::eIndex::Idle_0 );
				}

				{
					auto arrow_node = ret->AddChild<r2base::Node>();

					//
					arrow_node->GetComponent<r2component::TransformComponent>()->SetPositionY( 7 );

					//
					auto texture_frame_render_component = arrow_node->AddComponent<r2component::TextureFrameRenderComponent>();

					//
					auto texture_frame_animation_component = arrow_node->AddComponent<r2component::TextureFrameAnimationComponent>();
					texture_frame_animation_component->LoadAnimation( ptt::TextureFrameAnimationTable::GetInstance().Get( 3 ) );

					//
					texture_frame_animation_component->SetTextureFrameRenderComponent( texture_frame_render_component );
					texture_frame_animation_component->RunAnimation_Repeat( r2animation::eIndex::Idle_0 );
				}
			}

			//
			// Debug
			//
			if( ptt::DebugConfig::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>();
			}
		}

		return ret;
	}
}
#include "ptt_SelectIndicatorNode.h"

#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_DebugConfig.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp SelectIndicatorNode::Create( r2bix::Director& director )
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
					arrow_node->GetComponent<r2component::TransformComponent>()->SetPositionX( -16 );

					//
					auto texture_frame_render_component = arrow_node->AddComponent<r2component::TextureFrameRenderComponent>();
					texture_frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "select_indicator_left_0" ) );
				}

				{
					auto arrow_node = ret->AddChild<r2base::Node>();

					//
					arrow_node->GetComponent<r2component::TransformComponent>()->SetPositionX( 16 );

					//
					auto texture_frame_render_component = arrow_node->AddComponent<r2component::TextureFrameRenderComponent>();
					texture_frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "select_indicator_right_0" ) );
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
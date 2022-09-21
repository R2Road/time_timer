#include "ptt_SecondsNode.h"

#include <cmath>

#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2component_TransformComponent.h"

#include "ptt_DebugConfig.h"
#include "ptt_SecondsComponent.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp SecondsNode::Create( r2bix::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddComponent<ptt::SecondsComponent>();

			//
			// Setup
			//
			{
				{
					auto node = ret->AddChild<r2base::Node>();

					auto texture_frame_render_component = node->AddComponent<r2component::TextureFrameRenderComponent>();
					texture_frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "seconds_0" ) );
					node->GetComponent<r2component::TransformComponent>()->SetPositionY( 4 );
				}

				{
					auto node = ret->AddChild<r2base::Node>();

					auto texture_frame_render_component = node->AddComponent<r2component::TextureFrameRenderComponent>();
					texture_frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "seconds_0" ) );
					node->GetComponent<r2component::TransformComponent>()->SetPositionY( -4 );
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
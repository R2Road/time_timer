#include "ptt_SecondsNode.h"

#include <cmath>

#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "ptt_Config.h"
#include "ptt_SecondsComponent.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp SecondsNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddComponent<ptt::SecondsComponent>();

			//
			//
			//
			{
				auto texture_frame_render_component = ret->AddComponent<r2component::TextureFrameRenderComponent>();
				texture_frame_render_component->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "seconds_0" ) );
			}


			//
			//
			//
			if( ptt::Config::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>();
			}

		}

		return ret;
	}
}
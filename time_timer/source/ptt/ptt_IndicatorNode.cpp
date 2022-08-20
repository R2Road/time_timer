#include "ptt_IndicatorNode.h"

#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_Config.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp IndicatorNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			//
			//
			//
			{
				auto tfrc = ret->AddComponent<r2component::TextureFrameRenderComponent>();
				tfrc->SetTextureFrame( ptt::TextureTable::GetInstance().GetTextureFrame( "indicator_0" ) );
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
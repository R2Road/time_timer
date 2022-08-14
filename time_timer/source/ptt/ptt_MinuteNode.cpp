#include "ptt_MinuteNode.h"

#include <cmath>

#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2render_TextureFrame.h"

#include "ptt_NumberNode.h"

namespace ptt
{
	r2base::NodeUp MinuteNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			//
			//
			//
			ret->AddChild<r2node::PivotNode>();

			//
			//
			//
			{
				auto number_node = ret->AddChild<ptt::NumberNode>();
				number_node->mTransformComponent->SetPosition(
					-static_cast<int32_t>( std::ceil( number_node->GetComponent<r2component::TextureFrameRenderComponent>()->GetTextureFrame()->GetWidth() * 0.5f ) )
					, 0
				);
			}
			{
				auto number_node = ret->AddChild<ptt::NumberNode>();
				number_node->mTransformComponent->SetPosition(
					static_cast<int32_t>( std::ceil( number_node->GetComponent<r2component::TextureFrameRenderComponent>()->GetTextureFrame()->GetWidth() * 0.5f ) )
					, 0
				);
			}
		}

		return ret;
	}
}
#include "ptt_MinuteNode.h"

#include <cmath>

#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2render_TextureFrame.h"

#include "ptt_MinuteComponent.h"
#include "ptt_NumberComponent.h"
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
				auto number_node_1 = ret->AddChild<ptt::NumberNode>();
				number_node_1->mTransformComponent->SetPositionX(
					-static_cast<int32_t>( std::ceil( number_node_1->GetComponent<r2component::TextureFrameRenderComponent>()->GetTextureFrame()->GetWidth() * 0.5f ) )
				);

				auto number_node_2 = ret->AddChild<ptt::NumberNode>();
				number_node_2->mTransformComponent->SetPositionX(
					static_cast<int32_t>( std::ceil( number_node_2->GetComponent<r2component::TextureFrameRenderComponent>()->GetTextureFrame()->GetWidth() * 0.5f ) )
				);

				auto minute_component = ret->AddComponent<ptt::MinuteComponent>();
				minute_component->SetNumberComponent( number_node_1->GetComponent<ptt::NumberComponent>(), number_node_2->GetComponent<ptt::NumberComponent>() );
			}
		}

		return ret;
	}
}
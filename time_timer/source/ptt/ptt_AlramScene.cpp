#include "ptt_AlramScene.h"

#include <numeric>
#include <utility>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2component_LabelSComponent.h"
#include "r2bix/r2component_LabelMComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_LabelMNode.h"
#include "r2bix/r2node_LabelSNode.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_AlramEffectNode.h"
#include "ptt_AlramSceneComponent.h"
#include "ptt_DebugConfig.h"

namespace ptt
{
	r2node::SceneNodeUp AlramScene::Create( r2bix::Director& director, CoreUp&& core )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			//
			//
			//
			auto alram_scene_component = ret->AddComponent<ptt::AlramSceneComponent>();
			alram_scene_component->SetCore( std::move( core ) );

			//
			// Effect
			//
			{
				ret->AddChild<ptt::AlramEffectNode>();
			}

			//
			// You Win
			//
			{
				auto node = ret->AddChild<r2node::LabelSNode>();
				node->GetComponent<r2component::LabelSComponent>()->SetString( "### You Win ###" );

				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);
			}

			//
			// Exit Indicator
			//
			{
				auto node = ret->AddChild<r2node::LabelMNode>();
				node->GetComponent<r2component::LabelMComponent>()->SetString(
					      "<<< ESC | SPACE" "  "
					"\n"
				);
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 0.f, 0.f );

				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					0
					, 0
				);
			}

			//
			// More Minutes
			//
			{
				auto node = ret->AddChild<r2node::LabelMNode>();
				node->GetComponent<r2component::LabelMComponent>()->SetString(

					"\n"  "  "  "A | + 1 => "
					"\n"  "  "  "W | + 5 => "
					"\n"  "  "  "D | +10 => "
					"\n"  "  "  "S | +15 => "
				);
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 1.f, 1.f );

				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					director.GetScreenBufferSize().GetWidth()
					, director.GetScreenBufferSize().GetHeight()
				);
			}

			//
			// Debug
			//
			if( ptt::DebugConfig::GetNodeConfig().pivot )
			{
				//
				//
				//
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() );
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( director.GetScreenBufferSize().GetWidth() - 1, 0 );
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( director.GetScreenBufferSize().GetWidth() - 1, director.GetScreenBufferSize().GetHeight() - 1 );
				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( 0, director.GetScreenBufferSize().GetHeight() - 1 );

				ret->AddChild<r2node::PivotNode>( std::numeric_limits<int>::max() )->mTransformComponent->SetPosition( director.GetScreenBufferSize().GetWidth() * 0.5f, director.GetScreenBufferSize().GetHeight() * 0.5f );
			}

		}

		return ret;
	}
}
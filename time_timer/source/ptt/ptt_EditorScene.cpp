#include "ptt_EditorScene.h"

#include <numeric>
#include <utility>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2component_LabelSComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_LabelSNode.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_ChangeIndicatorNode.h"
#include "ptt_DebugConfig.h"
#include "ptt_EditorSceneComponent.h"
#include "ptt_MinuteComponent.h"
#include "ptt_MinuteNode.h"
#include "ptt_SelectIndicatorNode.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2node::SceneNodeUp EditorScene::Create( r2bix::Director& director, CoreUp&& core )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			//
			// Component
			//
			auto editor_scene_component = ret->AddComponent<ptt::EditorSceneComponent>();
			editor_scene_component->SetCore( std::move( core ) );

			//
			// Select Indicator
			//
			{
				auto node = ret->AddChild<ptt::SelectIndicatorNode>();

				auto transform_component = node->GetComponent<r2component::TransformComponent>();
				transform_component->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);
			}

			//
			// Change Indicator
			//
			{
				auto node = ret->AddChild<ptt::ChangeIndicatorNode>();

				auto transform_component = node->GetComponent<r2component::TransformComponent>();
				transform_component->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);

				editor_scene_component->SetIndicatorComponent( transform_component );
			}

			//
			// Minute
			//
			{
				auto node = ret->AddChild<ptt::MinuteNode>();
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);

				editor_scene_component->SetMinuteComponent( node->GetComponent<ptt::MinuteComponent>() );
			}

			//
			// Exit Indicator
			//
			{
				auto node = ret->AddChild<r2node::LabelSNode>();
				node->GetComponent<r2component::LabelSComponent>()->SetString( "<<< ESC" );
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 0.f, 0.f );
			}

			//
			// Start Indicator
			//
			{
				auto node = ret->AddChild<r2node::LabelSNode>();
				node->GetComponent<r2component::LabelSComponent>()->SetString( "SPACE => " );
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

			//
			// Setup
			//
			editor_scene_component->Setup();
		}

		return ret;
	}
}
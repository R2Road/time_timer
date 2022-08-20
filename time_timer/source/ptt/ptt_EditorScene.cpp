#include "ptt_EditorScene.h"

#include <numeric>
#include <utility>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_Config.h"
#include "ptt_EditorSceneComponent.h"
#include "ptt_IndicatorNode.h"
#include "ptt_MinuteComponent.h"
#include "ptt_MinuteNode.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2node::SceneNodeUp EditorScene::Create( r2base::Director& director, CoreUp&& core )
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
			// Indicator
			//
			{
				auto node = ret->AddChild<ptt::IndicatorNode>();

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
			// Debug
			//
			if( ptt::Config::GetNodeConfig().pivot )
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
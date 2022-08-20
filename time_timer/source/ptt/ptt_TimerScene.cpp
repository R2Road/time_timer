#include "ptt_TimerScene.h"

#include <numeric>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_LabelSComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_CustomTextureNode.h"
#include "r2bix/r2node_LabelSNode.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_Config.h"
#include "ptt_MinuteComponent.h"
#include "ptt_MinuteNode.h"
#include "ptt_SecondsComponent.h"
#include "ptt_SecondsNode.h"
#include "ptt_TimerSceneComponent.h"

namespace ptt
{
	r2node::SceneNodeUp TimerScene::Create( r2base::Director& director, CoreUp&& core )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			//
			// Component
			//
			auto timer_scene_component = ret->AddComponent<ptt::TimerSceneComponent>();
			timer_scene_component->SetCore( std::move( core ) );


			//
			// Minute
			//
			{
				auto node = ret->AddChild<ptt::MinuteNode>();
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);

				timer_scene_component->SetMinuteComponent( node->GetComponent<ptt::MinuteComponent>() );
			}

			//
			// Seconds
			//
			{
				auto node = ret->AddChild<ptt::SecondsNode>();
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.5f )
				);

				timer_scene_component->SetSecondsComponent( node->GetComponent<ptt::SecondsComponent>() );
			}

			//
			// Exit Indicator
			//
			{
				auto node = ret->AddChild<r2node::LabelSNode>();
				node->GetComponent<r2component::LabelSComponent>()->SetString( "<<< ESC" );
				node->GetComponent<r2component::TextureRenderComponent>()->SetPivotPoint( 0.f, 0.f );

				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					0
					, 0
				);
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
			timer_scene_component->Setup();
		}

		return ret;
	}
}
#include "ptt_AlramScene.h"

#include <numeric>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2node_PivotNode.h"

#include "ptt_Config.h"

namespace ptt
{
	r2node::SceneNodeUp AlramScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{

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

		}

		return ret;
	}
}
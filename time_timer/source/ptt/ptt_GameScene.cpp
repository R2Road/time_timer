#include "ptt_GameScene.h"

#include <numeric>

#include "r2bix/r2action_SequenceAction.h"
#include "r2bix/r2action_DelayAction.h"
#include "r2bix/r2action_MoveByAction.h"
#include "r2bix/r2action_MoveToAction.h"
#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_ActionProcessComponent.h"
#include "r2bix/r2component_CustomTextureComponent.h"
#include "r2bix/r2component_LabelSComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"
#include "r2bix/r2node_CustomTextureNode.h"
#include "r2bix/r2node_LabelSNode.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2node_SpriteNode.h"

#include "ptt/ptt_TextureTable.h"

namespace ptt
{
	r2node::SceneNodeUp GameScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			//
			// Table Load
			//
			ptt::TextureTable::GetInstance().Load();


			//
			// Title
			//
			{
				auto node = ret->AddChild<r2node::LabelSNode>();
				node->GetComponent<r2component::LabelSComponent>()->SetString( "timer timer" );
				node->GetComponent<r2component::TransformComponent>()->SetPosition(
					( director.GetScreenBufferSize().GetWidth() * 0.5f )
					, ( director.GetScreenBufferSize().GetHeight() * 0.11f )
				);
			}
		}

		return ret;
	}
}
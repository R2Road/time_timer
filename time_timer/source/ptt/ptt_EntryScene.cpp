#include "ptt_EntryScene.h"

#include "r2bix/r2base_Director.h"

#include "ptt_Core.h"
#include "ptt_EditorScene.h"
#include "ptt_TextureTable.h"
#include "ptt_TextureFrameAnimationTable.h"

namespace ptt
{
	class EntrySceneComponent : public r2base::Component<EntrySceneComponent>
	{
	public:
		EntrySceneComponent( r2base::Node& owner_node ) : r2base::Component<EntrySceneComponent>( owner_node ) {}

		//
		//
		//
		void Update( const float delta_time ) override
		{
			r2base::iComponent::Update( delta_time );

			//
			// Table Load
			//
			ptt::TextureTable::GetInstance().Load();
			ptt::TextureFrameAnimationTable::GetInstance().Load();

			//
			// Core
			//
			auto core = ptt::Core::Create();

			//
			// Scene
			//
			auto next_scene = ptt::EditorScene::Create( mOwnerNode.GetDirector(), std::move( core ) );

			//
			// Go Next 
			//
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
		}
	};

	r2node::SceneNodeUp EntryScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			ret->AddComponent<EntrySceneComponent>();
		}

		return ret;
	}
}
#include "ptt_EntryScene.h"

#include <numeric>

#include "r2bix/r2base_Director.h"

#include "ptt/ptt_Core.h"
#include "ptt/ptt_EditorComponent.h"
#include "ptt/ptt_EditorScene.h"
#include "ptt/ptt_TextureTable.h"

namespace ptt
{
	class EntryComponent : public r2base::Component<EntryComponent>
	{
	public:
		EntryComponent( r2base::Node& owner_node ) : r2base::Component<EntryComponent>( owner_node ) {}

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

			//
			// Core
			//
			auto core = ptt::Core::Create();

			//
			// Go Next Scene
			//
			auto next_scene = ptt::EditorScene::Create( mOwnerNode.GetDirector() );
			next_scene->GetComponent<ptt::EditorComponent>()->SetCore( std::move( core ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
		}
	};

	r2node::SceneNodeUp EntryScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			ret->AddComponent<EntryComponent>();
		}

		return ret;
	}
}
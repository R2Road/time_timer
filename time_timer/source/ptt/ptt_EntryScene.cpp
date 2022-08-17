#include "ptt_EntryScene.h"

#include <numeric>

#include "r2bix/r2base_Director.h"

#include "ptt/ptt_EditorScene.h"
#include "ptt/ptt_TextureTable.h"

namespace ptt
{
	class EntryComponent : public r2base::Component
	{
	public:
		using MyT = EntryComponent;
		using MyUniquePtrT = std::unique_ptr<MyT>;

	private:
		EntryComponent( r2base::Node& owner_node ) : r2base::Component( owner_node ) {}

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<MyT>::Get(); }
		static MyUniquePtrT Create( r2base::Node& owner_node )
		{
			MyUniquePtrT ret( new ( std::nothrow ) MyT( owner_node ) );
			if( !ret || !ret->Init() )
			{
				ret.reset();
			}

			return ret;
		}

	public:
		void Update( const float delta_time ) override
		{
			r2base::Component::Update( delta_time );

			//
			// Table Load
			//
			ptt::TextureTable::GetInstance().Load();

			//
			// Go Next Scene
			//
			auto next_scene = ptt::EditorScene::Create( mOwnerNode.GetDirector() );
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
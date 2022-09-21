#include "ptt_AlramSceneComponent.h"

#include <utility>
#include <iostream>

#include "r2/r2_Assert.h"

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2base_Node.h"

#include "ptt_Core.h"

#include "ptt_EditorScene.h"

namespace ptt
{
	AlramSceneComponent::AlramSceneComponent( r2base::Node& owner_node ) : r2base::Component<AlramSceneComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// 0 : esc
			, 0x20		// 1 : space
		} )
		, mCore()
		, mTimer( 5 )
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}
	AlramSceneComponent::~AlramSceneComponent()
	{
		GetOwnerNode().GetDirector().RemoveInputListener( &mKeyboardInputListener );
	}

	void AlramSceneComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();

		if( !mTimer.Update() )
		{
			//
			// beep
			//
			std::cout << '\a';

			mTimer.Start();
		}
		//
		// Move 2 Editor Scene
		//
		if( mKeyboardInputListener.IsRelease( 0 ) || mKeyboardInputListener.IsRelease( 1 ) )
		{
			auto next_scene = ptt::EditorScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
			return;
		}

		r2base::iComponent::Update( delta_time );
	}

	void AlramSceneComponent::SetCore( CoreUp&& core )
	{
		R2ASSERT( nullptr == mCore, "" );
		R2ASSERT( nullptr != core, "" );

		mCore = std::move( core );
	}
}
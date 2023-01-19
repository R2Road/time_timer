#include "ptt_AlramSceneComponent.h"

#include <utility>
#include <iostream>

#include "r2/r2_Assert.h"

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2base_Node.h"

#include "ptt_Core.h"

#include "ptt_EditorScene.h"
#include "ptt_TimerScene.h"

namespace ptt
{
	AlramSceneComponent::AlramSceneComponent( r2base::Node& owner_node ) : r2base::Component<AlramSceneComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// 0 : esc
			, 0x20		// 1 : space
			, 0x41		// 2 : a - left
			, 0x44		// 3 : d - right
			, 0x53		// 4 : s - down
			, 0x57		// 5 : w - up
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
		// More Minutes : 5, 10, 15, 20
		//
		if( mKeyboardInputListener.IsPushed( 2 ) ) // 'a'
		{
			mCore->GetPlayTime().SetMinute( 0, 5 );

			auto next_scene = ptt::TimerScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
			return;
		}
		if( mKeyboardInputListener.IsPushed( 3 ) ) // 'd'
		{
			mCore->GetPlayTime().SetMinute( 1, 5 );

			auto next_scene = ptt::TimerScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
			return;
		}
		if( mKeyboardInputListener.IsPushed( 4 ) ) // 's'
		{
			mCore->GetPlayTime().SetMinute( 2, 0 );

			auto next_scene = ptt::TimerScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
			return;
		}
		if( mKeyboardInputListener.IsPushed( 5 ) ) // 'w'
		{
			mCore->GetPlayTime().SetMinute( 1, 0 );

			auto next_scene = ptt::TimerScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
			return;
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
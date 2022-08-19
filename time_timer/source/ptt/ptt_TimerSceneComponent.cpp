#include "ptt_TimerSceneComponent.h"

#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2utility_InputUtil.h"

#include "ptt_Core.h"
#include "ptt_EditorScene.h"
#include "ptt_MinuteComponent.h"

namespace ptt
{
	TimerSceneComponent::TimerSceneComponent( r2base::Node& owner_node ) : r2base::Component<TimerSceneComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// 0 : esc
		} )
		, mCore()

		, mMinuteComponent( nullptr )
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}

	void TimerSceneComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();

		//
		// Move 2 Editor Scene
		//
		if( mKeyboardInputListener.IsRelease( 0 ) )
		{
			auto next_scene = ptt::EditorScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
			return;
		}

		r2base::iComponent::Update( delta_time );
	}

	void TimerSceneComponent::SetCore( CoreUp&& core )
	{
		R2ASSERT( nullptr == mCore, "" );
		R2ASSERT( nullptr != core, "" );

		mCore = std::move( core );
	}
	void TimerSceneComponent::SetMinuteComponent( MinuteComponent* const minute_component )
	{
		R2ASSERT( nullptr != minute_component, "" );

		mMinuteComponent = minute_component;
	}

	void TimerSceneComponent::Setup()
	{
		mMinuteComponent->SetMinute( mCore->GetMinute10(), mCore->GetMinute1() );
	}
}
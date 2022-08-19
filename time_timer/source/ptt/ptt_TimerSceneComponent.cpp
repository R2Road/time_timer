#include "ptt_TimerSceneComponent.h"

#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2utility_InputUtil.h"

#include "ptt_Core.h"
#include "ptt_EditorScene.h"
#include "ptt_MinuteComponent.h"
#include "ptt_SecondsComponent.h"

namespace ptt
{
	TimerSceneComponent::TimerSceneComponent( r2base::Node& owner_node ) : r2base::Component<TimerSceneComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// 0 : esc
			, 0x20		// 1 : space
		} )
		, mCore()

		, mMinuteComponent( nullptr )
		, mSecondsComponent( nullptr )
		, mTimer()
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}

	void TimerSceneComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();

		switch( mTimer.GetStatus() )
		{
		case ptt::Timer::eStatus::Play:
		{
			//
			// Timer
			//
			const auto update_result = mTimer.Update();
			const auto current_elapsed_minutes = mTimer.GetElapsedTime<std::chrono::minutes>();

			//
			// Minute View
			//
			{
				const int minute_1 = current_elapsed_minutes % 10;
				const int minute_10 = ( current_elapsed_minutes % 100 ) - minute_1;
				mMinuteComponent->SetMinute( mCore->GetMinute10() - minute_10, mCore->GetMinute1() - minute_1 );
			}

			//
			// Seconds View
			//
			{
				const int seconds_0_to_9 = mTimer.GetElapsedTime<std::chrono::seconds>() % 10;
				mSecondsComponent->Toggle( seconds_0_to_9 );
			}

			//
			// Time Over
			//
			if( !update_result )
			{
				auto next_scene = ptt::EditorScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
				mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
				return;
			}

			//
			// Pause
			//
			if( mKeyboardInputListener.IsRelease( 1 ) )
			{
				mTimer.Pause();
			}
		}
		break;

		case ptt::Timer::eStatus::Pause:
		{
			//
			// Resume
			//
			if( mKeyboardInputListener.IsRelease( 1 ) )
			{
				mTimer.Resume();
			}
		}
		break;
		}

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
	void TimerSceneComponent::SetSecondsComponent( SecondsComponent* const seconds_component )
	{
		R2ASSERT( nullptr != seconds_component, "" );

		mSecondsComponent = seconds_component;
	}

	void TimerSceneComponent::Setup()
	{
		mMinuteComponent->SetMinute( mCore->GetMinute10(), mCore->GetMinute1() );
		mTimer.Set( ( mCore->GetMinute10() + mCore->GetMinute1() ) * 60 );
		mTimer.Start();
	}
}
#include "ptt_TimerSceneComponent.h"

#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2base_Node.h"

#include "ptt_Core.h"
#include "ptt_MinuteComponent.h"
#include "ptt_SecondsComponent.h"

#include "ptt_AlramScene.h"
#include "ptt_EditorScene.h"

namespace ptt
{
	TimerSceneComponent::TimerSceneComponent( r2base::Node& owner_node ) : r2base::Component<TimerSceneComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// 0 : esc
			, 0x20		// 1 : space
		} )
		, mCore()

		, mPauseIndicatorNode( nullptr )
		, mPauseKeyViewNode( nullptr )
		, mResumeKeyViewNode( nullptr )
		, mMinuteComponent( nullptr )
		, mSecondsComponent( nullptr )
		, mTimer()
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}
	TimerSceneComponent::~TimerSceneComponent()
	{
		GetOwnerNode().GetDirector().RemoveInputListener( &mKeyboardInputListener );
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
				const int result_minute = mCore->GetPlayTime().GetMinute() - ( current_elapsed_minutes % 100 );

				const int result_minute_1 = result_minute % 10;
				const int result_minute_10 = ( result_minute - result_minute_1 ) / 10;
				mMinuteComponent->SetMinute( result_minute_10, result_minute_1 );
			}

			//
			// Seconds View
			//
			{
				mSecondsComponent->Toggle( mTimer.GetElapsedTime<std::chrono::seconds>() );
			}

			//
			// Time Over
			//
			if( !update_result )
			{
				auto next_scene = ptt::AlramScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
				mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
				return;
			}

			//
			// Pause
			//
			if( mKeyboardInputListener.IsRelease( 1 ) )
			{
				mTimer.Pause();

				mPauseIndicatorNode->SetVisible( true );
				mPauseKeyViewNode->SetVisible( false );
				mResumeKeyViewNode->SetVisible( true );
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

				mPauseIndicatorNode->SetVisible( false );
				mPauseKeyViewNode->SetVisible( true );
				mResumeKeyViewNode->SetVisible( false );
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
	void TimerSceneComponent::SetPauseIndicatorNode( r2base::Node* const pause_indicator_node )
	{
		R2ASSERT( nullptr != pause_indicator_node, "" );

		mPauseIndicatorNode = pause_indicator_node;
	}
	void TimerSceneComponent::SetPauseKeyViewNode( r2base::Node* const pause_key_view_node )
	{
		R2ASSERT( nullptr != pause_key_view_node, "" );

		mPauseKeyViewNode = pause_key_view_node;
	}
	void TimerSceneComponent::SetResumeKeyViewNode( r2base::Node* const resume_key_view_node )
	{
		R2ASSERT( nullptr != resume_key_view_node, "" );

		mResumeKeyViewNode = resume_key_view_node;
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
		mMinuteComponent->SetMinute( mCore->GetPlayTime().GetMinute10(), mCore->GetPlayTime().GetMinute1() );
		mTimer.Set( mCore->GetPlayTime().GetSeconds() );
		mTimer.Start();

		mPauseIndicatorNode->SetVisible( false );
		mPauseKeyViewNode->SetVisible( true );
		mResumeKeyViewNode->SetVisible( false );
	}
}
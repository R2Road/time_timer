#include "ptt_EditorSceneComponent.h"

#include <iostream>
#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2utility_InputUtil.h"

#include "ptt_Core.h"
#include "ptt_MinuteComponent.h"
#include "ptt_TimerScene.h"

namespace ptt
{
	EditorSceneComponent::EditorSceneComponent( r2base::Node& owner_node ) : r2base::Component<EditorSceneComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// 0 : esc
			, 0x20		// 1 : space
			, 0x41		// 2 : a - left
			, 0x44		// 3 : d - right
			, 0x53		// 4 : s - down
			, 0x57		// 5 : w - up
		} )
		, mCore()
		, mMinuteComponent( nullptr )
		, mIndicatorComponent( nullptr )
		, mCurrentNumberIndicator( eNumberIndicator::M1 )
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}

	void EditorSceneComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();

		//
		// Number Select
		//
		if( mKeyboardInputListener.IsPushed( 2 ) )
		{
			SelectNumber( eNumberIndicator::M10 );
		}
		if( mKeyboardInputListener.IsPushed( 3 ) )
		{
			SelectNumber( eNumberIndicator::M1 );
		}

		//
		// Number Change
		//
		if( mKeyboardInputListener.IsPushed( 5 ) )
		{
			if( eNumberIndicator::M10 == mCurrentNumberIndicator )
			{
				mCore->IncreaseMinute10();
			}
			else //if( eNumberIndicator::M1 == mCurrentNumberIndicator )
			{
				mCore->IncreaseMinute1();
			}

			mMinuteComponent->SetMinute( mCore->GetMinute10(), mCore->GetMinute1() );
		}
		if( mKeyboardInputListener.IsPushed( 4 ) )
		{
			if( eNumberIndicator::M10 == mCurrentNumberIndicator )
			{
				mCore->DecreaseMinute10();
			}
			else //if( eNumberIndicator::M1 == mCurrentNumberIndicator )
			{
				mCore->DecreaseMinute1();
			}

			mMinuteComponent->SetMinute( mCore->GetMinute10(), mCore->GetMinute1() );
		}

		//
		// Start Timer
		//
		if( mKeyboardInputListener.IsRelease( 1 ) )
		{
			if( 0 < mCore->GetMinute() )
			{
				auto next_scene = ptt::TimerScene::Create( mOwnerNode.GetDirector(), std::move( mCore ) );
				mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
				return;
			}
			else
			{
				//
				// beep
				//
				std::cout << '\a';
			}
		}

		//
		// End
		//
		if( mKeyboardInputListener.IsRelease( 0 ) )
		{
			r2utility::ClearCInputBuffer();
			GetOwnerNode().GetDirector().RequestAbort();
			return;
		}

		r2base::iComponent::Update( delta_time );
	}

	void EditorSceneComponent::SetCore( CoreUp&& core )
	{
		R2ASSERT( nullptr == mCore, "" );
		R2ASSERT( nullptr != core, "" );

		mCore = std::move( core );
	}
	void EditorSceneComponent::SetMinuteComponent( MinuteComponent* const minute_component )
	{
		R2ASSERT( nullptr != minute_component, "" );

		mMinuteComponent = minute_component;
	}
	void EditorSceneComponent::SetIndicatorComponent( r2component::TransformComponent* const indicator_component )
	{
		R2ASSERT( nullptr != indicator_component, "" );

		mIndicatorComponent = indicator_component;
	}

	void EditorSceneComponent::Setup()
	{
		mMinuteComponent->SetMinute( mCore->GetMinute10(), mCore->GetMinute1() );
		SelectNumber( ptt::EditorSceneComponent::eNumberIndicator::M1 );
	}

	void EditorSceneComponent::SelectNumber( const eNumberIndicator number_indicator )
	{
		mCurrentNumberIndicator = number_indicator;

		if( eNumberIndicator::M1 == mCurrentNumberIndicator )
		{
			mIndicatorComponent->SetPosition(
				mMinuteComponent->GetOwnerNode().mTransformComponent->GetPosition() + r2::PointInt( 5, 0 )
			);
		}
		else if( eNumberIndicator::M10 == mCurrentNumberIndicator )
		{
			mIndicatorComponent->SetPosition(
				mMinuteComponent->GetOwnerNode().mTransformComponent->GetPosition() - r2::PointInt( 5, 0 )
			);
		}
	}
}
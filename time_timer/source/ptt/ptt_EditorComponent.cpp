#include "ptt_EditorComponent.h"

#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2utility_InputUtil.h"

#include "ptt_Core.h"
#include "ptt_MinuteComponent.h"

namespace ptt
{
	EditorComponent::EditorComponent( r2base::Node& owner_node ) : r2base::Component<EditorComponent>( owner_node )
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

	void EditorComponent::Update( const float delta_time )
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
		// End
		//
		if( mKeyboardInputListener.IsRelease( 0 ) )
		{
			r2utility::ClearCInputBuffer();
			GetOwnerNode().GetDirector().RequestAbort();
		}

		r2base::iComponent::Update( delta_time );
	}

	void EditorComponent::SetCore( CoreUp&& core )
	{
		R2ASSERT( nullptr == mCore, "" );
		R2ASSERT( nullptr != core, "" );

		mCore = std::move( core );
	}
	void EditorComponent::SetMinuteComponent( MinuteComponent* const minute_component )
	{
		R2ASSERT( nullptr != minute_component, "" );

		mMinuteComponent = minute_component;
	}
	void EditorComponent::SetIndicatorComponent( r2component::TransformComponent* const indicator_component )
	{
		R2ASSERT( nullptr != indicator_component, "" );

		mIndicatorComponent = indicator_component;
	}

	void EditorComponent::Setup()
	{
		SelectNumber( ptt::EditorComponent::eNumberIndicator::M1 );
	}

	void EditorComponent::SelectNumber( const eNumberIndicator number_indicator )
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
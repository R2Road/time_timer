#include "ptt_EditorComponent.h"

#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2utility_InputUtil.h"

#include "ptt_Core.h"

namespace ptt
{
	EditorComponent::EditorComponent( r2base::Node& owner_node ) : r2base::Component<EditorComponent>( owner_node )
		, mKeyboardInputListener( {
			  0x1B		// esc
			, 0x20		// space
			, 0x41		// a - left
			, 0x44		// d - right
			, 0x53		// s - down
			, 0x57		// w - up
		} )
		, mCore()
		, mMinuteComponent( nullptr )
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}

	void EditorComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();
		
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
}
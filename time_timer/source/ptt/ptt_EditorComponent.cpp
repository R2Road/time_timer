#include "ptt_EditorComponent.h"

#include <new>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_Node.h"
#include "r2bix/r2utility_InputUtil.h"

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
	{
		GetOwnerNode().GetDirector().AddInputListener( &mKeyboardInputListener );
	}

	void EditorComponent::Update( const float delta_time )
	{
		mKeyboardInputListener.Update();
		
		if( mKeyboardInputListener.IsRelease( 0 ) )
		{
			r2utility::ClearCInputBuffer();
			GetOwnerNode().GetDirector().RequestAbort();
		}

		r2base::iComponent::Update( delta_time );
	}
}
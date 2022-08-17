#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2input_KeyboardInputListener.h"

namespace ptt
{
	class EditorComponent : public r2base::Component<EditorComponent>
	{
	public:
		EditorComponent( r2base::Node& owner_node );

		//
		//
		//
		void Update( const float delta_time ) override;

	private:
		r2input::KeyboardInputListener mKeyboardInputListener;
	};
}
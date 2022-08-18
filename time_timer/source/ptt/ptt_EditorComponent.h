#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2input_KeyboardInputListener.h"

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;

	class MinuteComponent;

	class EditorComponent : public r2base::Component<EditorComponent>
	{
	public:
		EditorComponent( r2base::Node& owner_node );

		//
		//
		//
		void Update( const float delta_time ) override;

		//
		//
		//
		void SetCore( CoreUp&& core );
		void SetMinuteComponent( MinuteComponent* const minute_component );

	private:
		r2input::KeyboardInputListener mKeyboardInputListener;
		CoreUp mCore;
		MinuteComponent* mMinuteComponent;
	};
}
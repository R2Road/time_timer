#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2input_KeyboardInputListener.h"

#include "ptt_Timer.h"

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;

	class MinuteComponent;

	class TimerSceneComponent : public r2base::Component<TimerSceneComponent>
	{
	public:
		TimerSceneComponent( r2base::Node& owner_node );

		//
		//
		//
		void Update( const float delta_time ) override;

		//
		//
		//
		void SetCore( CoreUp&& core );
		void SetMinuteComponent( MinuteComponent* const minute_component );

		//
		//
		//
		void Setup();

	private:
		r2input::KeyboardInputListener mKeyboardInputListener;
		CoreUp mCore;

		MinuteComponent* mMinuteComponent;
		ptt::Timer mTimer;
	};
}
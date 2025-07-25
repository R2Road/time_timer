#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2input_KeyboardInputListener.h"

#include "ptt_Timer.h"

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;

	class MinuteComponent;
	class SecondsComponent;

	class TimerSceneComponent : public r2base::Component<TimerSceneComponent>
	{
	public:
		TimerSceneComponent( r2base::Node& owner_node );
		~TimerSceneComponent();

		//
		//
		//
		void Update( const float delta_time ) override;

		//
		//
		//
		void SetCore( CoreUp&& core );
		void SetPauseIndicatorNode( r2base::Node* const pause_indicator_node );
		void SetPauseKeyViewNode( r2base::Node* const pause_key_view_node );
		void SetResumeKeyViewNode( r2base::Node* const resume_key_view_node );
		void SetMinuteComponent( MinuteComponent* const minute_component );
		void SetSecondsComponent( SecondsComponent* const seconds_component );

		//
		//
		//
		void Setup();

	private:
		r2input::KeyboardInputListener mKeyboardInputListener;
		CoreUp mCore;

		r2base::Node* mPauseIndicatorNode;
		r2base::Node* mPauseKeyViewNode;
		r2base::Node* mResumeKeyViewNode;
		MinuteComponent* mMinuteComponent;
		SecondsComponent* mSecondsComponent;
		ptt::Timer mTimer;
	};
}
#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2input_KeyboardInputListener.h"

#include "ptt_Timer.h"

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;

	class AlramSceneComponent : public r2base::Component<AlramSceneComponent>
	{
	public:
		AlramSceneComponent( r2base::Node& owner_node );
		~AlramSceneComponent();

		//
		//
		//
		void Update( const float delta_time ) override;

		//
		//
		//
		void SetCore( CoreUp&& core );

	private:
		r2input::KeyboardInputListener mKeyboardInputListener;
		CoreUp mCore;

		ptt::Timer mTimer;
	};
}
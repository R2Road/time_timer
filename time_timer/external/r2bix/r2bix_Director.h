#pragma once

#include <memory>

#include "r2bix_director_ScreenBufferManager.h"
#include "r2input_KeyboardInputCollector.h"
#include "r2node_SceneNode.h"
#include "r2/r2_SizeInt.h"

#include "r2bix_director_Config.h"
#include "r2bix_director_Scheduler.h"

namespace r2bix
{
	class Director
	{
	public:
		Director( const r2bix_director::Config& director_config );

		void Setup( r2node::SceneNodeUp node );

		void Run();
	private:
		void onUpdate( const float delta_time );
		void onRender();

	public:
		//
		//
		//
		r2::SizeInt GetScreenBufferSize() const { return mScreenBufferSIze; }

		//
		//
		//
		void RequestAbort() { mbAbort = true; }
		void ClearScreen();
		void Write2BackBuffer( const r2render::Texture* const texture );

		//
		// Input
		//
		void AddInputListener( r2input::KeyboardInputListener* const keyboard_input_listener );
		void RemoveInputListener( r2input::KeyboardInputListener* const keyboard_input_listener );

	private:
		r2bix_director::ScreenBufferManager mScreenBufferManager;
		r2bix_director::Scheduler mScheduler;
		bool mbAbort;
		r2::SizeInt mScreenBufferSIze;

		r2input::KeyboardInputCollector mKeyboardInputCollector;

		r2node::SceneNodeUp mCurrentSceneNode;
		r2node::SceneNodeUp mNextSceneNode;
	};
}
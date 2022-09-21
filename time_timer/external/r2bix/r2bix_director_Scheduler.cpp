#include "r2bix_director_Scheduler.h"

#include <algorithm>
#include <chrono>
#include <thread>

#include "r2/r2_FPSTimer.h"
#include "r2bix_director_Config.h"

namespace r2bix_director
{
	const std::function<void()> MakeProcessor( const Config& config, const std::function<void( float )> scene_update_func, const std::function<void()> scene_render_func )
	{
		switch( config.ScheduleType )
		{
		default:
		case Config::eScheduleType::Infinite:
			return [mUpdateTimer = r2::FPSTimer( config.UpdateFramePerSeconds ), mRenderTimer = r2::FPSTimer( config.UpdateFramePerSeconds ), scene_update_func, scene_render_func]() mutable
			{
				if( mUpdateTimer.Update() )
				{
					scene_update_func( mUpdateTimer.GetElapsedTime() );
				}

				if( mRenderTimer.Update() )
				{
					scene_render_func();
				}
			};

		case Config::eScheduleType::Sleep:
		{
			const auto start_time = std::chrono::system_clock::now();

			const auto limit_ms_4_update = std::chrono::milliseconds( 1000 / config.UpdateFramePerSeconds );
			auto next_update_time = limit_ms_4_update;
			auto last_update_time = std::chrono::milliseconds();

			const auto limit_ms_4_render = std::chrono::milliseconds( 1000 / config.RenderFramePerSeconds );
			auto next_render_time = limit_ms_4_render;

			auto play_time = std::chrono::milliseconds();

			return[
				start_time
				, play_time

				, limit_ms_4_update
				, next_update_time
				, last_update_time

				, limit_ms_4_render
				, next_render_time

				, scene_update_func
				, scene_render_func
			]() mutable
			{
				//
				// 가까운 Update Time 을 찾는다.
				//
				const auto required_sleep_time = std::min( next_update_time - play_time, next_render_time - play_time );

				//
				// Sleep
				//
				if( 0 < required_sleep_time.count() )
				{
					std::this_thread::sleep_for( required_sleep_time );
				}

				//
				// Play Time Update
				//
				play_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::system_clock::now() - start_time );

				//
				// Update
				//
				if( next_update_time < play_time )
				{
					scene_update_func( 0.001f * ( play_time - last_update_time ).count() );

					last_update_time = play_time;
					next_update_time = play_time + limit_ms_4_update;
				}

				//
				// Render
				//
				if( next_render_time < play_time )
				{
					scene_render_func();

					next_render_time = play_time + limit_ms_4_render;
				}
			};
		}
		}
	}

	Scheduler::Scheduler( const Config& config, const std::function<void( float )> scene_update_func, const std::function<void()> scene_render_func ) :
		mProcessor( MakeProcessor( config, scene_update_func, scene_render_func ) )
	{}

	void Scheduler::Do()
	{
		mProcessor();
	}
}
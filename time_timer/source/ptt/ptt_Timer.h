#pragma once

#include <chrono>

namespace ptt
{
	class Timer
	{
	public:
		Timer();

		//
		//
		//
		bool IsAlive() const
		{
			return mbAlive;
		}

		//
		//
		//
		int64_t GetCurrentTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mCurrentTime.time_since_epoch() ).count();
		}
		template<typename durationT>
		int64_t GetCurrentTime() const
		{
			return std::chrono::duration_cast<durationT>( mCurrentTime.time_since_epoch() ).count();
		}

		int64_t GetLastTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mLastTime.time_since_epoch() ).count();
		}
		template<typename durationT>
		int64_t GetLastTime() const
		{
			return std::chrono::duration_cast<durationT>( mLastTime.time_since_epoch() ).count();
		}

		int64_t GetElapsedTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mElapsedDuration ).count();
		}
		template<typename durationT>
		int64_t GetElapsedTime() const
		{
			return std::chrono::duration_cast<durationT>( mElapsedDuration ).count();
		}

		//
		//
		//
		void Start();
		void Update();
		void Stop();

	private:
		bool mbAlive;
		std::chrono::steady_clock::time_point mCurrentTime;
		std::chrono::steady_clock::time_point mLastTime;
		std::chrono::steady_clock::duration mElapsedDuration;
	};
}
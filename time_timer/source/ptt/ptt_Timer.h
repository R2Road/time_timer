#pragma once

#include <chrono>

namespace ptt
{
	class Timer
	{
	public:
		Timer();

		int64_t GetCurrentTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mCurrentTime.time_since_epoch() ).count();
		}
		int64_t GetLastTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mLastTime.time_since_epoch() ).count();
		}
		int64_t GetElapsedTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mElapsedDuration ).count();
		}

		void Start();
		void Update();

	private:
		std::chrono::steady_clock::time_point mCurrentTime;
		std::chrono::steady_clock::time_point mLastTime;
		std::chrono::steady_clock::duration mElapsedDuration;
	};
}
#pragma once

#include <chrono>

namespace ptt
{
	class Timer
	{
	public:
		enum class eStatus
		{
			Stop,
			Play,
			Pause,
		};

		Timer();
		Timer( const int seconds );

		//
		//
		//
		eStatus GetStatus() const
		{
			return mStatus;
		}
		bool IsAlive() const
		{
			return mStatus != eStatus::Stop;
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

		int64_t GetRequiredTime() const
		{
			return std::chrono::duration_cast<std::chrono::seconds>( mRequiredDuration ).count();
		}
		template<typename durationT>
		int64_t GetRequiredTime() const
		{
			return std::chrono::duration_cast<durationT>( mRequiredDuration ).count();
		}

		//
		//
		//
		void Set( const int seconds );
		void Start();
		bool Update();
		void Stop();
		void Pause();
		void Resume();

	private:
		void updateTime();

	private:
		eStatus mStatus;
		std::chrono::steady_clock::time_point mCurrentTime;
		std::chrono::steady_clock::time_point mLastTime;
		std::chrono::steady_clock::duration mElapsedDuration;
		std::chrono::steady_clock::duration mRequiredDuration;
	};
}
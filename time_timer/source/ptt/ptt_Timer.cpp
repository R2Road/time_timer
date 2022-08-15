#include "ptt_Timer.h"

namespace ptt
{
	Timer::Timer() :
		mCurrentTime( std::chrono::milliseconds( 0 ) )
		, mLastTime( std::chrono::milliseconds( 0 ) )
	{}

	void Timer::Start()
	{
		mLastTime = mCurrentTime = std::chrono::high_resolution_clock::now();
	}
}
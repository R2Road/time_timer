#include "ptt_Timer.h"

namespace ptt
{
	Timer::Timer() :
		mCurrentTime( std::chrono::milliseconds( 0 ) )
		, mLastTime( std::chrono::milliseconds( 0 ) )
		, mElapsedDuration( std::chrono::milliseconds( 0 ) )
	{}

	void Timer::Start()
	{
		mLastTime = mCurrentTime = std::chrono::high_resolution_clock::now();
		mElapsedDuration = std::chrono::duration_cast<std::chrono::milliseconds>( mCurrentTime - mLastTime );
	}
	void Timer::Update()
	{
		// # Summury - by R 2022.08.16 01:53
		// > Template Getter 에 std::chrono::nanoseconds 를 인자로 주면 예외가 터지는 경우가 있다.
		// > "mCurrentTime = std::chrono::high_resolution_clock::now();" 이 구문을 주석 처리하면 문제가 없다.
		// > 왜지?

		mLastTime = mCurrentTime;
		mCurrentTime = std::chrono::high_resolution_clock::now();

		mElapsedDuration += std::chrono::duration_cast<std::chrono::milliseconds>( mCurrentTime - mLastTime );
	}
}
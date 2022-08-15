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
		// > Template Getter �� std::chrono::nanoseconds �� ���ڷ� �ָ� ���ܰ� ������ ��찡 �ִ�.
		// > "mCurrentTime = std::chrono::high_resolution_clock::now();" �� ������ �ּ� ó���ϸ� ������ ����.
		// > ����?

		mLastTime = mCurrentTime;
		mCurrentTime = std::chrono::high_resolution_clock::now();

		mElapsedDuration += std::chrono::duration_cast<std::chrono::milliseconds>( mCurrentTime - mLastTime );
	}
}
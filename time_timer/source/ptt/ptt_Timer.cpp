#include "ptt_Timer.h"

namespace ptt
{
	Timer::Timer() :
		mStatus( eStatus::Stop )
		, mCurrentTime( std::chrono::nanoseconds( 0 ) )
		, mLastTime( std::chrono::nanoseconds( 0 ) )
		, mElapsedDuration( std::chrono::nanoseconds( 0 ) )
	{}

	void Timer::Start()
	{
		mStatus = eStatus::Play;
		mLastTime = mCurrentTime = std::chrono::high_resolution_clock::now();
		mElapsedDuration = std::chrono::duration_cast<std::chrono::nanoseconds>( mCurrentTime - mLastTime );
	}
	void Timer::Update()
	{
		// # Summury - by R 2022.08.16 01:53
		// > Template Getter �� std::chrono::nanoseconds �� ���ڷ� �ָ� ���ܰ� ������ ��찡 �ִ�.
		// > "mCurrentTime = std::chrono::high_resolution_clock::now();" �� ������ �ּ� ó���ϸ� ������ ����.
		// > ����?

		if( eStatus::Play != mStatus )
		{
			return;
		}

		mLastTime = mCurrentTime;
		mCurrentTime = std::chrono::high_resolution_clock::now();

		mElapsedDuration += std::chrono::duration_cast<std::chrono::nanoseconds>( mCurrentTime - mLastTime );
	}
	void Timer::Stop()
	{
		Update();
		mStatus = eStatus::Stop;
	}
}
#include "ptt_Timer.h"

namespace ptt
{
	Timer::Timer() :
		mStatus( eStatus::Stop )
		, mCurrentTime( std::chrono::nanoseconds( 0 ) )
		, mLastTime( std::chrono::nanoseconds( 0 ) )
		, mElapsedDuration( std::chrono::nanoseconds( 0 ) )
		, mRequiredDuration( std::chrono::nanoseconds( 0 ) )
	{}

	Timer::Timer( const int seconds ) :
		mStatus( eStatus::Stop )
		, mCurrentTime( std::chrono::nanoseconds( 0 ) )
		, mLastTime( std::chrono::nanoseconds( 0 ) )
		, mElapsedDuration( std::chrono::nanoseconds( 0 ) )
		, mRequiredDuration( std::chrono::nanoseconds( 0 ) )
	{
		Set( seconds );
	}

	void Timer::Set( const int seconds )
	{
		mRequiredDuration = std::chrono::milliseconds( seconds * 1000 );
	}

	void Timer::Start()
	{
		mStatus = eStatus::Play;
		mLastTime = mCurrentTime = std::chrono::high_resolution_clock::now();
		mElapsedDuration = std::chrono::nanoseconds( 0 );
	}
	void Timer::Update()
	{
		updateTime();
	}
	void Timer::Stop()
	{
		updateTime();
		mStatus = eStatus::Stop;
	}

	void Timer::Pause()
	{
		if( eStatus::Play != mStatus )
		{
			return;
		}

		updateTime();
		mStatus = eStatus::Pause;
	}

	void Timer::Resume()
	{
		if( eStatus::Pause != mStatus )
		{
			return;
		}

		mStatus = eStatus::Play;

		//
		// 시간 측정 초기화
		//
		mLastTime = mCurrentTime = std::chrono::high_resolution_clock::now();
	}

	void Timer::updateTime()
	{
		// # Summury - by R 2022.08.16 01:53
		// > Template Getter 에 std::chrono::nanoseconds 를 인자로 주면 예외가 터지는 경우가 있다.
		// > "mCurrentTime = std::chrono::high_resolution_clock::now();" 이 구문을 주석 처리하면 문제가 없다.
		// > 왜지?

		if( eStatus::Play != mStatus )
		{
			return;
		}

		mLastTime = mCurrentTime;
		mCurrentTime = std::chrono::high_resolution_clock::now();

		mElapsedDuration += std::chrono::duration_cast<std::chrono::nanoseconds>( mCurrentTime - mLastTime );
	}
}
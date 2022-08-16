#include "test_ptt_timer.h"

#include <conio.h>

#include "r2/r2_FPSTimer.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_Timer.h"

namespace test_ptt_timer
{
	r2cm::iItem::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Generate";
		};
	}
	r2cm::iItem::DoFunctionT Generate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Timer timer );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( timer.IsAlive() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, timer.GetCurrentTime() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, timer.GetLastTime() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, timer.GetElapsedTime() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, timer.GetRequiredTime() );
			}
			
			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Set::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Set";
		};
	}
	r2cm::iItem::DoFunctionT Set::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int seconds = 123456 );
				DECLARATION_MAIN( ptt::Timer timer );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Set( seconds ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( seconds, timer.GetRequiredTime() );
				OUTPUT_VALUE( timer.GetRequiredTime() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int seconds = 654321 );
				DECLARATION_MAIN( ptt::Timer timer( seconds ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( seconds, timer.GetRequiredTime() );
				OUTPUT_VALUE( timer.GetRequiredTime() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Start::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Start";
		};
	}
	r2cm::iItem::DoFunctionT Start::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Timer timer );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( timer.Start() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );
				EXPECT_TRUE( timer.IsAlive() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( timer.GetCurrentTime(), timer.GetLastTime() );
				OUTPUT_VALUE( timer.GetCurrentTime() );
				OUTPUT_VALUE( timer.GetLastTime() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0ll, timer.GetElapsedTime() );
				OUTPUT_VALUE( timer.GetElapsedTime() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Demo" << r2cm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				do
				{
					if( ft.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						PROCESS_MAIN( timer.Start() );
						OUTPUT_VALUE( timer.GetCurrentTime() );
						OUTPUT_VALUE( timer.GetLastTime() );
						OUTPUT_VALUE( timer.GetElapsedTime() );
					}

					if( _kbhit() )
					{
						_getch();
						break;
					}

				} while( true );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Update::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Update";
		};
	}
	r2cm::iItem::DoFunctionT Update::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Timer timer( 3 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( timer.Start() );
				OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( timer.Update() );
				EXPECT_NE( timer.GetCurrentTime<std::chrono::microseconds>(), timer.GetLastTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Demo" << r2cm::linefeed;
				std::cout << r2cm::tab << "[1] Timer::Start" << r2cm::linefeed;
				std::cout << r2cm::tab << "[ESC] End" << r2cm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					if( ft.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						OUTPUT_VALUE( timer.Update() );
						OUTPUT_VALUE( static_cast<int>( timer.GetStatus() ) );
						OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
					}

					if( _kbhit() )
					{
						input = _getch();

						if( '1' == input )
						{
							timer.Start();
						}
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Stop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Stop";
		};
	}
	r2cm::iItem::DoFunctionT Stop::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Timer timer( 10000 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( timer.Start() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );
				EXPECT_TRUE( timer.IsAlive() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Stop() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );
				EXPECT_FALSE( timer.IsAlive() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( timer.Start() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Demo" << r2cm::linefeed;
				std::cout << r2cm::tab << "[Any Key] Timer::Stop" << r2cm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				do
				{
					if( ft.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						OUTPUT_VALUE( timer.Update() );
						OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
					}

					if( _kbhit() )
					{
						PROCESS_MAIN( timer.Stop() );

						_getch();
						break;
					}

				} while( true );
			}
			
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Stop 을 호출한 이후에는 Update 를 호출해도 시간이 갱신되지 않는다." << r2cm::linefeed2;

				DECLARATION_MAIN( auto et = timer.GetElapsedTime<std::chrono::microseconds>() );
				PROCESS_MAIN( timer.Update() );
				EXPECT_EQ( et, timer.GetElapsedTime<std::chrono::microseconds>() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Pause";
		};
	}
	r2cm::iItem::DoFunctionT Pause::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Timer timer );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Pause() );
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Resume() );
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( timer.Start() );
				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Resume() );
				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Pause() );
				EXPECT_EQ( ptt::Timer::eStatus::Pause, timer.GetStatus() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( timer.Resume() );
				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Demo" << r2cm::linefeed;
				std::cout << r2cm::tab << "[1] Timer::Pause" << r2cm::linefeed;
				std::cout << r2cm::tab << "[2] Timer::Resume" << r2cm::linefeed;
				std::cout << r2cm::tab << "[ESC] End" << r2cm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					if( ft.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						PROCESS_MAIN( timer.Update() );
						OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( static_cast<int>( timer.GetStatus() ) );
					}

					if( _kbhit() )
					{
						input = _getch();
						switch( input )
						{
						case '1':
							timer.Pause();
							break;
						case '2':
							timer.Resume();
							break;
						}
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
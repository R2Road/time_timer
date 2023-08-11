#include "test_ptt_timer.h"

#include <conio.h>

#include "r2/r2_FPSTimer.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_Timer.h"

namespace test_ptt_timer
{
	std::ostream& operator<<( std::ostream& o, ptt::Timer::eStatus status )
	{
		o << static_cast<int>( status );
		return o;
	}

	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "기본 생성자" );

				LF();

				DECLARATION_MAIN( ptt::Timer timer );

				LF();

				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );
				EXPECT_FALSE( timer.IsAlive() );

				LF();

				EXPECT_EQ( 0, timer.GetCurrentTime() );
				EXPECT_EQ( 0, timer.GetLastTime() );
				EXPECT_EQ( 0, timer.GetElapsedTime() );
				EXPECT_EQ( 0, timer.GetRequiredTime() );
			}
			
			LS();

			{
				OUTPUT_SUBJECT( "기본 생성자" );

				LF();

				DECLARATION_MAIN( ptt::Timer timer( 12345 ) );

				LF();

				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );
				EXPECT_FALSE( timer.IsAlive() );

				LF();

				EXPECT_EQ( 0, timer.GetCurrentTime() );
				EXPECT_EQ( 0, timer.GetLastTime() );
				EXPECT_EQ( 0, timer.GetElapsedTime() );
				EXPECT_EQ( 12345, timer.GetRequiredTime() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Set::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Set";
		};
	}
	r2tm::DoFunctionT Set::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Timer timer );
			EXPECT_EQ( 0, timer.GetRequiredTime() );

			LS();

			{
				PROCESS_MAIN( timer.Set( 123456 ) );

				LF();

				EXPECT_EQ( 123456, timer.GetRequiredTime() );
			}

			LS();

			{
				PROCESS_MAIN( timer.Set( 654321 ) );

				LF();

				EXPECT_EQ( 654321, timer.GetRequiredTime() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Start::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Start";
		};
	}
	r2tm::DoFunctionT Start::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Timer timer );

			LS();

			{
				PROCESS_MAIN( timer.Start() );

				LF();

				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );
				EXPECT_TRUE( timer.IsAlive() );

				LF();

				EXPECT_EQ( timer.GetCurrentTime(), timer.GetLastTime() );
				OUTPUT_VALUE( timer.GetCurrentTime() );
				OUTPUT_VALUE( timer.GetLastTime() );

				LF();

				EXPECT_EQ( 0ll, timer.GetElapsedTime() );
			}

			LS();

			OUTPUT_NOTE( "Demo" );
			OUTPUT_COMMENT( "[ESC] End" );

			LS();

			{
				DECLARATION_MAIN( r2::FPSTimer ft( 30 ) );

				LF();

				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				do
				{
					if( ft.Update() )
					{
						r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						PROCESS_MAIN( timer.Start() );
						OUTPUT_VALUE( timer.GetCurrentTime() );
						OUTPUT_VALUE( timer.GetLastTime() );
						OUTPUT_VALUE( timer.GetElapsedTime() );
					}

					if( _kbhit() )
					{
						_getch(); // 입력키를 pop 해서 이후 키 처리에 문제가 없게 한다.
						break;
					}

				} while( true );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT Update::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Update";
		};
	}
	r2tm::DoFunctionT Update::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Timer timer( 3 ) );

			LS();

			{
				PROCESS_MAIN( timer.Start() );
				OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
			}

			LS();

			{
				PROCESS_MAIN( timer.Update() );
				EXPECT_NE( timer.GetCurrentTime<std::chrono::microseconds>(), timer.GetLastTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
				OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Demo" << r2tm::linefeed;
				std::cout << r2tm::tab << "[1] Timer::Start" << r2tm::linefeed;
				std::cout << r2tm::tab << "[ESC] End" << r2tm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					if( ft.Update() )
					{
						r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

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

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Stop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Stop";
		};
	}
	r2tm::DoFunctionT Stop::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Timer timer( 10000 ) );

			LS();

			{
				PROCESS_MAIN( timer.Start() );

				LF();

				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );
				EXPECT_TRUE( timer.IsAlive() );

				LF();

				PROCESS_MAIN( timer.Stop() );

				LF();

				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );
				EXPECT_FALSE( timer.IsAlive() );
			}

			LS();

			{
				PROCESS_MAIN( timer.Start() );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Demo" << r2tm::linefeed;
				std::cout << r2tm::tab << "[Any Key] Timer::Stop" << r2tm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				do
				{
					if( ft.Update() )
					{
						r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

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
			
			LS();

			{
				std::cout << r2tm::tab << "+ Stop 을 호출한 이후에는 Update 를 호출해도 시간이 갱신되지 않는다." << r2tm::linefeed2;

				DECLARATION_MAIN( auto et = timer.GetElapsedTime<std::chrono::microseconds>() );
				PROCESS_MAIN( timer.Update() );
				EXPECT_EQ( et, timer.GetElapsedTime<std::chrono::microseconds>() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Timer : Pause";
		};
	}
	r2tm::DoFunctionT Pause::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Timer timer( 10000 ) );

			LS();

			{
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );

				LF();

				PROCESS_MAIN( timer.Pause() );
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );

				LF();

				PROCESS_MAIN( timer.Resume() );
				EXPECT_EQ( ptt::Timer::eStatus::Stop, timer.GetStatus() );
			}

			LS();

			{
				PROCESS_MAIN( timer.Start() );
				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );

				LF();

				PROCESS_MAIN( timer.Resume() );
				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );

				LF();

				PROCESS_MAIN( timer.Pause() );
				EXPECT_EQ( ptt::Timer::eStatus::Pause, timer.GetStatus() );

				LF();

				PROCESS_MAIN( timer.Resume() );
				EXPECT_EQ( ptt::Timer::eStatus::Play, timer.GetStatus() );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Demo" << r2tm::linefeed;
				std::cout << r2tm::tab << "[1] Timer::Pause" << r2tm::linefeed;
				std::cout << r2tm::tab << "[2] Timer::Resume" << r2tm::linefeed;
				std::cout << r2tm::tab << "[ESC] End" << r2tm::linefeed2;

				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					if( ft.Update() )
					{
						r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						OUTPUT_VALUE( timer.Update() );
						OUTPUT_VALUE( static_cast<int>( timer.GetStatus() ) );
						OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
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

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
#include "test_ptt_demo.h"

#include <algorithm>
#include <conio.h>

#include "r2/r2_FPSTimer.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_Timer.h"

namespace test_ptt_demo
{
	r2tm::TitleFunctionT Play::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo";
		};
	}
	r2tm::DoFunctionT Play::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( ptt::Timer timer );
			DECLARATION_MAIN( int required_10_min = 0 );
			DECLARATION_MAIN( int required_1_min = 1 );
			PROCESS_MAIN( timer.Set( ( required_10_min + required_1_min ) * 60 ) );

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Demo" << r2tm::linefeed2;
				std::cout << r2tm::tab << "[1] Start/Stop" << r2tm::linefeed;
				std::cout << r2tm::tab << "[2] Pause/Resume" << r2tm::linefeed;
				std::cout << r2tm::tab << "[Q/A] 10 Min Up/Down" << r2tm::linefeed;
				std::cout << r2tm::tab << "[W/S]  1 Min Up/Down" << r2tm::linefeed;
				std::cout << r2tm::tab << "[ESC] End" << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				ptt::Timer::eStatus last_status = timer.GetStatus();
				do
				{
					if( ft.Update() )
					{
						r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						std::cout << "Required Time : " << required_10_min << required_1_min << r2tm::linefeed2;

						OUTPUT_VALUE( timer.Update() );
						OUTPUT_VALUE( static_cast<int>( timer.GetStatus() ) );
						OUTPUT_VALUE( timer.GetRequiredTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetElapsedTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetCurrentTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetLastTime<std::chrono::microseconds>() );
						OUTPUT_VALUE( timer.GetLastTime<std::chrono::seconds>() );

						if( ptt::Timer::eStatus::Play == last_status && ptt::Timer::eStatus::Stop == timer.GetStatus() )
						{
							std::cout << (char)7;
						}
						last_status = timer.GetStatus();
					}

					if( _kbhit() )
					{
						input = _getch();
						switch( input )
						{
						case '1':
							( ptt::Timer::eStatus::Stop == timer.GetStatus() ? timer.Start() : timer.Stop() );
							break;
						case '2':
							( ptt::Timer::eStatus::Pause == timer.GetStatus() ? timer.Resume() : timer.Pause() );
							break;

						case 'q':
							required_10_min = std::min( 9, required_10_min + 1 );
							timer.Set( ( required_10_min + required_1_min ) * 60 );
							break;
						case 'a':
							required_10_min = std::max( 0, required_10_min - 1 );
							timer.Set( ( required_10_min + required_1_min ) * 60 );
							break;

						case 'w':
							required_1_min = std::min( 9, required_1_min + 1 );
							timer.Set( ( required_10_min + required_1_min ) * 60 );
							break;
						case 's':
							required_1_min = std::max( 0, required_1_min - 1 );
							timer.Set( ( required_10_min + required_1_min ) * 60 );
							break;
						}
					}

				} while( 27 != input );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
#include "test_ptt_demo.h"

#include <algorithm>
#include <conio.h>

#include "r2/r2_FPSTimer.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_Timer.h"

namespace test_ptt_demo
{
	r2cm::iItem::TitleFunctionT Play::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo";
		};
	}
	r2cm::iItem::DoFunctionT Play::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Timer timer );
			DECLARATION_MAIN( int required_10_min = 0 );
			DECLARATION_MAIN( int required_1_min = 1 );
			PROCESS_MAIN( timer.Set( ( required_10_min + required_1_min ) * 60 ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Demo" << r2cm::linefeed2;
				std::cout << r2cm::tab << "[1] Start/Stop" << r2cm::linefeed;
				std::cout << r2cm::tab << "[2] Pause/Resume" << r2cm::linefeed;
				std::cout << r2cm::tab << "[Q/A] 10 Min Up/Down" << r2cm::linefeed;
				std::cout << r2cm::tab << "[W/S]  1 Min Up/Down" << r2cm::linefeed;
				std::cout << r2cm::tab << "[ESC] End" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				r2::FPSTimer ft( 30 );
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					if( ft.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						std::cout << "Required Time : " << required_10_min << required_1_min << r2cm::linefeed2;

						OUTPUT_VALUE( timer.Update() );
						OUTPUT_VALUE( static_cast<int>( timer.GetStatus() ) );
						OUTPUT_VALUE( timer.GetRequiredTime<std::chrono::microseconds>() );
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

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
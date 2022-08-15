#include "test_ptt_timer.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

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
				EXPECT_EQ( timer.GetCurrentTime(), timer.GetLastTime() );
				OUTPUT_VALUE( timer.GetCurrentTime() );
				OUTPUT_VALUE( timer.GetLastTime() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
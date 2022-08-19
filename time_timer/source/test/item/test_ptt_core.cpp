#include "test_ptt_core.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "ptt/ptt_Core.h"

namespace test_ptt_core
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::CoreUp core = ptt::Core::Create() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( core->IncreaseMinute10() );
				EXPECT_EQ( 1, core->GetMinute10() );
				PROCESS_MAIN( core->IncreaseMinute10() );
				EXPECT_EQ( 2, core->GetMinute10() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( core->IncreaseMinute1() );
				EXPECT_EQ( 1, core->GetMinute1() );
				PROCESS_MAIN( core->IncreaseMinute1() );
				EXPECT_EQ( 2, core->GetMinute1() );
				PROCESS_MAIN( core->IncreaseMinute1() );
				EXPECT_EQ( 3, core->GetMinute1() );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 23, core->GetMinute() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 23 * 60, core->GetSeconds() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( core->DecreaseMinute10() );
				EXPECT_EQ( 1, core->GetMinute10() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( core->DecreaseMinute1() );
				EXPECT_EQ( 2, core->GetMinute1() );
				PROCESS_MAIN( core->DecreaseMinute1() );
				EXPECT_EQ( 1, core->GetMinute1() );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 11, core->GetMinute() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 11 * 60, core->GetSeconds() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
#include "test_ptt_core.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "ptt/ptt_Core.h"

namespace test_ptt_core
{
	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Not Working : private Constructor" );

				std::cout << r2cm::linefeed;

				OUTPUT_CODE( ptt::Core core );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( ptt::CoreUp core = ptt::Core::Create() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : Basic";
		};
	}
	r2cm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::CoreUp core = ptt::Core::Create() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( core->GetRequiredTime().IncreaseMinute10() );
				EXPECT_EQ( 1, core->GetRequiredTime().GetMinute10() );
				PROCESS_MAIN( core->GetRequiredTime().IncreaseMinute10() );
				EXPECT_EQ( 2, core->GetRequiredTime().GetMinute10() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( core->GetRequiredTime().IncreaseMinute1() );
				EXPECT_EQ( 1, core->GetRequiredTime().GetMinute1() );
				PROCESS_MAIN( core->GetRequiredTime().IncreaseMinute1() );
				EXPECT_EQ( 2, core->GetRequiredTime().GetMinute1() );
				PROCESS_MAIN( core->GetRequiredTime().IncreaseMinute1() );
				EXPECT_EQ( 3, core->GetRequiredTime().GetMinute1() );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 23, core->GetRequiredTime().GetMinute() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 23 * 60, core->GetRequiredTime().GetSeconds() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( core->GetRequiredTime().DecreaseMinute10() );
				EXPECT_EQ( 1, core->GetRequiredTime().GetMinute10() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( core->GetRequiredTime().DecreaseMinute1() );
				EXPECT_EQ( 2, core->GetRequiredTime().GetMinute1() );
				PROCESS_MAIN( core->GetRequiredTime().DecreaseMinute1() );
				EXPECT_EQ( 1, core->GetRequiredTime().GetMinute1() );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 11, core->GetRequiredTime().GetMinute() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 11 * 60, core->GetRequiredTime().GetSeconds() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}
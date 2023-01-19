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

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, core->GetRequiredTime().GetMinute() );
				EXPECT_EQ( 0, core->GetRequiredTime().GetMinute10() );
				EXPECT_EQ( 0, core->GetRequiredTime().GetMinute1() );
				EXPECT_EQ( 0, core->GetRequiredTime().GetSeconds() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT RequiredTime::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : RequiredTime";
		};
	}
	r2cm::DoFunctionT RequiredTime::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( ptt::Core::RequiredTime r );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( r.IncreaseMinute10() );
				EXPECT_EQ( 1, r.GetMinute10() );
				PROCESS_MAIN( r.IncreaseMinute10() );
				EXPECT_EQ( 2, r.GetMinute10() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( r.IncreaseMinute1() );
				EXPECT_EQ( 1, r.GetMinute1() );
				PROCESS_MAIN( r.IncreaseMinute1() );
				EXPECT_EQ( 2, r.GetMinute1() );
				PROCESS_MAIN( r.IncreaseMinute1() );
				EXPECT_EQ( 3, r.GetMinute1() );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 23, r.GetMinute() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 23 * 60, r.GetSeconds() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( r.DecreaseMinute10() );
				EXPECT_EQ( 1, r.GetMinute10() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( r.DecreaseMinute1() );
				EXPECT_EQ( 2, r.GetMinute1() );
				PROCESS_MAIN( r.DecreaseMinute1() );
				EXPECT_EQ( 1, r.GetMinute1() );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 11, r.GetMinute() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 11 * 60, r.GetSeconds() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}
#include "test_ptt_core.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

#include "ptt/ptt_Core.h"

namespace test_ptt_core
{
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "Not Working : private Constructor" );

				LF();

				OUTPUT_CODE( ptt::Core core );
			}

			LS();

			{
				DECLARATION_MAIN( ptt::CoreUp core = ptt::Core::Create() );

				LF();

				EXPECT_EQ( 0, core->GetRequiredTime().GetMinute() );
				EXPECT_EQ( 0, core->GetRequiredTime().GetMinute10() );
				EXPECT_EQ( 0, core->GetRequiredTime().GetMinute1() );
				EXPECT_EQ( 0, core->GetRequiredTime().GetSeconds() );

				LF();

				EXPECT_EQ( 0, core->GetPlayTime().GetMinute() );
				EXPECT_EQ( 0, core->GetPlayTime().GetMinute10() );
				EXPECT_EQ( 0, core->GetPlayTime().GetMinute1() );
				EXPECT_EQ( 0, core->GetPlayTime().GetSeconds() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT RequiredTime::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : RequiredTime";
		};
	}
	r2tm::DoFunctionT RequiredTime::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Core::RequiredTime r );

			LS();

			{
				PROCESS_MAIN( r.IncreaseMinute10() );
				EXPECT_EQ( 1, r.GetMinute10() );
				PROCESS_MAIN( r.IncreaseMinute10() );
				EXPECT_EQ( 2, r.GetMinute10() );

				LF();

				PROCESS_MAIN( r.IncreaseMinute1() );
				EXPECT_EQ( 1, r.GetMinute1() );
				PROCESS_MAIN( r.IncreaseMinute1() );
				EXPECT_EQ( 2, r.GetMinute1() );
				PROCESS_MAIN( r.IncreaseMinute1() );
				EXPECT_EQ( 3, r.GetMinute1() );
			}

			LS();

			{
				EXPECT_EQ( 23, r.GetMinute() );

				LF();

				EXPECT_EQ( 23 * 60, r.GetSeconds() );
			}

			LS();

			{
				PROCESS_MAIN( r.DecreaseMinute10() );
				EXPECT_EQ( 1, r.GetMinute10() );

				LF();

				PROCESS_MAIN( r.DecreaseMinute1() );
				EXPECT_EQ( 2, r.GetMinute1() );
				PROCESS_MAIN( r.DecreaseMinute1() );
				EXPECT_EQ( 1, r.GetMinute1() );
			}

			LS();

			{
				EXPECT_EQ( 11, r.GetMinute() );

				LF();

				EXPECT_EQ( 11 * 60, r.GetSeconds() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PlayTime::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Core : PlayTime";
		};
	}
	r2tm::DoFunctionT PlayTime::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( ptt::Core::PlayTime p );

			LS();

			{
				PROCESS_MAIN( p.SetMinute( 1, 2 ) );
				EXPECT_EQ( 12, p.GetMinute() );
				EXPECT_EQ( 1, p.GetMinute10() );
				EXPECT_EQ( 2, p.GetMinute1() );
				EXPECT_EQ( 12 * 60, p.GetSeconds() );

				LF();

				PROCESS_MAIN( p.SetMinute( 2, 4 ) );
				EXPECT_EQ( 24, p.GetMinute() );
				EXPECT_EQ( 2, p.GetMinute10() );
				EXPECT_EQ( 4, p.GetMinute1() );
				EXPECT_EQ( 24 * 60, p.GetSeconds() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
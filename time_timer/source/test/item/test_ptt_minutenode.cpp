#include "test_ptt_minutenode.h"

#include <conio.h>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2render_Camera.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_DebugConfig.h"
#include "ptt/ptt_MinuteComponent.h"
#include "ptt/ptt_MinuteNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_minutenode
{
	r2tm::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MinuteNode : Generate";
		};
	}
	r2tm::DoFunctionT Generate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			LF();

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			LS();

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );

			LS();

			{
				EXPECT_TRUE( node->GetComponent<ptt::MinuteComponent>() );
			}

			LS();

			if( ptt::DebugConfig::GetNodeConfig().pivot )
			{
				EXPECT_EQ( 3, node->GetChildCount() );
			}
			else
			{
				EXPECT_EQ( 2, node->GetChildCount() );
			}
			
			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MinuteNode : View";
		};
	}
	r2tm::DoFunctionT View::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 7 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			LF();

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			LS();

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );

			LS();

			{
				PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				LF();

				Utility4Test::DrawTexture( render_target );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}






	r2tm::TitleFunctionT Process::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MinuteNode : Process";
		};
	}
	r2tm::DoFunctionT Process::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 7 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			LS();

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			LS();

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto minute_component = node->GetComponent<ptt::MinuteComponent>() );

			LS();

			{
				std::cout << r2tm::tab << "# Key" << r2tm::linefeed;
				std::cout << r2tm::tab << "[Q/A] Minute 10 | Up/Down" << r2tm::linefeed;
				std::cout << r2tm::tab << "[W/S] Minute  1 | Up/Down" << r2tm::linefeed;
			}

			LS();

			{
				int minute_10 = 0;
				int minute_1 = 0;

				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2tm::WindowUtility::MoveCursorPoint( pivot_point );

					PROCESS_MAIN( minute_component->SetMinute( minute_10, minute_1 ) );
					PROCESS_MAIN( node->Update( 0.1f ) );
					PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

					LF();

					Utility4Test::DrawTexture( render_target );

					input = _getch();
					switch( input )
					{
					case 'q':
						minute_10 = std::min( 9, minute_10 + 1 );
						break;
					case 'a':
						minute_10 = std::max( 0, minute_10 - 1 );
						break;

					case 'w':
						minute_1 = std::min( 9, minute_1 + 1 );
						break;
					case 's':
						minute_1 = std::max( 0, minute_1 - 1 );
						break;
					}

				} while( 27 != input );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}
}
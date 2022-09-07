#include "test_ptt_minutenode.h"

#include <conio.h>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_DebugConfig.h"
#include "ptt/ptt_MinuteComponent.h"
#include "ptt/ptt_MinuteNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_minutenode
{
	r2cm::iItem::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MinuteNode : Generate";
		};
	}
	r2cm::iItem::DoFunctionT Generate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2base::Director dummy_director( {} ) );

			std::cout << r2cm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( node->GetComponent<ptt::MinuteComponent>() );
			}

			std::cout << r2cm::split;

			if( ptt::DebugConfig::GetNodeConfig().pivot )
			{
				EXPECT_EQ( 3, node->GetChildCount() );
			}
			else
			{
				EXPECT_EQ( 2, node->GetChildCount() );
			}
			
			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MinuteNode : View";
		};
	}
	r2cm::iItem::DoFunctionT View::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 7 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director( {} ) );

			std::cout << r2cm::linefeed;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2cm::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}






	r2cm::iItem::TitleFunctionT Process::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MinuteNode : Process";
		};
	}
	r2cm::iItem::DoFunctionT Process::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 7 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director( {} ) );

			std::cout << r2cm::split;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto minute_component = node->GetComponent<ptt::MinuteComponent>() );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "# Key" << r2cm::linefeed;
				std::cout << r2cm::tab << "[Q/A] Minute 10 | Up/Down" << r2cm::linefeed;
				std::cout << r2cm::tab << "[W/S] Minute  1 | Up/Down" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int minute_10 = 0;
				int minute_1 = 0;

				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2cm::WindowUtility::MoveCursorPoint( pivot_point );

					PROCESS_MAIN( minute_component->SetMinute( minute_10, minute_1 ) );
					PROCESS_MAIN( node->Update( 0.1f ) );
					PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

					std::cout << r2cm::linefeed;

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

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}
#include "test_ptt_secondsnode.h"

#include <conio.h>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2render_Camera.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_DebugConfig.h"
#include "ptt/ptt_SecondsComponent.h"
#include "ptt/ptt_SecondsNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_secondsnode
{
	r2tm::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : Generate";
		};
	}
	r2tm::DoFunctionT Generate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			std::cout << r2tm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2tm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );

			std::cout << r2tm::split;

			{
				EXPECT_FALSE( node->IsVisible() );
				EXPECT_TRUE( node->GetComponent<ptt::SecondsComponent>() );
			}

			std::cout << r2tm::split;

			if( ptt::DebugConfig::GetNodeConfig().pivot )
			{
				EXPECT_EQ( 3, node->GetChildCount() );
			}
			else
			{
				EXPECT_EQ( 2, node->GetChildCount() );
			}
			
			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : View";
		};
	}
	r2tm::DoFunctionT View::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), 'x' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			std::cout << r2tm::linefeed;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2tm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );
			PROCESS_MAIN( node->SetVisible( true ) );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2tm::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Process::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : Process";
		};
	}
	r2tm::DoFunctionT Process::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), 'x' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			std::cout << r2tm::split;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2tm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto seconds_component = node->GetComponent<ptt::SecondsComponent>() );

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "# Key" << r2tm::linefeed;
				std::cout << r2tm::tab << "[Q/A] Seconds Up/Down" << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			DECLARATION_MAIN( int seconds = 0 );

			std::cout << r2tm::split;

			{
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

					std::cout << "Current Seconds : " << seconds << r2tm::linefeed;
					PROCESS_MAIN( render_target.FillCharacterAll( 'x' ) );
					PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

					std::cout << r2tm::linefeed;

					Utility4Test::DrawTexture( render_target );

					input = _getch();
					switch( input )
					{
					case 'q':
						seconds = ++seconds;
						seconds_component->Toggle( seconds );
						break;

					case 'a':
						seconds = --seconds;
						seconds_component->Toggle( seconds );
						break;
					}

				} while( 27 != input );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::None;
		};
	}
}
#include "test_ptt_secondsnode.h"

#include <conio.h>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2render_Camera.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_DebugConfig.h"
#include "ptt/ptt_SecondsComponent.h"
#include "ptt/ptt_SecondsNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_secondsnode
{
	r2cm::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : Generate";
		};
	}
	r2cm::DoFunctionT Generate::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			std::cout << r2cm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( node->IsVisible() );
				EXPECT_TRUE( node->GetComponent<ptt::SecondsComponent>() );
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

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : View";
		};
	}
	r2cm::DoFunctionT View::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), 'x' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			std::cout << r2cm::linefeed;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );
			PROCESS_MAIN( node->SetVisible( true ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2cm::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Process::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : Process";
		};
	}
	r2cm::DoFunctionT Process::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), 'x' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			std::cout << r2cm::split;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto seconds_component = node->GetComponent<ptt::SecondsComponent>() );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "# Key" << r2cm::linefeed;
				std::cout << r2cm::tab << "[Q/A] Seconds Up/Down" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( int seconds = 0 );

			std::cout << r2cm::split;

			{
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{

					r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

					std::cout << "Current Seconds : " << seconds << r2cm::linefeed;
					PROCESS_MAIN( render_target.FillCharacterAll( 'x' ) );
					PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

					std::cout << r2cm::linefeed;

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

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::None;
		};
	}
}
#include "test_ptt_secondsnode.h"

#include <conio.h>

#include "r2bix/r2base_Director.h"
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
	r2cm::iItem::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : Generate";
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

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( node->GetComponent<ptt::SecondsComponent>() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( node->GetComponent<r2component::TextureFrameRenderComponent>() );
				EXPECT_TRUE( node->GetComponent<r2component::TextureFrameRenderComponent>()->GetTextureFrame() );
			}

			std::cout << r2cm::split;

			if( ptt::Config::GetNodeConfig().pivot )
			{
				EXPECT_EQ( 1, node->GetChildCount() );
			}
			else
			{
				EXPECT_EQ( 0, node->GetChildCount() );
			}
			
			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SecondsNode : View";
		};
	}
	r2cm::iItem::DoFunctionT View::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), 'x' ) );
			DECLARATION_SUB( r2base::Director dummy_director( {} ) );

			std::cout << r2cm::linefeed;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );

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
			return "SecondsNode : Process";
		};
	}
	r2cm::iItem::DoFunctionT Process::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 31, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), 'x' ) );
			DECLARATION_SUB( r2base::Director dummy_director( {} ) );

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
				std::cout << r2cm::tab << "[Space] Apply Seconds" << r2cm::linefeed;
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
						break;
					case 'a':
						seconds = --seconds;
						break;

					case 32:
						seconds_component->Toggle( seconds );
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}
#include "test_ptt_numbernode.h"

#include <conio.h>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_NumberComponent.h"
#include "ptt/ptt_NumberNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_numbernode
{
	r2tm::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : Generate";
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

			DECLARATION_MAIN( auto node = ptt::NumberNode::Create( dummy_director ) );

			LS();

			{
				DECLARATION_MAIN( auto tfrc = node->GetComponent<r2component::TextureFrameRenderComponent>() );

				LF();

				EXPECT_TRUE( tfrc );
				EXPECT_EQ( ptt::TextureTable::GetInstance().GetTextureFrame( "number_0" ), tfrc->GetTextureFrame() );
			}
			
			LS();

			{
				DECLARATION_MAIN( auto tfac = node->GetComponent<r2component::TextureFrameAnimationComponent>() );

				LF();

				EXPECT_TRUE( tfac );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_0 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_1 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_2 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_3 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_4 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_5 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_6 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_7 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_8 ) );
				EXPECT_TRUE( tfac->HasAnimation( r2animation::eIndex::Idle_9 ) );
			}

			LS();

			{
				DECLARATION_MAIN( auto number_component = node->GetComponent<ptt::NumberComponent>() );

				LF();

				EXPECT_TRUE( number_component );
				EXPECT_EQ( node->GetComponent<r2component::TextureFrameAnimationComponent>(), number_component->GetTextureFrameAnimationComponent() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FirstView::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : FirstView";
		};
	}
	r2tm::DoFunctionT FirstView::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 11, 7 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			LF();

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			LS();

			DECLARATION_MAIN( auto node = ptt::NumberNode::Create( dummy_director ) );

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
			return "NumberNode : Process";
		};
	}
	r2tm::DoFunctionT Process::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 15, 9 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2bix::Director dummy_director( {} ) );

			LS();

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			LS();

			DECLARATION_MAIN( auto node = ptt::NumberNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto number_component = node->GetComponent<ptt::NumberComponent>() );

			LS();

			{
				std::cout << r2tm::tab << "# Key" << r2tm::linefeed;
				std::cout << r2tm::tab << "[0 ~ 9] Play Animation" << r2tm::linefeed;
			}

			LS();

			{
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int input = 0;
				int new_number = 0;
				do
				{

					r2tm::WindowUtility::MoveCursorPoint( pivot_point );

					PROCESS_MAIN( node->Update( 0.1f ) );
					PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

					LF();

					Utility4Test::DrawTexture( render_target );

					input = _getch();

					new_number = input - 48; // 48 == '0'
					if( 0 <= new_number && new_number < 10 )
					{
						number_component->SetNumber( new_number );
					}

				} while( 27 != input );
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}
}
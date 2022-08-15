#include "test_ptt_numbernode.h"

#include <conio.h>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_NumberComponent.h"
#include "ptt/ptt_NumberNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_numbernode
{
	r2cm::iItem::TitleFunctionT Generate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : Generate";
		};
	}
	r2cm::iItem::DoFunctionT Generate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::NumberNode::Create( dummy_director ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto tfrc = node->GetComponent<r2component::TextureFrameRenderComponent>() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( tfrc );
				EXPECT_EQ( ptt::TextureTable::GetInstance().GetTextureFrame( "number_0" ), tfrc->GetTextureFrame() );
			}
			
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto tfac = node->GetComponent<r2component::TextureFrameAnimationComponent>() );

				std::cout << r2cm::linefeed;

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

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto number_component = node->GetComponent<ptt::NumberComponent>() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( number_component );
				EXPECT_EQ( node->GetComponent<r2component::TextureFrameAnimationComponent>(), number_component->GetTextureFrameAnimationComponent() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT FirstView::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "NumberNode : FirstView";
		};
	}
	r2cm::iItem::DoFunctionT FirstView::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 11, 7 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::NumberNode::Create( dummy_director ) );

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
			return "NumberNode : Process";
		};
	}
	r2cm::iItem::DoFunctionT Process::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 15, 9 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::split;

			PROCESS_SUB( ptt::TextureTable::GetInstance().Load() );
			PROCESS_SUB( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::NumberNode::Create( dummy_director ) );
			DECLARATION_MAIN( auto number_component = node->GetComponent<ptt::NumberComponent>() );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "# Key" << r2cm::linefeed;
				std::cout << r2cm::tab << "[0 ~ 9] Play Animation" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				int new_number = 0;
				do
				{

					r2cm::WindowUtility::MoveCursorPoint( pivot_point );

					PROCESS_MAIN( node->Update( 0.1f ) );
					PROCESS_MAIN( node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

					std::cout << r2cm::linefeed;

					Utility4Test::DrawTexture( render_target );

					input = _getch();

					new_number = input - 48; // 48 == '0'
					if( 0 <= new_number && new_number < 10 )
					{
						number_component->SetNumber( new_number );
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}
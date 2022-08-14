#include "test_ptt_minutenode.h"

#include <conio.h>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

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

			DECLARATION_MAIN( auto node = ptt::MinuteNode::Create( dummy_director ) );

			std::cout << r2cm::split;

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
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

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
}
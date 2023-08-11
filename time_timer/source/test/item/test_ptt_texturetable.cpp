#include "test_ptt_texturetable.h"

#include <string>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_texturetable
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Texture Table";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );

			std::cout << r2tm::split;

			{
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

				std::string temp = "number_ ";
				for( short i = 0; 10 > i; ++i )
				{
					temp.pop_back();
					temp += std::to_string( i );

					auto tf = ptt::TextureTable::GetInstance().GetTextureFrame( temp.c_str() );

					Utility4Test::DrawTextureFrame( pivot_point.x + ( i * static_cast<short>( tf->GetWidth() + 2 ) ), pivot_point.y, *tf );
				}
			}

			std::cout << r2tm::split;

			{
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

				std::string temp = "indicator_up_ ";
				for( short i = 0; 5 > i; ++i )
				{
					temp.pop_back();
					temp += std::to_string( i );

					auto tf = ptt::TextureTable::GetInstance().GetTextureFrame( temp.c_str() );

					Utility4Test::DrawTextureFrame( pivot_point.x + ( i * static_cast<short>( tf->GetWidth() + 2 ) ), pivot_point.y, *tf );
				}
			}

			std::cout << r2tm::split;

			{
				auto tf = ptt::TextureTable::GetInstance().GetTextureFrame( "seconds_0" );

				Utility4Test::DrawTextureFrame( *tf );
			}

			std::cout << r2tm::split;

			{
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

				std::string temp = "indicator_down_ ";
				for( short i = 0; 5 > i; ++i )
				{
					temp.pop_back();
					temp += std::to_string( i );

					auto tf = ptt::TextureTable::GetInstance().GetTextureFrame( temp.c_str() );

					Utility4Test::DrawTextureFrame( pivot_point.x + ( i * static_cast<short>( tf->GetWidth() + 2 ) ), pivot_point.y, *tf );
				}
			}

			std::cout << r2tm::split;

			{
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

				{
					auto tf = ptt::TextureTable::GetInstance().GetTextureFrame( "select_indicator_left_0" );
					Utility4Test::DrawTextureFrame( pivot_point.x, pivot_point.y, *tf );
				}

				{
					auto tf = ptt::TextureTable::GetInstance().GetTextureFrame( "select_indicator_right_0" );
					Utility4Test::DrawTextureFrame( pivot_point.x + static_cast<short>( tf->GetWidth() + 3 ), pivot_point.y, *tf );
				}
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
#include "ptt_TextureTable.h"

#include "r2bix/r2render_Texture.h"
#include "r2bix/r2render_TextureFrame.h"

namespace ptt
{
	void TextureTable::Load()
	{
		if( !mTextureContainer.empty() )
		{
			return;
		}

		{
			auto result = mTextureContainer.emplace( "project_timer_timer_image", TextureValueT( new ( std::nothrow ) r2render::Texture(
				60,
				//		"          1         2         3         4         5         6         7"
				//		"01234567890123456789012345678901234567890123456789012345678901234567890"
				/* 0 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  xxxxxxxxx    "
				/* 1 */ "x 00000 xx  11   xx 22222 xx 33333 xx 4  4  x  x*******x    "
				/* 2 */ "x0     0xx 111   xx2     2xx3     3xx4   4  x  x ***** x    "
				/* 3 */ "x0     0xx   1   xx  2222 xx   333 xx4   4  x  x  ***  x    "
				/* 4 */ "x0     0xx   1   xx22     xx3     3xx4444444x  x   *   x    "
				/* 5 */ "x 00000 xx1111111xx2222222xx 33333 xx    4  x  x       x    "
				/* 6 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  x       x    "
				/* 7 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  x       x    "
				/* 8 */ "x555555 xx 666   xx7777777xx 88888 xx 99999 x  x       x    "
				/* 9 */ "x5      xx6      xx      7xx8     8xx9     9x  x       x    "
				/* 0 */ "x555555 xx666666 xx      7xx 88888 xx 999999x  x       x    "
				/* 1 */ "x      5xx6     6xx      7xx8     8xx      9x  x       x    "
				/* 2 */ "x555555 xx 66666 xx      7xx 88888 xx 99999 x  x       x    "
				/* 3 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  x       x    "
				/* 4 */ "xxxxxxxxxxxxxxxxxxx                            x   *   x    "
				/* 5 */ "x=================x                            x  ***  x    "
				/* 6 */ "xxxxxxxxxxxxxxxxxxx                            x ***** x    "
				/* 7 */ "                                               x*******x    "
				/* 8 */ "                                               xxxxxxxxx    "
				/* 9 */ "                                                            "
				/* 0 */ "                                                            "
				/* 1 */ "                                                            "
				/* 2 */ "                                                            "
				/* 3 */ "                                                            "
			) ) );

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 1, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_1"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 10, 1, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_2"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 19, 1, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_3"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 28, 1, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_4"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 37, 1, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_5"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 8, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_6"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 10, 8, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_7"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 19, 8, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_8"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 28, 8, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_9"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 37, 8, 6, 4 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"indicator_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 48, 1, 6, 16 ) );
			}

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"seconds_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 15, 16, 0 ) );
			}
		}
	}
}
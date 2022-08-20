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
				/* 0 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 1 */ "x 00000 xx  11   xx 22222 xx 33333 xx 4  4  x               "
				/* 2 */ "x0     0xx 111   xx2     2xx3     3xx4   4  x               "
				/* 3 */ "x0     0xx   1   xx  2222 xx   333 xx4   4  x               "
				/* 4 */ "x0     0xx   1   xx22     xx3     3xx4444444x               "
				/* 5 */ "x 00000 xx1111111xx2222222xx 33333 xx    4  x               "
				/* 6 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 7 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 8 */ "x555555 xx 666   xx7777777xx 88888 xx 99999 x               "
				/* 9 */ "x5      xx6      xx      7xx8     8xx9     9x               "
				/* 0 */ "x555555 xx666666 xx      7xx 88888 xx 999999x               "
				/* 1 */ "x      5xx6     6xx      7xx8     8xx      9x               "
				/* 2 */ "x555555 xx 66666 xx      7xx 88888 xx 99999 x               "
				/* 3 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 4 */ "xxxxxxxxxxxxxxxxxxx                                         "
				/* 5 */ "x=================x                                         "
				/* 6 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   "
				/* 7 */ "x   w   x   w   x   w   x   w   x       x                   "
				/* 8 */ "x  www  x  www  x  www  x       x  www  x                   "
				/* 9 */ "x wwwww x wwwww x       x wwwww x wwwww x                   "
				/* 0 */ "xwwwwwwwx       xwwwwwwwxwwwwwwwxwwwwwwwx                   "
				/* 1 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   "
				/* 2 */ "xsssssssx       xsssssssxsssssssxsssssssx                   "
				/* 3 */ "x sssss x sssss x       x sssss x sssss x                   "
				/* 4 */ "x  sss  x  sss  x  sss  x       x  sss  x                   "
				/* 5 */ "x   s   x   s   x   s   x   s   x       x                   "
				/* 6 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   "
				/* 7 */ "x    axd     x                                              "
				/* 8 */ "x  aaaxddd   x                                              "
				/* 9 */ "xaaaaaxddddddx                                              "
				/* 0 */ "x  aaaxddd   x                                              "
				/* 1 */ "x    axd     x                                              "
				/* 2 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   "
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
					"seconds_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 15, 16, 0 ) );
			}



			//
			//
			//
			{
				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_up_0"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 17, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_up_1"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 9, 17, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_up_2"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 17, 17, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_up_3"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 25, 17, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_up_4"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 33, 17, 6, 3 ) );
				}
			}


			//
			//
			//
			{
				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_down_0"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 22, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_down_1"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 9, 22, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_down_2"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 17, 22, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_down_3"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 25, 22, 6, 3 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"indicator_down_4"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 33, 22, 6, 3 ) );
				}
			}


			//
			//
			//
			{
				{
					auto frame_result = mTextureFrameContainer.emplace(
						"select_indicator_left_0"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 27, 4, 4 ) );
				}

				{
					auto frame_result = mTextureFrameContainer.emplace(
						"select_indicator_right_0"
						, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
					);
					frame_result.first->second->SetVisibleRect( r2::RectInt( 7, 27, 4, 4 ) );
				}
			}
		}
	}
}
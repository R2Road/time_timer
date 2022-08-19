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
				/* 1 */ "x=00000=====11======22222====33333====4==4==x  x*******x    "
				/* 2 */ "x0=====0===111=====2=====2==3=====3==4===4==x  x ***** x    "
				/* 3 */ "x0=====0=====1=======2222======333===4===4==x  x  ***  x    "
				/* 4 */ "x0=====0=====1=====22=======3=====3==4444444x  x   *   x    "
				/* 5 */ "x=00000===1111111==2222222===33333=======4==x  x       x    "
				/* 6 */ "x===========================================x  x       x    "
				/* 7 */ "x===========================================x  x       x    "
				/* 8 */ "x555555====666=====7777777===88888====99999=x  x       x    "
				/* 9 */ "x5========6==============7==8=====8==9=====9x  x       x    "
				/* 0 */ "x555555===666666=========7===88888====999999x  x       x    "
				/* 1 */ "x======5==6=====6========7==8=====8========9x  x       x    "
				/* 2 */ "x555555====66666=========7===88888====99999=x  x       x    "
				/* 3 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  x       x    "
				/* 4 */ "                                               x   *   x    "
				/* 5 */ "                                               x  ***  x    "
				/* 6 */ "                                               x ***** x    "
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
		}
	}
}
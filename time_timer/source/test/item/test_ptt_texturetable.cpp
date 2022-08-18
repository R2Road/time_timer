#include "test_ptt_texturetable.h"

#include <string>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_TextureTable.h"
#include "test/Utility4Test.h"

namespace test_ptt_texturetable
{
	r2cm::iItem::TitleFunctionT Number::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Texture Table : Number";
		};
	}
	r2cm::iItem::DoFunctionT Number::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );

			std::cout << r2cm::split;

			{
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();

				std::string temp = "number_ ";
				for( short i = 0; 10 > i; ++i )
				{
					temp.pop_back();
					temp += std::to_string( i );

					auto tf_num = ptt::TextureTable::GetInstance().GetTextureFrame( temp.c_str() );

					Utility4Test::DrawTextureFrame( pivot_point.x + ( i * static_cast<short>( tf_num->GetWidth() + 2 ) ), pivot_point.y, *tf_num );
				}
			}

			std::cout << r2cm::split;

			{
				auto tf_num = ptt::TextureTable::GetInstance().GetTextureFrame( "indicator_0" );

				Utility4Test::DrawTextureFrame( *tf_num );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
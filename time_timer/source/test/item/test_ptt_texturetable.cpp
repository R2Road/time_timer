#include "test_ptt_texturetable.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

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
				DECLARATION_MAIN( auto tf_num = ptt::TextureTable::GetInstance().GetTextureFrame( "number_0" ) );

				std::cout << r2cm::linefeed;

				Utility4Test::DrawTextureFrame( *tf_num );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
#include "test_ptt_secondsnode.h"

#include <conio.h>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"
#include "r2bix/r2render_Camera.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "ptt/ptt_Config.h"
#include "ptt/ptt_SecondsNode.h"
#include "ptt/ptt_TextureFrameAnimationTable.h"
#include "ptt/ptt_TextureTable.h"

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

			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::linefeed;

			PROCESS_MAIN( ptt::TextureTable::GetInstance().Load() );
			PROCESS_MAIN( ptt::TextureFrameAnimationTable::GetInstance().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto node = ptt::SecondsNode::Create( dummy_director ) );

			std::cout << r2cm::split;

			{
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
}
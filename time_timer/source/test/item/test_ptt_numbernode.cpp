#include "test_ptt_numbernode.h"

#include "r2bix/r2base_Director.h"
#include "r2bix/r2render_Camera.h"
#include "r2bix/r2component_TextureFrameAnimationComponent.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "ptt/ptt_NumberNode.h"
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

			DECLARATION_SUB( r2render::Camera camera( { 0, 0 }, { 21, 11 } ) );
			DECLARATION_SUB( r2render::Texture render_target( camera.GetWidth(), camera.GetHeight(), '=' ) );
			DECLARATION_SUB( r2base::Director dummy_director );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto number_node = ptt::NumberNode::Create( dummy_director ) );
			EXPECT_TRUE( number_node->GetComponent<r2component::TextureFrameAnimationComponent>() );
			EXPECT_TRUE( number_node->GetComponent<r2component::TextureFrameRenderComponent>() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( number_node->Render( &camera, &render_target, r2::PointInt::GetZERO() ) );

				std::cout << r2cm::linefeed;

				Utility4Test::DrawTexture( render_target );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
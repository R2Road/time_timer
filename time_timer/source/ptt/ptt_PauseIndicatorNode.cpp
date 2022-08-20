#include "ptt_PauseIndicatorNode.h"

#include <string_view>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2component_CustomTextureComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"

#include "ptt_Config.h"
#include "ptt_SecondsComponent.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp PauseIndicatorNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddComponent<ptt::SecondsComponent>();

			//
			//
			//
			{
				auto custome_texture_component = ret->AddComponent<r2component::CustomTextureComponent>();
				custome_texture_component->GetTexture()->Reset( director.GetScreenBufferSize().GetWidth(), director.GetScreenBufferSize().GetHeight(), ' ' );

				custome_texture_component->GetTexture()->FillColorAll( r2base::eBackgroundColor::BG_LightBlue );

				const std::string_view str = "pause ";
				auto current_c = str.begin();
				for( int y = 0, y_end = custome_texture_component->GetTexture()->GetHeight(); y_end > y; ++y )
				{
					for( int x = 0, x_end = custome_texture_component->GetTexture()->GetWidth(); x_end > x; ++x )
					{
						custome_texture_component->GetTexture()->FillCharacter( x, y, *current_c );

						++current_c;
						if( str.end() == current_c )
						{
							current_c = str.begin();
						}
					}
				}

				auto texture_render_component = ret->AddComponent<r2component::TextureRenderComponent>();
				texture_render_component->SetTexture( custome_texture_component->GetTexture() );
				texture_render_component->SetPivotPoint( 0, 0 );
			}


			//
			//
			//
			if( ptt::Config::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>();
			}

		}

		return ret;
	}
}
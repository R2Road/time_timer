#include "ptt_AlramEffectNode.h"

#include <string_view>

#include "r2bix/r2action_BlinkAction.h"
#include "r2bix/r2action_DelayAction.h"
#include "r2bix/r2action_RepeatAction.h"
#include "r2bix/r2action_SequenceAction.h"
#include "r2bix/r2bix_Director.h"
#include "r2bix/r2node_PivotNode.h"
#include "r2bix/r2component_ActionProcessComponent.h"
#include "r2bix/r2component_CustomTextureComponent.h"
#include "r2bix/r2component_TextureRenderComponent.h"

#include "ptt_DebugConfig.h"
#include "ptt_SecondsComponent.h"
#include "ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp AlramEffectNode::Create( r2bix::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddComponent<ptt::SecondsComponent>();
			ret->SetVisible( false );

			//
			// Setup
			//
			{
				auto custome_texture_component = ret->AddComponent<r2component::CustomTextureComponent>();
				{
					custome_texture_component->GetTexture()->Reset( director.GetScreenBufferSize().GetWidth(), director.GetScreenBufferSize().GetHeight(), ' ' );

					custome_texture_component->GetTexture()->FillColorAll( r2base::eForegroundColor::FG_LightYellow | r2base::eBackgroundColor::BG_LightGreen );

					const std::string_view str = "You Win~!! ";
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
				}

				auto texture_render_component = ret->AddComponent<r2component::TextureRenderComponent>();
				texture_render_component->SetTexture( custome_texture_component->GetTexture() );
				texture_render_component->SetPivotPoint( 0, 0 );

				auto action_process_component = ret->AddComponent<r2component::ActionProcessComponent>();
				{
					auto root_action = r2action::RepeatAction::Create();
					{
						auto sequence_action = r2action::SequenceAction::Create();
						{
							auto delay_action = sequence_action->AddAction<r2action::DelayAction>();
							delay_action->SetTimeLimit( 0.5f );

							auto blink_action = sequence_action->AddAction<r2action::BlinkAction>();
							blink_action->SetTimeLimit( 0.5f );
						}

						root_action->SetAction( std::move( sequence_action ) );
					}
					action_process_component->SetAction( std::move( root_action ) );
				}

				action_process_component->StartAction();
			}


			//
			// Debug
			//
			if( ptt::DebugConfig::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>();
			}

		}

		return ret;
	}
}
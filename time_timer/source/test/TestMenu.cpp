#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_ptt_core.h"
#include "item/test_ptt_demo.h"
#include "item/test_ptt_minutenode.h"
#include "item/test_ptt_numbernode.h"
#include "item/test_ptt_secondsnode.h"
#include "item/test_ptt_texturetable.h"
#include "item/test_ptt_timer.h"

r2cm::MenuUp TestMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', test_ptt_texturetable::Basic() );



		ret->AddLineFeed();



		ret->AddItem( '2', test_ptt_timer::Generate() );
		ret->AddItem( '3', test_ptt_timer::Set() );
		ret->AddItem( '4', test_ptt_timer::Start() );
		ret->AddItem( '5', test_ptt_timer::Update() );
		ret->AddItem( '6', test_ptt_timer::Stop() );
		ret->AddItem( '7', test_ptt_timer::Pause() );



		ret->AddLineFeed();



		ret->AddItem( '9', test_ptt_core::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_ptt_numbernode::Generate() );
		ret->AddItem( 'w', test_ptt_numbernode::FirstView() );
		ret->AddItem( 'e', test_ptt_numbernode::Process() );



		ret->AddLineFeed();



		ret->AddItem( 'a', test_ptt_minutenode::Generate() );
		ret->AddItem( 's', test_ptt_minutenode::View() );
		ret->AddItem( 'd', test_ptt_minutenode::Process() );



		ret->AddLineFeed();



		ret->AddItem( 'z', test_ptt_secondsnode::Generate() );
		ret->AddItem( 'x', test_ptt_secondsnode::View() );
		ret->AddItem( 'c', test_ptt_secondsnode::Process() );



		ret->AddSplit();



		ret->AddItem( 32, test_ptt_demo::Play() ); // space



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::FG_White
			, []()->const char* { return "Exit"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				return r2cm::eItemLeaveAction::Exit;
			}
		);
	}

	return ret;
}
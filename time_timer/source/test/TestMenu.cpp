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
		ret->AddItem( '1', test_ptt_texturetable::Basic::GetInstance() );



		ret->AddSplit();



		ret->AddItem( '2', test_ptt_timer::Generate::GetInstance() );
		ret->AddItem( '3', test_ptt_timer::Set::GetInstance() );
		ret->AddItem( '4', test_ptt_timer::Start::GetInstance() );
		ret->AddItem( '5', test_ptt_timer::Update::GetInstance() );
		ret->AddItem( '6', test_ptt_timer::Stop::GetInstance() );
		ret->AddItem( '7', test_ptt_timer::Pause::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( '9', test_ptt_core::Basic::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_ptt_numbernode::Generate::GetInstance() );
		ret->AddItem( 'w', test_ptt_numbernode::FirstView::GetInstance() );
		ret->AddItem( 'e', test_ptt_numbernode::Process::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'a', test_ptt_minutenode::Generate::GetInstance() );
		ret->AddItem( 's', test_ptt_minutenode::View::GetInstance() );
		ret->AddItem( 'd', test_ptt_minutenode::Process::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'z', test_ptt_secondsnode::Generate::GetInstance() );
		ret->AddItem( 'x', test_ptt_secondsnode::View::GetInstance() );
		ret->AddItem( 'c', test_ptt_secondsnode::Process::GetInstance() );



		ret->AddSplit();



		ret->AddItem( 32, test_ptt_demo::Play::GetInstance() ); // space



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
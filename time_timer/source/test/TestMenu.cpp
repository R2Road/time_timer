#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_ptt_minutenode.h"
#include "item/test_ptt_numbernode.h"
#include "item/test_ptt_texturetable.h"

r2cm::MenuUp TestMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', test_ptt_texturetable::Number::GetInstance() );



		ret->AddSplit();



		ret->AddItem( '2', test_ptt_numbernode::Generate::GetInstance() );
		ret->AddItem( '3', test_ptt_numbernode::FirstView::GetInstance() );
		ret->AddItem( '4', test_ptt_numbernode::Process::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_ptt_minutenode::Generate::GetInstance() );
		ret->AddItem( 'w', test_ptt_minutenode::View::GetInstance() );
		ret->AddItem( 'e', test_ptt_minutenode::Process::GetInstance() );



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
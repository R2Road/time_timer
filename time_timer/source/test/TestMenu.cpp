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

r2cm::TitleFunctionT TestMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Test Menu";
	};
}
r2cm::DescriptionFunctionT TestMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2cm::WriteFunctionT TestMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_ptt_texturetable::Basic() );



		ret->AddLineFeed();



		ret->AddItem( '2', test_ptt_timer::Declaration() );
		ret->AddItem( '3', test_ptt_timer::Set() );
		ret->AddItem( '4', test_ptt_timer::Start() );
		ret->AddItem( '5', test_ptt_timer::Update() );
		ret->AddItem( '6', test_ptt_timer::Stop() );
		ret->AddItem( '7', test_ptt_timer::Pause() );



		ret->AddLineFeed();



		ret->AddItem( '8', test_ptt_core::Declaration() );
		ret->AddItem( '9', test_ptt_core::RequiredTime() );



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
			, r2cm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}
#include "DevelopmentMenu.h"

#include <string>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2bix_VersionInfo.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_VersionInfo.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "ptt/ptt_DirectorConfig.h"
#include "ptt/ptt_EntryScene.h"
#include "ptt/ptt_VersionInfo.h"

#include "test/TestMenu.h"

r2cm::TitleFunctionT DevelopmentMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Development Menu" )
			+ " : <" + r2cm::VersionInfo.String4Version + ">"
			+ " : <" + r2bix::VersionInfo.String4Version + ">"
			+ " : <" + ptt::VersionInfo.String4Version + ">";
		return ret.c_str();
	};
}
r2cm::DescriptionFunctionT DevelopmentMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ptt::VersionInfo.String4SubjectAsAProgrammer; };
}
r2cm::WriteFunctionT DevelopmentMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem(
			'1'
			, r2cm::eColor::FG_White
			, []()->const char* { return "Test"; }
			, []()->r2cm::eDoLeaveAction
			{
				// 2022.04.11 by R2Road
				// 인자로 넘어온 director 를 사용해도 되지만 아래 코드와의 일관성을 위해 새 r2cm::Director를 만들어 돌린다.

				//
				// Setup
				//
				r2cm::Director director;
				director.Setup( TestMenu() );

				//
				// Process
				//
				director.Run();

				return r2cm::eDoLeaveAction::None;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			32
			, r2cm::eColor::BG_Blue
			, []()->const char* { return "Time Timer"; }
			, []()->r2cm::eDoLeaveAction
			{
				r2cm::WindowUtility::Resize( 548, 548 );
				r2cm::WindowUtility::Move( 0, 0 );

				{
					//
					// Setup
					//
					r2bix::Director director( ptt::DirectorConfig );
					director.Setup( ptt::EntryScene::Create( director ) );

					//
					// Environment : ScrollBar | Maximize Button | Frame Lock
					//
					r2cm::WindowUtility::ScrollBarVisible( false );
					r2cm::WindowUtility::MaximizeButtonEnable( false );
					r2cm::WindowUtility::ResizingByDraggingEnable( false );

					//
					// Process
					//
					director.Run();
				}

				r2cm::WindowUtility::Resize( 960, 960 );
				r2cm::WindowUtility::Move( 0, 0 );
				r2cm::WindowUtility::ScrollBarVisible( true );
				r2cm::WindowUtility::MaximizeButtonEnable( true );
				r2cm::WindowUtility::ResizingByDraggingEnable( true );

				return r2cm::eDoLeaveAction::None;
			}
		);



		ret->AddSplit();



		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}
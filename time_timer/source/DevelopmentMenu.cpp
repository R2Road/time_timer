#include "DevelopmentMenu.h"

#include <string>

#include "r2bix/r2bix_Director.h"
#include "r2bix/r2bix_VersionInfo.h"

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_VersionInfo.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "ptt/ptt_DirectorConfig.h"
#include "ptt/ptt_EntryScene.h"
#include "ptt/ptt_VersionInfo.h"

#include "test/TestMenu.h"

r2tm::TitleFunctionT DevelopmentMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Development Menu" )
			+ " : " "<" + "C++17" + ">"
			+ ", " "<" + "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			+ ", " "<" + r2tm::VersionInfo.String4Version + ">"
			+ ", " "<" + r2bix::VersionInfo.String4Version + ">"
			+ ", " "<" + ptt::VersionInfo.String4Version + ">";
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT DevelopmentMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()
			+ ptt::VersionInfo.String4SubjectAsAProgrammer
			+ "\n"
			  "\n"
			  "\n"
			+ ptt::VersionInfo.String4Road2Version_1_0_9
		;

		return ret.c_str();
	};
}
r2tm::WriteFunctionT DevelopmentMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem(
			'1'
			, r2tm::eColor::FG_White
			, []()->const char* { return "Test"; }
			, []()->r2tm::eDoLeaveAction
			{
				// 2022.04.11 by R2Road
				// 인자로 넘어온 director 를 사용해도 되지만 아래 코드와의 일관성을 위해 새 r2tm::Director를 만들어 돌린다.

				//
				// Setup
				//
				r2tm::Director director;
				director.Setup( TestMenu() );

				//
				// Process
				//
				director.Run();

				return r2tm::eDoLeaveAction::None;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			32
			, r2tm::eColor::BG_Blue
			, []()->const char* { return "Time Timer"; }
			, []()->r2tm::eDoLeaveAction
			{
				r2tm::WindowUtility::Resize( 548, 548 );
				r2tm::WindowUtility::Move( 0, 0 );

				{
					//
					// Setup
					//
					r2bix::Director director( ptt::DirectorConfig );
					director.Setup( ptt::EntryScene::Create( director ) );

					//
					// Environment : ScrollBar | Maximize Button | Frame Lock
					//
					r2tm::WindowUtility::ScrollBarVisible( false );
					r2tm::WindowUtility::MaximizeButtonEnable( false );
					r2tm::WindowUtility::ResizingByDraggingEnable( false );

					//
					// Process
					//
					director.Run();
				}

				r2tm::WindowUtility::Resize( 960, 960 );
				r2tm::WindowUtility::Move( 0, 0 );
				r2tm::WindowUtility::ScrollBarVisible( true );
				r2tm::WindowUtility::MaximizeButtonEnable( true );
				r2tm::WindowUtility::ResizingByDraggingEnable( true );

				return r2tm::eDoLeaveAction::None;
			}
		);



		ret->AddSplit();



		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2tm::eDoLeaveAction
			{
				return r2tm::eDoLeaveAction::Exit;
			}
		);
	};
}
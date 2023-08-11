#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2tm/r2tm_WindowUtility.h"
#include "ptt/ptt_VersionInfo.h"

#define DEVELOPMENT_PTT 1

#if defined( DEVELOPMENT_PTT ) && ( DEVELOPMENT_PTT == 1 )

	#include "r2tm/r2tm_Director.h"
	#include "DevelopmentMenu.h"

#else

	#include "r2bix/r2bix_Director.h"
	#include "ptt/ptt_DirectorConfig.h"
	#include "ptt/ptt_EntryScene.h"

#endif

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowUtility::ChangeTitle( ptt::VersionInfo.String4Version );

#if defined( DEVELOPMENT_PTT ) && ( DEVELOPMENT_PTT == 1 )

	//
	// Environment : Size
	//
	r2tm::WindowUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2tm::WindowUtility::Move( 0, 0 );

	//
	// Setup & Run
	//
	r2tm::Director director;
	director.Setup( DevelopmentMenu() );
	director.Run();

#else

	//
	// Environment : Size
	//
	r2tm::WindowUtility::Resize( 548, 548 );

	//
	// Environment : Position
	//
	r2tm::WindowUtility::Move( 0, 0 );

	//
	// Setup
	//
	r2bix::Director director( ptt::DirectorConfig );
	director.Setup( ptt::EntryScene::Create( director ) );

	//
	// Environment : ScrollBar | Maximize Button | Frame Lock | QuickEdit
	//
	r2tm::WindowUtility::ScrollBarVisible( false );
	r2tm::WindowUtility::MaximizeButtonEnable( false );
	r2tm::WindowUtility::ResizingByDraggingEnable( false );
	r2tm::WindowUtility::QuickEditEnable( false );

	//
	// Run
	//
	director.Run();

#endif

	return 0;
}

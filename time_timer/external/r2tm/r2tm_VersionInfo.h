#pragma once

namespace r2tm
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	constexpr struct
	{

		const char* const String4VersionRule =
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0"  " : "  "�ϼ�?"
			"\n"	"> " "0.1.0.0"  " : "  "���� ���� ���ڰ� 10�� ����"
			"\n"	"> " "0.0.1.0"  " : "  "Road �Ϸ�"
			"\n"	"> " "0.0.0.1"  " : "  "����ڰ� ���� ������ ���� �Ǵ� ��ȭ"
		;



		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '7';
		const char VersionNumber_4 = '4';

		const char String4Version[16] = { 'r', '2', 't', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '\0' };



		const char* const String4Road2Version_1_0_8 =
					"### Road 2 Version 1.0.8 ###"
			"\n"
			"\n"	"[o] " "update    function   : r2tm::Inspector - OUTPUT_NOTE"
			"\n"	"[o] " "update    struct     : r2tm::WindowUtility::CursorPoint - ������ �߰�, ������ +, += �߰�"
			"\n"	"[o] " "update    inspector  : Add - OUTPUT_SOURCE_READY, OUTPUT_SOURCE_BEGIN, OUTPUT_SOURCE_END"
			"\n"	"[o] " "update    inspector  : Add - OUTPUT_SOURCE_READY_N_BEGIN"
			"\n"	"[ ] " "..."
		;

		const char* const String4Road2Version_1_0_7 =
					"### Road 2 Version 1.0.7 ###"
			"\n"
			"\n"	"[o] " "add method           : r2tm::WindowUtility::FillString"
			"\n"	"[o] " "update inspector     : Add - OUTPUT_STRING"
			"\n"	"[o] " "update inspector     : OUTPUT_SIZE - ũ�� �ڿ� byte ���ڿ� ���"
			"\n"	"[o] " "rename method        : r2tm::StopWatch - PrintMinAndMaxTime_NanoSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MilliSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MicroSeconds"
			"\n"	"[o] " "update menuprocessor : Ű, �޼��� �ؽ�Ʈ�� ��׶��� ���� ����"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - FillString"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - MoveCursorPoint"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - FillCharacter"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - FillColor"
			"\n"	"[o] " "overload    method   : r2tm::WindowUtility - MoveCursorPointWithClearBuffer"
		;

		const char* const String4Road2Version_1_0_6 =
					"### Road 2 Version 1.0.6 ###"
			"\n"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SUBJECT"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SIZE"
			"\n"	"[o] " "update ostream : Add - LF(), LF2(), LF3(), LS()"
			"\n"	"[o] " "update menuprocessor : Add - AddExit"
			"\n"	"[o] " "update inspector : Apply Color - OUTPUT_NOTE, OUTPUT_SUBJECT, OUTPUT_COMMENT, OUTPUT_CODE"
		;

		const char* const String4Road2Version_1_0_5 =
					"### Road 2 Version 1.0.5 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_GT, EXPECT_LT, EXPECT_GE, EXPECT_LE - ���н� �� ���"
			"\n"	"[o] " "Split Menu And MenuProcessor"
		;
		
		const char* const String4Road2Version_1_0_4 =
					"### Road 2 Version 1.0.4 ###"
			"\n"
			"\n"	"[o] " "update method : apply const - r2tm::iItem::GetDoFunction"
			"\n"	"[o] " "remove class : r2tm::SingleTon"
		;
		
		const char* const String4Road2Version_1_0_3 =
					"### Road 2 Version 1.0.3 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_EQ, EXPECT_NE - ���н� �� ���"
			"\n"	"[o] " "update inspector : OUTPUT_BINARY - ���ü� ����"
			"\n"	"[o] " "update inspector : inspector �� debug break ON/OFF ����"
			"\n"	"[o] " "update inspector : Add - OUTPUT_NOTE"
			"\n"	"[o] " "update inspector : Add - OUTPUT_COMMENT"
			"\n"	"[o] " "update inspector : OUTPUT_FILE ���� line index ���"
			"\n"	"[o] " "update inspector : Add - OUTPUT_FILE_RANGE"
		;
		
		const char* const String4Road2Version_1_0_2 =
					"### Road 2 Version 1.0.2 ###"
			"\n"
			"\n"	"[o] " "add method : r2tm::WindowUtility::ScrollBarVisible"
			"\n"	"[o] " "add method : r2tm::WindowUtility::MaximizeButtonEnable"
			"\n"	"[o] " "add method : r2tm::WindowUtility::ResizingByDraggingEnable"
			"\n"	"[o] " "add method : r2tm::WindowUtility::QuickEditEnable"
		;
		
		const char* const String4Road2Version_1_0_1 =
					"### Road 2 Version 1.0.1 ###"
			"\n"
			"\n"	"[o] " "add class : r2tm::StopWatch"
			"\n"	"[o] " "update method : r2tm::Menu::AddItem - Item ���� �÷� ����"
			"\n"	"[o] " "update method : r2tm::Menu::Do - �޴� ������ # �� ����ڰ� �Է����� �ʾƵ� �ǵ��� ����"
		;

		const char* const String4Road2Version_1_0_0 =
					"### Road 2 Version 1.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
		;



		const char* const String4Road2NextVersion = String4Road2Version_1_0_8;

	} VersionInfo;
}
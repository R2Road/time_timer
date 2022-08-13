#pragma once

namespace r2base
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	static struct
	{
		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '1';

		const char String4Version[15] = { 'r', '2', 'b', 'i', 'x', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4Road2Version_0_0_1 =
					"### Road 2 Version 0.0.1 ###"
			"\n\n"	"[o] " "Double Buffering"
			"\n"	"[o] " "Input"
			"\n"	"[o] " "Render Pipe Line"
			"\n"	"[o] " "Scene Node"
			"\n"	"[o] " "Component"
			"\n"	"[o] " "Make Simple Puzzle Game"
		;

		const char* const String4Road2Version_0_0_2 =
					"### Road 2 Version 0.0.2 ###"
			"\n\n"	"[o] " "Texture : Color : 각 문자에 전경, 원경 색상 지정"
			"\n"	"[o] " "Texture : Character : 글자 유효성. 버퍼에 글자를 기록할지 여부"
			"\n"	"[o] " "Render : Color Mask : 전경과 원경의 색상 유효성 처리."
			"\n"	"[o] " "Render : Color Blend"
			"\n"	"[o] " "Audio : 라이브러리 선택 및 테스트( 재생, 중단 등의 기본 사항 )"
			"\n"	"[ ] " "Audio : Pre Load"
			"\n"	"[ ] " "Split The Render And Update Process"
			"\n"	"[ ] " "Node Delete And Caching Pipe Line"
			"\n"	"[ ] " "Make Simple Texture Adventure"

			"\n\n"	"------------------------------------------"

			"\n\n"	"[ ] " "Json"
			"\n"	"[ ] " "Script"
			"\n"	"[ ] " "Texture Viewer"
			"\n"	"[ ] " "Texture Editor"
			"\n"	"[ ] " "Korean"
		;
	} VersionInfo;
}
#pragma once

namespace r2bix
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{
		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '2';


		const char String4Version[15] = { 'r', '2', 'b', 'i', 'x', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };


		const char* const String4Road2Version_0_0_3 =
					"### Road 2 Version 0.0.3 ###"
			"\n"
			"\n"	"[ ] " "Texture Viewer"
			"\n"	"[ ] " "Node Delete And Caching Pipe Line"
			"\n"	"[ ] " "Split Scene Graph Struct And Update Process"
			"\n"	"[ ] " "Make Simple Texture Adventure"

			"\n\n"	"------------------------------------------"

			"\n\n"	"[ ] " "Json"
			"\n"	"[ ] " "Script"
			"\n"	"[ ] " "Texture Editor"
			"\n"	"[ ] " "Korean"
			"\n"	"[ ] " "Audio : Pre Load"
		;

		const char* const String4Road2Version_0_0_2 =
					"### Road 2 Version 0.0.2 ###"
			"\n"
			"\n"	"[o] " "Texture : Color : �� ���ڿ� ����, ���� ���� ����"
			"\n"	"[o] " "Texture : Character : ���� ��ȿ��. ���ۿ� ���ڸ� ������� ����"
			"\n"	"[o] " "Render : Color Mask : ����� ������ ���� ��ȿ�� ó��."
			"\n"	"[o] " "Render : Color Blend"
			"\n"	"[o] " "Audio : ���̺귯�� ���� �� �׽�Ʈ( ���, �ߴ� ���� �⺻ ���� )"
			"\n"	"[o] " "Split The Render And Update Process"
			"\n"	"[o] " "Scheduler : r2bix::Director�� r2::FPSTimer �� std::this_thread::sleep_for( CPU ��뷮 ���� ) ���� ����"
		;

		const char* const String4Road2Version_0_0_1 =
					"### Road 2 Version 0.0.1 ###"
			"\n"
			"\n"	"[o] " "Double Buffering"
			"\n"	"[o] " "Input"
			"\n"	"[o] " "Render Pipe Line"
			"\n"	"[o] " "Scene Node"
			"\n"	"[o] " "Component"
			"\n"	"[o] " "Make Simple Puzzle Game"
		;
	} VersionInfo;
}
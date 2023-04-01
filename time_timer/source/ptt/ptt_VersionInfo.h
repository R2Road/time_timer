#pragma once

namespace ptt
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{
		const char* const String4SubjectAsAProgrammer = {
					"### ������Ʈ ��ǥ | Subject Of A Project ###"
			"\n"
			"\n"	"[o] "    "������ �����͸� �ٷ�� Core ��ü�� �д�"
			"\n"	"[o] "    "Core ��ü�� Singleton�� ������� �ʴ´�"
			"\n"	"[o] "    "Scene �� �Բ� �̵��Ѵ�."
		};



		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '8';

		const char String4Version[19] = { 'T', 'i', 'm', 'e', 'T', 'i', 'm', 'e', 'r', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };



		const char* const String4Road2Version_1_0_8 =
					"### Road 2 Version 1.0.8 ###"
			"\n"
			"\n"	"[o] " "update timer scene : improve key info - show resume key info"
			"\n"	"[o] " "update alram scene : adjust additional time - 5, 10, 15, 20 > 1, 5, 10, 15"
		;

		const char* const String4Road2Version_1_0_7 =
					"### Road 2 Version 1.0.7 ###"
			"\n"
			"\n"	"[o] " "Add Interface 2 Alram Scene :  5�� ��"
			"\n"	"[o] " "Add Interface 2 Alram Scene : 10�� ��"
			"\n"	"[o] " "Add Interface 2 Alram Scene : 15�� ��"
			"\n"	"[o] " "Add Interface 2 Alram Scene : 20�� ��"
		;

	} VersionInfo;
}
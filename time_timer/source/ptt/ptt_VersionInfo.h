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

		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '4';

		const char String4Version[19] = { 'T', 'i', 'm', 'e', 'T', 'i', 'm', 'e', 'r', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4SubjectAsAProgrammer = {
			"### �� ������Ʈ�� ���� ��ǥ | Subject As A Programmer ###"
			"\n"
			"\n"	"1. Core"
			"\n"	"[o] "    "������ �����͸� �ٷ�� Core ��ü�� �д�"
			"\n"	"[o] "    "Core ��ü�� Singleton�� ������� �ʴ´�"
			"\n"	"[o] "    "Director�� �Բ� �� ����� ���� ������ �־��ش�"
			"\n"	"[o] "    "Scene �� �Բ� �̵��Ѵ�."
		};

	} VersionInfo;
}
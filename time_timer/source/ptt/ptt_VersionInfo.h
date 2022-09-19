#pragma once

namespace ptt
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	static struct
	{

		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '4';

		const char String4Version[19] = { 'T', 'i', 'm', 'e', 'T', 'i', 'm', 'e', 'r', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4SubjectAsAProgrammer = {
			"### 이 프로젝트의 실험 목표 | Subject As A Programmer ###"
			"\n"
			"\n"	"1. Core"
			"\n"	"[o] "    "전반의 데이터를 다루는 Core 객체를 둔다"
			"\n"	"[o] "    "Core 객체에 Singleton은 사용하지 않는다"
			"\n"	"[o] "    "Director와 함께 각 노드의 생성 과정에 넣어준다"
			"\n"	"[o] "    "Scene 과 함께 이동한다."
		};

	} VersionInfo;
}
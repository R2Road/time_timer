#pragma once

#include <stdint.h>

#include "r2/r2_SizeInt.h"

namespace r2bix_director
{
	struct Config
	{
		r2::SizeInt ScreenBufferSIze = { 107, 53 };
		const int UpdateFramePerSeconds = 30u;
		const int RenderFramePerSeconds = 30u;

		enum class eScheduleType
		{
			Infinite,
			Sleep,
		};
		const eScheduleType ScheduleType = eScheduleType::Infinite;
	};
}
#pragma once

#include "r2bix/r2bix_director_Config.h"

namespace ptt
{
	const r2bix_director::Config DirectorConfig
	{
		// Screen Buffer Size
		{ 57, 27 }

		// Update FPS
		, 60u

		// Render FPS
		, 30u

		// Schedule Type( Infinite/Sleep )
		, r2bix_director::Config::eScheduleType::Sleep
	};
}
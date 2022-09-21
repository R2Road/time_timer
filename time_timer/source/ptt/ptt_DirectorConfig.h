#pragma once

#include "r2bix/r2bix_director_Config.h"

namespace ptt
{
	const r2bix_director::Config DirectorConfig
	{
		{ 57, 27 } // Screen Buffer Size
		, 60u // Update FPS
		, 30u // Render FPS
		, r2bix_director::Config::eScheduleType::Sleep
	};
}
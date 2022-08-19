#include <stdint.h>

#include "r2/r2_Size_Int.h"

namespace r2base
{
	struct DirectorConfig
	{
		r2::SizeInt ScreenBufferSIze = { 107, 53 };
		const int FramePerSeconds = 30u;
	};
}
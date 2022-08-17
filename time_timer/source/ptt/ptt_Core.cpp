#include "ptt_Core.h"

namespace ptt
{
	CoreUp Core::Create()
	{
		CoreUp ret( new ( std::nothrow ) Core() );
		if( !ret )
		{
			ret.reset();
		}

		return ret;
	}
}
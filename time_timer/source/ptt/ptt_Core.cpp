#include "ptt_Core.h"

#include <algorithm>

namespace ptt
{
	Core::Core() : 
		mMinute_10( 0 )
		, mMinute_1( 0 )
	{}

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
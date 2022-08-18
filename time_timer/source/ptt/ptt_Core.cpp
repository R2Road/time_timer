#include "ptt_Core.h"

#include <algorithm>
#include <new>

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

	void Core::IncreaseMinute10()
	{
		mMinute_10 = std::min( 9, mMinute_10 + 1 );
	}
	void Core::DecreaseMinute10()
	{
		mMinute_10 = std::max( 0, mMinute_10 - 1 );
	}
	void Core::IncreaseMinute1()
	{
		mMinute_1 = std::min( 9, mMinute_1 + 1 );
	}
	void Core::DecreaseMinute1()
	{
		mMinute_1 = std::max( 0, mMinute_1 - 1 );
	}
}
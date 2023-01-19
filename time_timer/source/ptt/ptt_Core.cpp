#include "ptt_Core.h"

#include <algorithm>
#include <new>

namespace ptt
{
	Core::Core() : mRequiredTime()
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

	void Core::RequiredTime::IncreaseMinute10()
	{
		mMinute_10 = std::min( 9, mMinute_10 + 1 );
	}
	void Core::RequiredTime::DecreaseMinute10()
	{
		mMinute_10 = std::max( 0, mMinute_10 - 1 );
	}
	void Core::RequiredTime::IncreaseMinute1()
	{
		mMinute_1 = std::min( 9, mMinute_1 + 1 );
	}
	void Core::RequiredTime::DecreaseMinute1()
	{
		mMinute_1 = std::max( 0, mMinute_1 - 1 );
	}
}
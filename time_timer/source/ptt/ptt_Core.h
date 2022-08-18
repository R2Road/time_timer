#pragma once

#include <memory>

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;
	class Core
	{
	private:
		Core();

	public:
		static CoreUp Create();

		//
		//
		//
		int GetMinute10() const
		{
			return mMinute_10;
		}
		int GetMinute1() const
		{
			return mMinute_1;
		}

	private:
		int mMinute_10;
		int mMinute_1;
	};
}
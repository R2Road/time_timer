#pragma once

#include <memory>

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;
	class Core
	{
	public:
		class RequiredTime
		{
		public:
			RequiredTime() : mMinute_10( 0 ), mMinute_1( 0 )
			{}

			//
			//
			//
			void IncreaseMinute10();
			void DecreaseMinute10();
			void IncreaseMinute1();
			void DecreaseMinute1();

			//
			//
			//
			int GetMinute() const
			{
				return ( mMinute_10 * 10 ) + mMinute_1;
			}
			int GetMinute10() const
			{
				return mMinute_10;
			}
			int GetMinute1() const
			{
				return mMinute_1;
			}
			int GetSeconds() const
			{
				return GetMinute() * 60;
			}

		private:
			int mMinute_10;
			int mMinute_1;
		};

	private:
		Core();

	public:
		static CoreUp Create();

		const RequiredTime& GetRequiredTime() const
		{
			return const_cast<Core*>( this )->GetRequiredTime();;
		}
		RequiredTime& GetRequiredTime()
		{
			return mRequiredTime;
		}

	private:
		RequiredTime mRequiredTime;
	};
}
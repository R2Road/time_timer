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

		class PlayTime
		{
		public:
			PlayTime() : mMinute_10( 0 ), mMinute_1	( 0 )
			{}

			//
			//
			//
			void SetMinute( const int minute_10, const int minute_1 )
			{
				mMinute_10 = minute_10;
				mMinute_1 = minute_1;
			}

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

		const PlayTime& GetPlayTime() const
		{
			return const_cast<Core*>( this )->GetPlayTime();;
		}
		PlayTime& GetPlayTime()
		{
			return mPlayTime;
		}



	private:
		RequiredTime mRequiredTime;
		PlayTime mPlayTime;
	};
}
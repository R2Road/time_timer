#pragma once

#include <stdint.h>

namespace r2base
{
	enum eColorMaskFlag
	{
		CMF_Foreground = 1,
		CMF_Background = 1 << 1,
	};
	class ColorMaskOption
	{
	public:
		ColorMaskOption() : mMaskFlags( CMF_Foreground | CMF_Background ) { updateMask(); }
		ColorMaskOption( const int flags ) : mMaskFlags( flags ) { updateMask(); }

		void On( const eColorMaskFlag flag )
		{
			mMaskFlags |= flag;
			updateMask();
		}
		void Off( const eColorMaskFlag flag )
		{
			mMaskFlags &= ( ~flag );
			updateMask();
		}

		uint8_t GetMask() const { return mMask; }
	private:
		void updateMask()
		{
			mMask = 0;

			if( mMaskFlags & CMF_Foreground )
			{
				static const uint8_t foreground_mask = ( static_cast<uint8_t>( -1 ) >> 4 );
				mMask |= foreground_mask;
			}
			if( mMaskFlags & CMF_Background )
			{
				static const uint8_t background_mask = ( ( static_cast<uint8_t>( -1 ) >> 4 ) << 4 );
				mMask |= background_mask;
			}
		}

	private:
		uint32_t mMaskFlags;
		uint8_t mMask;
	};
}
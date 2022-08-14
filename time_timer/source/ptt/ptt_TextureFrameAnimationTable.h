#pragma once

#include "r2cm/r2cm_Singleton.h"
#include "r2bix/r2base_TextureFrameAnimationTableBase.h"

namespace ptt
{
	class TextureFrameAnimationTable : public r2base::TextureFrameAnimationTableBase, public r2cm::SingleTon<TextureFrameAnimationTable>
	{
	public:
		void Load() override;
	};
}
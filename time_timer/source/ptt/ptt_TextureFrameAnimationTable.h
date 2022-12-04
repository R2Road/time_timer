#pragma once

#include "r2/r2_SingletonWithStaticVariable.h"
#include "r2bix/r2base_TextureFrameAnimationTableBase.h"

namespace ptt
{
	class TextureFrameAnimationTable : public r2base::TextureFrameAnimationTableBase, public r2::SingletonWithStaticVariable<TextureFrameAnimationTable>
	{
	public:
		void Load() override;
	};
}
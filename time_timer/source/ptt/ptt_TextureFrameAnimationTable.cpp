#include "ptt_TextureFrameAnimationTable.h"

#include <utility>

#include "ptt_TextureTable.h"

namespace ptt
{
	void TextureFrameAnimationTable::Load()
	{
		if( !mContainer.empty() )
		{
			return;
		}

		r2base::TextureFrameAnimationInfo::Animation animation;
		r2base::TextureFrameAnimationInfo::AnimationPackageT animation_package;

		//
		//
		//
		{
			// Number
			{
				animation.Index = r2animation::eIndex::Idle_1;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_0" ) } );
				animation_package.push_back( std::move( animation ) );
			}

			mContainer.emplace( 1, std::move( animation_package ) );
		}
	}
}
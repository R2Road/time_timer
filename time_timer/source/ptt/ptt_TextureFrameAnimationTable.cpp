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
		// Number
		//
		{
			{
				animation.Index = r2animation::eIndex::Idle_0;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_0" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_1;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_1" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_2;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_2" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_3;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_3" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_4;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_4" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_5;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_5" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_6;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_6" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_7;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_7" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_8;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_8" ) } );
				animation_package.push_back( std::move( animation ) );

				animation.Index = r2animation::eIndex::Idle_9;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.f, TextureTable::GetInstance().GetTextureFrame( "number_9" ) } );
				animation_package.push_back( std::move( animation ) );
			}

			mContainer.emplace( 1, std::move( animation_package ) );
		}

		//
		// Indicator Up
		//
		{
			{
				animation.Index = r2animation::eIndex::Idle_0;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_up_0" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_up_1" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_up_2" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_up_3" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_up_4" ) } );
				animation_package.push_back( std::move( animation ) );
			}

			mContainer.emplace( 2, std::move( animation_package ) );
		}

		//
		// Indicator Down
		//
		{
			{
				animation.Index = r2animation::eIndex::Idle_0;
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_down_0" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_down_1" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_down_2" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_down_3" ) } );
				animation.Container.push_back( r2base::TextureFrameAnimationInfo::AnimationFrame{ 0.2f, TextureTable::GetInstance().GetTextureFrame( "indicator_down_4" ) } );
				animation_package.push_back( std::move( animation ) );
			}

			mContainer.emplace( 3, std::move( animation_package ) );
		}
	}
}
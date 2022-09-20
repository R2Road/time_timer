#include "r2component_TextureFrameAnimationComponent.h"

#include "r2component_TextureFrameRenderComponent.h"

namespace r2component
{
	TextureFrameAnimationComponent::TextureFrameAnimationComponent( r2base::Node& owner_node ) : r2base::Component<TextureFrameAnimationComponent>( owner_node )
		, mTextureFrameRenderComponent( nullptr )

		, mbRepeat( false )
		, mAnimationPackage()
		, mCurrentAnimation( mAnimationPackage.end() )
		, mCurrentAnimationFrameIndex( 0u )
	{}

	void TextureFrameAnimationComponent::Update( const float delta_time )
	{
		if( mAnimationPackage.end() == mCurrentAnimation )
		{
			return;
		}

		if( mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Timer.Update( delta_time ) )
		{
			return;
		}

		if( mCurrentAnimation->Container.size() > mCurrentAnimationFrameIndex + 1u )
		{
			mCurrentAnimationFrameIndex = mCurrentAnimationFrameIndex + 1u;
			mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Timer.Start();
			mTextureFrameRenderComponent->SetTextureFrame( mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Frame );
		}
		else
		{
			if( mbRepeat )
			{
				mCurrentAnimationFrameIndex = 0u;
				mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Timer.Start();
				mTextureFrameRenderComponent->SetTextureFrame( mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Frame );
			}
			else
			{
				mCurrentAnimation = mAnimationPackage.end();
			}
		}
	}

	void TextureFrameAnimationComponent::LoadAnimation( const r2base::TextureFrameAnimationInfo& info )
	{
		StopAnimation();

		Animation animation;
		for( const auto& a : info.Get() )
		{
			animation.Index = a.Index;

			for( const auto& f : a.Container )
			{
				animation.Container.push_back( AnimationFrame{ { f.TimeLimit, true }, f.Frame } );
			}

			mAnimationPackage.emplace_back( std::move( animation ) );
		}

		mCurrentAnimation = mAnimationPackage.end();
	}
	bool TextureFrameAnimationComponent::HasAnimation( const r2animation::eIndex animation_index ) const
	{
		for( const auto& a : mAnimationPackage )
		{
			if( animation_index == a.Index )
			{
				return true;
			}
		}

		return false;
	}
	void TextureFrameAnimationComponent::RunAnimation_Once( const r2animation::eIndex animation_index )
	{
		StopAnimation();

		for( auto cur = mAnimationPackage.begin(), end = mAnimationPackage.end(); end != cur; ++cur )
		{
			if( animation_index == cur->Index )
			{
				mbRepeat = false;
				mCurrentAnimation = cur;
				mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Timer.Start();
				mTextureFrameRenderComponent->SetTextureFrame( mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Frame );
				break;
			}
		}
	}
	void TextureFrameAnimationComponent::RunAnimation_Repeat( const r2animation::eIndex animation_index )
	{
		StopAnimation();

		for( auto cur = mAnimationPackage.begin(), end = mAnimationPackage.end(); end != cur; ++cur )
		{
			if( animation_index == cur->Index )
			{
				mbRepeat = true;
				mCurrentAnimation = cur;
				mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Timer.Start();
				mTextureFrameRenderComponent->SetTextureFrame( mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Frame );
				break;
			}
		}
	}
	void TextureFrameAnimationComponent::StopAnimation()
	{
		mbRepeat = false;
		if( mAnimationPackage.end() != mCurrentAnimation )
		{
			mCurrentAnimation->Container[mCurrentAnimationFrameIndex].Timer.Stop();
		}
		mCurrentAnimation = mAnimationPackage.end();
		mCurrentAnimationFrameIndex = 0u;
	}

	const r2animation::eIndex TextureFrameAnimationComponent::GetCurrentAnimationIndex() const
	{
		if( mAnimationPackage.end() == mCurrentAnimation )
		{
			return r2animation::eIndex::None;
		}

		return mCurrentAnimation->Index;
	}
}
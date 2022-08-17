#pragma once

#include "r2bix/r2base_Component.h"

namespace r2component
{
	class TextureFrameAnimationComponent;
}

namespace ptt
{
	class NumberComponent : public r2base::Component<NumberComponent>
	{
	public:
		NumberComponent( r2base::Node& owner_node );

		//
		//
		//
		r2component::TextureFrameAnimationComponent* const GetTextureFrameAnimationComponent() const
		{
			return mTextureFrameAnimationComponent;
		}
		void SetTextureFrameAnimationComponent( r2component::TextureFrameAnimationComponent* const texture_frame_animation_component )
		{
			mTextureFrameAnimationComponent = texture_frame_animation_component;
		}
		void SetNumber( const int new_number );

	private:
		r2component::TextureFrameAnimationComponent* mTextureFrameAnimationComponent;
	};
}
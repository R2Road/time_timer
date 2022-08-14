#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2base_ComponentStaticID.h"

namespace r2component
{
	class TextureFrameAnimationComponent;
}

namespace ptt
{
	class NumberComponent : public r2base::Component
	{
	private:
		NumberComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<NumberComponent>::Get(); }
		static std::unique_ptr<NumberComponent> Create( r2base::Node& owner_node );

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
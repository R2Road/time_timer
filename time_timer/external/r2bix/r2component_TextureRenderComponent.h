#pragma once

#include "r2base_Component.h"

#include "r2base_ColorMaskOption.h"

#include "r2/r2_PointFloat.h"
#include "r2/r2_RectInt.h"

namespace r2render
{
	class Texture;
}

namespace r2component
{
	class TextureRenderComponent : public r2base::Component<TextureRenderComponent>
	{
	public:
		TextureRenderComponent( r2base::Node& owner_node );

		//
		// Override
		//
		void Render( const r2render::Camera* const camera, r2render::iRenderTarget* const render_target, r2::PointInt offset ) override;

		//
		// Getter
		//
		const r2render::Texture* const GetTexture() const
		{
			return mTexture;
		}
		r2::RectInt GetRect() const
		{
			return mVisibleRect;
		}

		//
		// Setter
		//
		void SetPivotPoint( const float x, const float y );
		void SetTexture( const r2render::Texture* const texture );
		void ResetVisibleRect();
		void SetVisibleRectForced( const int x, const int y, const int width, const int height )
		{
			mVisibleRect.Set( x, y, width, height );
		}
		void MoveRectOrigin( const int move_x, const int move_y )
		{
			mVisibleRect.MoveOrigin( move_x, move_y );
		}

	private:
		r2::PointFloat mPivotPoint;
		r2::RectInt mVisibleRect;
		const r2render::Texture* mTexture;
		r2base::ColorMaskOption mColorMaskOption;
	};
}
#include "r2component_TextureFrameRenderComponent.h"

#include "r2base_DebugConfig.h"
#include "r2base_Node.h"
#include "r2component_TransformComponent.h"
#include "r2render_Camera.h"
#include "r2render_TextureFrame.h"

namespace r2component
{
	TextureFrameRenderComponent::TextureFrameRenderComponent( r2base::Node& owner_node ) : r2base::Component<TextureFrameRenderComponent>( owner_node )
		, mPivotPoint( 0.5f, 0.5f )
		, mVisibleRect()
		, mTextureFrame( nullptr )
		, mColorMaskOption( r2base::eColorMaskFlag::CMF_Foreground | r2base::eColorMaskFlag::CMF_Background )
	{}

	void TextureFrameRenderComponent::Render( const r2render::Camera* const camera, r2render::iRenderTarget* const render_target, r2::PointInt offset )
	{
		if( nullptr == mTextureFrame )
		{
			return;
		}

		//
		// World Space : My Rect : Test
		//
		{
			const r2::RectInt my_world_space_rect( offset + mVisibleRect.GetOrigin() + mOwnerNode.mTransformComponent->GetPosition(), mVisibleRect.GetSize() );
			if( !my_world_space_rect.IntersectsRect( camera->GetRect() ) )
			{
				return;
			}
		}

		//
		// Camera Space : My Position
		//
		const auto camera_space_my_position = offset + mOwnerNode.mTransformComponent->GetPosition() - camera->GetPoint();

		//
		// Render Target Space : My Position
		//
		const auto render_target_space_my_position = camera_space_my_position - camera->GetCameraSpaceRect().GetOrigin();

		//
		// Render Target Space : My Rect
		//
		auto render_target_space_my_rect = mVisibleRect;
		render_target_space_my_rect.MoveOrigin( render_target_space_my_position.GetX(), render_target_space_my_position.GetY() );

		//
		// Render Target Space : Intersect Rect
		//
		auto render_target_space_intersect_rect = render_target->GetRect().IntersectsWithRect( render_target_space_my_rect );

		//
		// Offset
		//
		const auto off_set_point = render_target_space_intersect_rect.GetOrigin() - render_target_space_my_rect.GetOrigin();
		for( int y = render_target_space_intersect_rect.GetMinY(), ty = 0; render_target_space_intersect_rect.GetMaxY() >= y; ++y, ++ty )
		{
			for( int x = render_target_space_intersect_rect.GetMinX(), tx = 0; render_target_space_intersect_rect.GetMaxX() >= x; ++x, ++tx )
			{
				if( !mTextureFrame->GetCharacterDisuse( off_set_point.GetX() + tx, off_set_point.GetY() + ty ) )
				{
					render_target->FillCharacter(
						x, y
						, mTextureFrame->GetCharacter( off_set_point.GetX() + tx, off_set_point.GetY() + ty )
					);
				}

				render_target->FillColorWithMask(
					x, y
					, mTextureFrame->GetColor( off_set_point.GetX() + tx, off_set_point.GetY() + ty )
					, mColorMaskOption
				);
			}
		}

		//
		// Debug
		//
		if( r2base::DebugConfig::GetLabelConfig().bShowPositionPivot )
		{
			render_target->FillCharacter( render_target_space_my_position.GetX(), render_target_space_my_position.GetY(), '+' );
		}
	}

	void TextureFrameRenderComponent::SetPivotPoint( const float x, const float y )
	{
		mPivotPoint.Set( x, y );

		resetVisibleRect();
	}
	void TextureFrameRenderComponent::SetTextureFrame( const r2render::TextureFrame* const texture_frame )
	{
		mTextureFrame = texture_frame;

		resetVisibleRect();
	}
	void TextureFrameRenderComponent::resetVisibleRect()
	{
		if( !mTextureFrame )
		{
			return;
		}

		mVisibleRect.Set(
			-static_cast<int>( mTextureFrame->GetWidth() * mPivotPoint.GetX() )
			, -static_cast<int>( mTextureFrame->GetHeight() * mPivotPoint.GetY() )
			, mTextureFrame->GetVisibleRect().GetSize().GetWidth()
			, mTextureFrame->GetVisibleRect().GetSize().GetHeight()
		);
	}
}
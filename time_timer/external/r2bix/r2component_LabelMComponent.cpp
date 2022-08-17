#include "r2component_LabelMComponent.h"

#include "r2component_CustomTextureComponent.h"
#include "r2component_TextureRenderComponent.h"

namespace r2component
{
	LabelMComponent::LabelMComponent( r2base::Node& owner_node ) : r2base::Component<LabelMComponent>( owner_node )
		, mCustomTextureComponent( nullptr )
		, mTextureRenderComponent( nullptr )
		, mColorValue( r2base::eForegroundColor::FG_White | r2base::eBackgroundColor::BG_Black )
	{}

	void LabelMComponent::SetString( const std::string_view str )
	{
		if( mText == str )
		{
			return;
		}

		mText = str;

		if( mCustomTextureComponent )
		{
			mCustomTextureComponent->GetTexture()->Reset( str );
			mCustomTextureComponent->GetTexture()->FillColorAll( mColorValue );
		}

		if( mTextureRenderComponent )
		{
			mTextureRenderComponent->ResetVisibleRect();
		}
	}
	void LabelMComponent::SetColor( const r2base::ColorValue color_value )
	{
		if( color_value == mColorValue )
		{
			return;
		}

		mColorValue = color_value;

		if( mCustomTextureComponent )
		{
			mCustomTextureComponent->GetTexture()->FillColorAll( mColorValue );
		}
	}
}
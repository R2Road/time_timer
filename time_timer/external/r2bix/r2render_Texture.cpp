#include "r2render_Texture.h"

#include <algorithm>
#include <cassert>

#include "r2utility_StringSize.h"
#include "r2utility_StringDecomposition.h"

namespace r2render
{
	Texture::Texture( const std::string_view str ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
		, mColors()
		, mCharDisuses()
	{
		Reset( str );
	}
	Texture::Texture( const uint32_t width, const std::string_view str ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
		, mColors()
		, mCharDisuses()
	{
		Reset( width, str );
	}
	Texture::Texture( const uint32_t width, uint32_t height ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
		, mColors()
		, mCharDisuses()
	{
		Reset( width, height, 32 );
	}
	Texture::Texture( const uint32_t width, const uint32_t height, const char fill_char ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
		, mColors()
		, mCharDisuses()
	{
		Reset( width, height, fill_char );
	}
	Texture::Texture( const uint32_t width, const uint32_t height, const char fill_char, const r2base::ColorValue color_value ) :
		mGridIndexConverter( 1, 1 )
		, mChars()
		, mColors()
		, mCharDisuses()
	{
		Reset( width, height, fill_char, color_value );
	}
	Texture::Texture( const uint32_t width, const uint32_t height, const std::string_view str ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, 32 )
		, mColors( width * height, r2base::DefaultColorValue )
		, mCharDisuses( width * height, false )
	{
		assert( 0u < width && 0u < height );
		memcpy_s( &mChars[0], mChars.size(), str.data(), std::min( str.size(), mChars.size() ) );
	}
	Texture::Texture( const uint32_t width, uint32_t height, const char fill_char, const std::string_view str ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, fill_char )
		, mColors( width * height, r2base::DefaultColorValue )
		, mCharDisuses( width * height, false )
	{
		assert( 0u < width && 0u < height );
		memcpy_s( &mChars[0], mChars.size(), str.data(), std::min( str.size(), mChars.size() ) );
	}

	Texture::ValueT Texture::GetCharacter( const uint32_t x, const uint32_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		return mChars[target_linear_index];
	}
	std::string_view Texture::GetCharacterLine( const uint32_t y ) const
	{
		std::string_view temp( &mChars[0] );
		return temp.substr( mGridIndexConverter.To_Linear( 0, y ), mGridIndexConverter.GetWidth() );
	}

	r2base::ColorValue Texture::GetColor( const uint32_t x, const uint32_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );
		return mColors[target_linear_index];
	}
	const r2base::ColorValue* Texture::GetColorLine( const uint32_t y ) const
	{
		return &mColors[mGridIndexConverter.To_Linear( 0, y )];
	}

	bool Texture::GetCharacterDisuse( const uint32_t x, const uint32_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );
		return mCharDisuses[target_linear_index];
	}

	void Texture::Reset( const std::string_view str )
	{
		const auto size = r2utility::StringSize::Calculate( str );
		const auto str_list = r2utility::StringDecomposition::Do( "\n", str );

		Reset( static_cast<uint32_t>( size.width ), static_cast<uint32_t>( size.height ), ' ' );

		int current_y = 0;
		int linear_index = 0;
		for( const auto& s : str_list )
		{
			linear_index = mGridIndexConverter.To_Linear( 0, current_y );
			memcpy_s( &mChars[linear_index], mGridIndexConverter.GetWidth(), s.data(), s.size() );

			++current_y;
		}
	}
	void Texture::Reset( const uint32_t width, const std::string_view str )
	{
		assert( 0u < width && 0u < str.length() );

		mGridIndexConverter = r2::GridIndexConverter( width, static_cast<int>( str.length() < 0 ? 1 : ( str.length() / width ) + ( str.length() % width < 1 ? 0 : 1 ) ) );

		//
		// Chars
		//
		mChars.clear();
		mChars.resize( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), 32 );
		memcpy_s( &mChars[0], mChars.size(), str.data(), str.size() );

		//
		// Color
		//
		mColors.clear();
		mColors.resize( mChars.size(), r2base::DefaultColorValue );

		//
		// Disuse
		//
		mCharDisuses.clear();
		mCharDisuses.resize( mChars.size(), false );
	}
	void Texture::Reset( const uint32_t width, const uint32_t height, const char fill_char )
	{
		Reset( width, height, fill_char, r2base::DefaultColorValue );
	}
	void Texture::Reset( const uint32_t width, const uint32_t height, const char fill_char, const r2base::ColorValue color_value )
	{
		assert( 0u < width && 0u < height );

		mGridIndexConverter = r2::GridIndexConverter( width, height );

		//
		// Chars
		//
		mChars.clear();
		mChars.resize( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), fill_char );

		//
		// Color
		//
		mColors.clear();
		mColors.resize( mChars.size(), color_value );

		//
		// Disuse
		//
		mCharDisuses.clear();
		mCharDisuses.resize( mChars.size(), false );
	}

	void Texture::FillCharacterAll( const char c )
	{
		memset( &mChars[0], c, mChars.size() );
	}

	void Texture::FillCharacter( const uint32_t x, const uint32_t y, const char c )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mChars[target_linear_index] = c;
	}

	void Texture::FillColorAll( const r2base::ColorValue color_value )
	{
		std::fill( mColors.begin(), mColors.end(), color_value );
	}

	void Texture::FillColor( const uint32_t x, const uint32_t y, const r2base::ColorValue color_value )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mColors[target_linear_index] = color_value;
	}

	void Texture::FillColorWithMask( const uint32_t x, const uint32_t y, const r2base::ColorValue color_value, const r2base::ColorMaskOption color_mask_option )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mColors[target_linear_index] = ( 
				( static_cast<uint8_t>( mColors[target_linear_index] ) & static_cast<uint8_t>( ~color_mask_option.GetMask() ) )
			|	( color_value & color_mask_option.GetMask() )
		);
	}

	void Texture::BlendColor( const uint32_t x, const uint32_t y, const r2base::ColorValue color_value )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mColors[target_linear_index] |= color_value;
	}

	void Texture::FillCharacterDisuse( const uint32_t x, const uint32_t y, const bool disuse )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mCharDisuses[target_linear_index] = disuse;
	}
}
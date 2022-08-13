#pragma once

#include <string_view>

namespace r2utility
{
	class StringSize
	{
	public:
		struct Size
		{
			std::size_t width = 0u;
			std::size_t height = 0u;
		};

	private:
		StringSize() = delete;

	public:
		static const Size Calculate( const std::string_view str );
	};
}

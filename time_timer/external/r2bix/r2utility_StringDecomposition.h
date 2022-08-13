#pragma once

#include <list>
#include <string_view>

namespace r2utility
{
	class StringDecomposition
	{
	public:
		using ResultContainerT = std::list<std::string_view>;

	private:
		StringDecomposition() = delete;

	public:
		static ResultContainerT Do( const std::string_view token, const std::string_view str );
	};
}

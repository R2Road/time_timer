#include "r2utility_StringDecomposition.h"

namespace r2utility
{
	StringDecomposition::ResultContainerT StringDecomposition::Do( const std::string_view token, const std::string_view str )
	{
		ResultContainerT out_container;

		if( !str.empty() )
		{
			std::size_t pivot_pos = 0u;
			std::size_t find_pos = 0u;
			std::size_t fixed_find_pos = 0u;

			do
			{

				find_pos = str.find( token, pivot_pos );
				if( std::string::npos == find_pos )
				{
					fixed_find_pos = str.size();
				}
				else
				{
					fixed_find_pos = find_pos;
				}

				//
				//
				//
				out_container.push_back( str.substr( pivot_pos, fixed_find_pos - pivot_pos ) );

				pivot_pos = fixed_find_pos + 1u;

			} while( std::string::npos != find_pos && pivot_pos <= str.size() );
		}

		return out_container;
	}
}
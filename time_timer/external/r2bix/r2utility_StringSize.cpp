#include "r2utility_StringSize.h"

namespace r2utility
{
	const StringSize::Size StringSize::Calculate( const std::string_view str )
	{
		Size out_ret{ 0u, 0u };

		if( !str.empty() )
		{
			const char* key_string = "\n";

			std::size_t pivot_pos = 0u;
			std::size_t find_pos = 0u;
			std::size_t fixed_find_pos = 0u;

			do
			{

				find_pos = str.find( key_string, pivot_pos );
				if( std::string::npos == find_pos )
				{
					fixed_find_pos = str.size();
				}
				else
				{
					fixed_find_pos = find_pos;
				}

				if( fixed_find_pos - pivot_pos > out_ret.width )
				{
					out_ret.width = fixed_find_pos - pivot_pos;
				}

				pivot_pos = fixed_find_pos + 1u;
				++out_ret.height;

			} while( std::string::npos != find_pos && pivot_pos <= str.size() );
		}

		return out_ret;
	}
}
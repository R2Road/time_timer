#pragma once

#include "r2bix/r2base_Component.h"

namespace ptt
{
	class SecondsComponent : public r2base::Component<SecondsComponent>
	{
	public:
		SecondsComponent( r2base::Node& owner_node );

		void Toggle( const int64_t seconds );

	private:
		bool mbFlag;
	};
}
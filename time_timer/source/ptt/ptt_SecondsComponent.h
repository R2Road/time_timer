#pragma once

#include "r2bix/r2base_Component.h"

namespace ptt
{
	class SecondsComponent : public r2base::Component<SecondsComponent>
	{
	public:
		SecondsComponent( r2base::Node& owner_node );

		void Toggle( const bool new_flag );

	private:
		bool mbFlag;
	};
}
#pragma once

#include "r2bix/r2base_Node.h"

namespace ptt
{
	class SelectIndicatorNode : public r2base::Node
	{
	private:
		SelectIndicatorNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}
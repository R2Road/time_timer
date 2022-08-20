#pragma once

#include "r2bix/r2base_Node.h"

namespace ptt
{
	class IndicatorNode : public r2base::Node
	{
	private:
		IndicatorNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}
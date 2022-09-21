#pragma once

#include "r2bix/r2base_Node.h"

namespace ptt
{
	class PauseIndicatorNode : public r2base::Node
	{
	private:
		PauseIndicatorNode() = delete;

	public:
		static r2base::NodeUp Create( r2bix::Director& director );
	};
}
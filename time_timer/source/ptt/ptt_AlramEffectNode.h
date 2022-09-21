#pragma once

#include "r2bix/r2base_Node.h"

namespace ptt
{
	class AlramEffectNode : public r2base::Node
	{
	private:
		AlramEffectNode() = delete;

	public:
		static r2base::NodeUp Create( r2bix::Director& director );
	};
}
#pragma once

#include "r2bix/r2base_Node.h"

namespace ptt
{
	class ChangeIndicatorNode : public r2base::Node
	{
	private:
		ChangeIndicatorNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}
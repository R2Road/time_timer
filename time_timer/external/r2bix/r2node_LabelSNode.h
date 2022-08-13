#pragma once

#include "r2base_Node.h"

namespace r2base
{
	class Director;
}

namespace r2node
{
	class LabelSNode : public r2base::Node
	{
	private:
		LabelSNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}
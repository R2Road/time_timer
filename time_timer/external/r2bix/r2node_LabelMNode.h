#pragma once

#include "r2base_Node.h"

namespace r2base
{
	class Director;
}

namespace r2node
{
	class LabelMNode : public r2base::Node
	{
	private:
		LabelMNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}
#pragma once

#include "r2bix/r2base_Node.h"

namespace ptt
{
	class MinuteNode : public r2base::Node
	{
	private:
		MinuteNode() = delete;

	public:
		static r2base::NodeUp Create( r2base::Director& director );
	};
}
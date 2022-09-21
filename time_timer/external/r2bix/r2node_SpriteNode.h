#pragma once

#include "r2base_Node.h"

namespace r2bix
{
	class Director;
}

namespace r2node
{
	class SpriteNode : public r2base::Node
	{
	private:
		SpriteNode() = delete;

	public:
		static r2base::NodeUp Create( r2bix::Director& director );
	};
}
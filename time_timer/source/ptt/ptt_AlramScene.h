#pragma once

#include "r2bix/r2node_SceneNode.h"

namespace ptt
{
	class AlramScene : public r2node::SceneNode
	{
	private:
		AlramScene() = delete;

	public:
		static r2node::SceneNodeUp Create( r2base::Director& director );
	};
}
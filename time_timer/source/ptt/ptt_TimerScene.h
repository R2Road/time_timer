#pragma once

#include "r2bix/r2node_SceneNode.h"

namespace ptt
{
	class GameScene : public r2node::SceneNode
	{
	private:
		GameScene() = delete;

	public:
		static r2node::SceneNodeUp Create( r2base::Director& director );
	};
}
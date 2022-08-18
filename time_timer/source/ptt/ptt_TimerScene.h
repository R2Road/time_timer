#pragma once

#include "r2bix/r2node_SceneNode.h"

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;

	class TimerScene : public r2node::SceneNode
	{
	private:
		TimerScene() = delete;

	public:
		static r2node::SceneNodeUp Create( r2base::Director& director, CoreUp&& core );
	};
}
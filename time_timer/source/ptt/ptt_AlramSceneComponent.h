#pragma once

#include "r2bix/r2base_Component.h"

namespace ptt
{
	using CoreUp = std::unique_ptr<class Core>;

	class AlramSceneComponent : public r2base::Component<AlramSceneComponent>
	{
	public:
		AlramSceneComponent( r2base::Node& owner_node );

		//
		//
		//
		void SetCore( CoreUp&& core );

	private:
		CoreUp mCore;
	};
}
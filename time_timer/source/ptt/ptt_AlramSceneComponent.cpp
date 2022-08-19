#include "ptt_AlramSceneComponent.h"

#include <utility>

#include "r2/r2_Assert.h"

#include "r2bix/r2base_Director.h"

#include "ptt_Core.h"

namespace ptt
{
	AlramSceneComponent::AlramSceneComponent( r2base::Node& owner_node ) : r2base::Component<AlramSceneComponent>( owner_node )
		, mCore()
	{}

	void AlramSceneComponent::SetCore( CoreUp&& core )
	{
		R2ASSERT( nullptr == mCore, "" );
		R2ASSERT( nullptr != core, "" );

		mCore = std::move( core );
	}
}
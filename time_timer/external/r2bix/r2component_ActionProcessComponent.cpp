#include "r2component_ActionProcessComponent.h"

namespace r2component
{
	ActionProcessComponent::ActionProcessComponent( r2base::Node& owner_node ) : r2base::Component<ActionProcessComponent>( owner_node )
		, mAction()
		, mbStart( false )
	{}

	void ActionProcessComponent::StartAction()
	{
		mbStart = ( nullptr != mAction );
		if( mbStart )
		{
			mAction->SetOwnerNode( &mOwnerNode );
			mAction->Enter();
		}
	}

	void ActionProcessComponent::Update( const float delta_time )
	{
		if( !mbStart )
		{
			return;
		}

		mbStart = mAction->Update( delta_time );
	}
}
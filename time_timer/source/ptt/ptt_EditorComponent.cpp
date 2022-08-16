#include "ptt_EditorComponent.h"

#include <new>

namespace ptt
{
	EditorComponent::EditorComponent( r2base::Node& owner_node ) : r2base::Component( owner_node )
	{}

	EditorComponent::MyUniquePtrT EditorComponent::Create( r2base::Node& owner_node )
	{
		MyUniquePtrT ret( new ( std::nothrow ) EditorComponent( owner_node ) );
		if( !ret || !ret->Init() )
		{
			ret.reset();
		}

		return ret;
	}
}
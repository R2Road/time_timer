#pragma once

#include "r2base_iComponent.h"
#include "r2base_ComponentStaticID.h"

namespace r2base
{
	template<typename T>
	class Component : public iComponent
	{
	public:
		using MyT = T;

	protected:
		Component( r2base::Node& owner_node ) : r2base::iComponent( owner_node ) {}

	public:
		static std::unique_ptr<MyT> Create( r2base::Node& owner_node )
		{
			std::unique_ptr<MyT> ret( new ( std::nothrow ) MyT( owner_node ) );
			if( !ret || !ret->Init() )
			{
				ret.reset();
			}

			return ret;
		}

		int GetStaticID() const override { return r2base::ComponentStaticID<MyT>::Get(); }
	};
}
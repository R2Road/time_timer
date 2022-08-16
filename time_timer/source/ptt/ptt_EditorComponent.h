#pragma once

#include "r2bix/r2base_Component.h"
#include "r2bix/r2base_ComponentStaticID.h"
#include "r2bix/r2input_KeyboardInputListener.h"

namespace ptt
{
	class EditorComponent : public r2base::Component
	{
	public:
		using MyT = EditorComponent;
		using MyUniquePtrT = std::unique_ptr<MyT>;

	private:
		EditorComponent( r2base::Node& owner_node );

	public:
		int GetStaticID() const override { return r2base::ComponentStaticID<MyT>::Get(); }
		static MyUniquePtrT Create( r2base::Node& owner_node );

	public:
		void Update( const float delta_time ) override;

	private:
		r2input::KeyboardInputListener mKeyboardInputListener;
	};
}
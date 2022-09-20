#pragma once

#include <memory>

#include "r2/r2_PointInt.h"

namespace r2render
{
	class Camera;
	class iRenderTarget;
}

namespace r2base
{
	class Node;

	using ComponentUp = std::unique_ptr<class iComponent>;
	class iComponent
	{
	protected:
		iComponent( Node& owner_node ) : mOwnerNode( owner_node ) {}
	public:
		virtual ~iComponent() {}

	public:
		Node& GetOwnerNode() const { return mOwnerNode; }

		virtual int GetStaticID() const = 0;
		virtual bool Init() { return true; }
		virtual void Update( const float /*delta_time*/ ) {}
		virtual void Render( const r2render::Camera* const /*camera*/, r2render::iRenderTarget* const /*render_target*/, r2::PointInt /*offset*/ ) {}

	protected:
		Node& mOwnerNode;
	};
}
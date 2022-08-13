#include "ptt_NumberNode.h"

#include <numeric>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2component_TextureFrameRenderComponent.h"

#include "ptt/ptt_TextureTable.h"

namespace ptt
{
	r2base::NodeUp NumberNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddComponent<r2component::TextureFrameRenderComponent>();
		}

		return ret;
	}
}
#include "ptt_MinuteNode.h"

#include "ptt_NumberNode.h"

namespace ptt
{
	r2base::NodeUp MinuteNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{
			ret->AddChild<ptt::NumberNode>();
			ret->AddChild<ptt::NumberNode>();
		}

		return ret;
	}
}
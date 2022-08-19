#include "ptt_SecondsNode.h"

#include <cmath>

#include "r2bix/r2node_PivotNode.h"

#include "ptt_Config.h"

namespace ptt
{
	r2base::NodeUp SecondsNode::Create( r2base::Director& director )
	{
		auto ret( r2base::Node::Create( director ) );
		if( ret )
		{

			//
			//
			//
			if( ptt::Config::GetNodeConfig().pivot )
			{
				ret->AddChild<r2node::PivotNode>();
			}

		}

		return ret;
	}
}
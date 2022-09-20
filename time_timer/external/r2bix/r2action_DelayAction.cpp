#include "r2action_DelayAction.h"

#include "r2base_Node.h"

namespace r2action
{
	DelayAction::DelayAction() :
		mTimer( 1.f )
	{}

	std::unique_ptr<DelayAction> DelayAction::Create()
	{
		std::unique_ptr<DelayAction> ret( new ( std::nothrow ) DelayAction() );
		return ret;
	}

	void DelayAction::Enter()
	{
		mTimer.Start();
	}
	bool DelayAction::Update( const float delta_time )
	{
		mTimer.Update( delta_time );

		return mTimer.IsAlive();
	}
}
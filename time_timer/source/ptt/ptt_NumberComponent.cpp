#include "ptt_NumberComponent.h"

#include "r2/r2_Assert.h"
#include "r2bix/r2component_TextureFrameAnimationComponent.h"

namespace ptt
{
	NumberComponent::NumberComponent( r2base::Node& owner_node ) : r2base::Component<NumberComponent>( owner_node )
		, mTextureFrameAnimationComponent( nullptr )
	{}

	void NumberComponent::SetNumber( const int new_number )
	{
		R2ASSERT( nullptr != mTextureFrameAnimationComponent, "" );

		switch( new_number )
		{
		case 0:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_0 );
			break;
		case 1:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_1 );
			break;
		case 2:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_2 );
			break;
		case 3:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_3 );
			break;
		case 4:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_4 );
			break;
		case 5:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_5 );
			break;
		case 6:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_6 );
			break;
		case 7:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_7 );
			break;
		case 8:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_8 );
			break;
		case 9:
			mTextureFrameAnimationComponent->RunAnimation_Once( r2animation::eIndex::Idle_9 );
			break;

		default:
			R2ASSERT( false, "" );
		}
	}
}
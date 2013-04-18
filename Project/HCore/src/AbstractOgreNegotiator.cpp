#include <AbstractOgreNegotiator.h>
#include <OgreMediator.h>

void AbstractOgreNegotiator::notifyMediator(NegotiatorEvent& mediatorEvent){
	mMediator->onOgreChanged(this, mediatorEvent);
}
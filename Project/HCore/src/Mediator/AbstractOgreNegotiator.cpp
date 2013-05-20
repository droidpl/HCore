#include <Mediator/AbstractOgreNegotiator.h>
#include <Mediator/OgreMediator.h>

void AbstractOgreNegotiator::notifyMediator(NegotiatorEvent& mediatorEvent){
	if (mMediator != NULL) mMediator->onOgreChanged(this, mediatorEvent);
}
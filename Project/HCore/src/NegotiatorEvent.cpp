#include <NegotiatorEvent.h>

NegotiatorEvent::NegotiatorEvent(string id, string message){
	mId = id;
	mMessage = message;
}

bool NegotiatorEvent::matchEvent(string eventId){
	return mId.compare(eventId) == 0;
}
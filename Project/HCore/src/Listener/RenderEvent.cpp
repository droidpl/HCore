#include <Listener/RenderEvent.h>

RenderEvent::RenderEvent(float timeSinceLastEvent, float timeSinceLastFrame){
	mTimeSinceLastEvent = timeSinceLastEvent;
	mTimeSinceLastFrame = timeSinceLastEvent;
}

RenderEvent::RenderEvent(){
	RenderEvent(0, 0);
}
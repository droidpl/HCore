#include <Listener/OgreRenderObserver.h>

OgreRenderObserver::OgreRenderObserver(RenderListener* renderListener){
	mRenderListener = renderListener;
}

OgreRenderObserver::~OgreRenderObserver(){}

void OgreRenderObserver::notify(){
	mRenderListener->onUpdate(mLastRenderEvent);
}

bool OgreRenderObserver::frameRenderingQueued (const Ogre::FrameEvent &evt){
	mLastRenderEvent = RenderEvent(evt.timeSinceLastEvent, evt.timeSinceLastFrame);
	notify();
	return true;
}

bool OgreRenderObserver::matchListener(RenderListener* renderListener){
	return  mRenderListener == renderListener;
}
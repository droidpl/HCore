#include <MouseManager.h>
#include <OgreMediator.h>

MouseManager::~MouseManager(){
	if (mStarted) stopMouse();
	OgreInputSystem::getInstance().destroyInputObject(mMouse);
}

void MouseManager::startMouse(){
	mMediator->addRenderListener(this);
	mStarted = true;
}

void MouseManager::stopMouse(){
	mMediator->detachRenderListener(this);
	mStarted = false;
}
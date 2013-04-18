#include <KeyboardManager.h>
#include <OgreMediator.h>

void KeyboardManager::startKeyboard(){
	mMediator->addRenderListener(this);
	mStarted = true;
}

void KeyboardManager::stopKeyboard(){
	mMediator->detachRenderListener(this);
	mStarted = false;
}
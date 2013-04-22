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

list<OIS::KeyCode>* KeyboardManager::getListOfKeys(){
	//TODO
	return NULL;
}
void KeyboardManager::releaseAllPressedKeys(){
	//TODO
}
void KeyboardManager::releasePressedKey(OIS::KeyCode& keyCode){
	//TODO
}
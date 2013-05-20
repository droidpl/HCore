#include <Input/Keyboard/KeyboardManager.h>
#include <Mediator/OgreMediator.h>

KeyboardManager::~KeyboardManager(){
	if (mStarted) stopKeyboard();
	OgreInputSystem::getInstance().destroyInputObject(mKeyboard);
}

void KeyboardManager::startKeyboard(){
	mMediator->addRenderListener(this);
	mStarted = true;
}

void KeyboardManager::stopKeyboard(){
	mMediator->detachRenderListener(this);
	mStarted = false;
}

void KeyboardManager::releaseAllPressedKeys(){
	mKeyCodes.clear();
}
void KeyboardManager::releasePressedKey(const OIS::KeyCode& keyCode){
	mKeyCodes.remove(keyCode);
}
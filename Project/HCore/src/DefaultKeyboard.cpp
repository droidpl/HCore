#include <DefaultKeyboard.h>

DefaultKeyboard::DefaultKeyboard(OgreMediator* mediator, OIS::Keyboard* keyboard){
	mMediator = mediator;
	mKeyboard = keyboard;
	mStarted = false;
	mKeyboard->setEventCallback(this);
}

DefaultKeyboard::~DefaultKeyboard(){
	if(mStarted) stopKeyboard();
	OgreInputSystem::getInstance().destroyInputObject(mKeyboard);
}

void DefaultKeyboard::onUpdate (RenderEvent& renderEvent){
	mKeyboard->capture();
}

bool DefaultKeyboard::keyPressed(const OIS::KeyEvent &arg){
	LogAPI::getInstance().logMessage("Key pressed", typeid(this).name());
	return true;
}

bool DefaultKeyboard::keyReleased(const OIS::KeyEvent &arg){
	LogAPI::getInstance().logMessage("Key released", typeid(this).name());
	return true;
}
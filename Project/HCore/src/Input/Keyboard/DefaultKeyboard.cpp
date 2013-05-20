#include <Input/Keyboard/DefaultKeyboard.h>
#include <Mediator/OgreMediator.h>

DefaultKeyboard::DefaultKeyboard(OgreMediator* mediator, OIS::Keyboard* keyboard){
	mMediator = mediator;
	mKeyboard = keyboard;
	mStarted = false;
	mTimeSinceLastFrame = 0;
	mKeyboard->setEventCallback(this);
}

void DefaultKeyboard::onUpdate (RenderEvent& renderEvent){
	if (mStarted){
		//Notify to the mediator the change
		mTimeSinceLastFrame = renderEvent.getTimeSinceLastFrame();
		if (mKeyCodes.size() > 0){
			string commandName = "manageKeyboardCamera";
			NegotiatorEvent evt(commandName);
			notifyMediator(evt);
		}
	}
	mKeyboard->capture();
}

bool DefaultKeyboard::keyPressed(const OIS::KeyEvent &keyPressed){
	LogAPI::getInstance().logMessage("Key pressed" + keyPressed.key, typeid(this).name());
	if (isCommandKey(keyPressed.key))
		mKeyCodes.push_back(keyPressed.key);
	if (keyPressed.key == OIS::KC_T){
		mMediator->changeInputSystem(InputTypes::KeyboardTypes::INVERSE);
		return false;
	}
	return true;
}

bool DefaultKeyboard::keyReleased(const OIS::KeyEvent &keyReleased){
	LogAPI::getInstance().logMessage("Key released", typeid(this).name());
	if (isCommandKey(keyReleased.key))
		releasePressedKey(keyReleased.key);
	return true;
}

bool DefaultKeyboard::isCommandKey(const OIS::KeyCode& keyCode){
	bool isCommand = false;
	switch(keyCode){
		case OIS::KC_UP:
		case OIS::KC_W:
		case OIS::KC_DOWN:
		case OIS::KC_S:
		case OIS::KC_LEFT:
		case OIS::KC_A:
		case OIS::KC_RIGHT:
		case OIS::KC_D:
		case OIS::KC_PGDOWN:
		case OIS::KC_E:
		case OIS::KC_PGUP:
		case OIS::KC_Q:
			isCommand = true;
	}
	return isCommand;
}
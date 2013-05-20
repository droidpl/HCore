#include <Input/Keyboard/InverseKeyboard.h>
#include <Mediator/OgreMediator.h>

InverseKeyboard::InverseKeyboard(OgreMediator* mediator, OIS::Keyboard* keyboard){
	mMediator = mediator;
	mKeyboard = keyboard;
	mStarted = false;
	mTimeSinceLastFrame = 0;
	mKeyboard->setEventCallback(this);
}

void InverseKeyboard::onUpdate (RenderEvent& renderEvent){
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

bool InverseKeyboard::keyPressed(const OIS::KeyEvent &keyPressed){
	LogAPI::getInstance().logMessage("Key pressed" + keyPressed.key, typeid(this).name());
	if (isCommandKey(keyPressed.key))
		mKeyCodes.push_back(translateKey(keyPressed.key));
	if (keyPressed.key == OIS::KC_T){
		mMediator->changeInputSystem(InputTypes::KeyboardTypes::DEFAULT);
		return false;
	}
	return true;
}

bool InverseKeyboard::keyReleased(const OIS::KeyEvent &keyReleased){
	LogAPI::getInstance().logMessage("Key released", typeid(this).name());
	if (isCommandKey(keyReleased.key))
		releasePressedKey(translateKey(keyReleased.key));
	return true;
}

bool InverseKeyboard::isCommandKey(const OIS::KeyCode& keyCode){
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

const OIS::KeyCode InverseKeyboard::translateKey(const OIS::KeyCode &keyCode){
	OIS::KeyCode newCode = OIS::KC_SPACE;
	switch(keyCode){
		case OIS::KC_UP:
		case OIS::KC_W:
			newCode = OIS::KC_S;
		break;
		case OIS::KC_DOWN:
		case OIS::KC_S:
			newCode = OIS::KC_W;
		break;
		case OIS::KC_LEFT:
		case OIS::KC_A:
			newCode = OIS::KC_D;
		break;
		case OIS::KC_RIGHT:
		case OIS::KC_D:
			newCode = OIS::KC_A;
		break;
		case OIS::KC_PGDOWN:
		case OIS::KC_E:
			newCode = OIS::KC_Q;
		break;
		case OIS::KC_PGUP:
		case OIS::KC_Q:
			newCode = OIS::KC_E;
		break;
	}
	return newCode;
}
#include <Commands/ManageKeyboardCameraCommand.h>

ManageKeyboardCameraCommand::ManageKeyboardCameraCommand(OgreCameraManager* cameraManager, KeyboardManager* keyboardManager){
	mCameraManager= cameraManager;
	mKeyboardManager = keyboardManager;
}

void ManageKeyboardCameraCommand::execute(){
	list<const OIS::KeyCode> listOfCodes = *mKeyboardManager->getListOfKeys();
	list<const OIS::KeyCode>::iterator it;
	it = listOfCodes.begin();
	Ogre::Vector3 accel = Ogre::Vector3::ZERO;
	Ogre::Vector3  velocity = Ogre::Vector3::ZERO;
	float timeSinceLastFrame = mKeyboardManager->getTimeSinceLastFrame();
	while (it != listOfCodes.end()){
		switch((*it)){
			case OIS::KC_UP:
			case OIS::KC_W:
				accel += mCameraManager->getDirection();
			break;
			case OIS::KC_DOWN:
			case OIS::KC_S:
				accel -= mCameraManager->getDirection();
			break;
			case OIS::KC_LEFT:
			case OIS::KC_A:
				accel -= mCameraManager->getRight();
			break;
			case OIS::KC_RIGHT:
			case OIS::KC_D:
				accel += mCameraManager->getRight();
			break;
			case OIS::KC_PGDOWN:
			case OIS::KC_E:
				accel -= mCameraManager->getUp();
			break;
			case OIS::KC_PGUP:
			case OIS::KC_Q:
				accel += mCameraManager->getUp();
			break;
		}
		it++;
	}
	//Normalize the accel and multiply by max velocity vector and the last frame time (avoiding lag extrange responses)
	if (accel != Ogre::Vector3::ZERO){
		if (accel.squaredLength() != 0){
			accel.normalise();
			velocity += accel * MAX_SPEED * timeSinceLastFrame * 10;
		}
		mCameraManager->move(velocity);
	}
}
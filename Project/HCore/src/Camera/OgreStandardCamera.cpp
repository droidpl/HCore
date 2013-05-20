#include <Camera/OgreStandardCamera.h>

const string OgreStandardCamera::ID_CAMERA = "standardCamera";

OgreStandardCamera::OgreStandardCamera(OgreMediator* mediator){
	mMediator = mediator;
	mCamera = NULL;
}

void OgreStandardCamera::setPosition (float x, float y, float z){
	mCamera->setPosition(Ogre::Vector3(x, y, z));
}

void OgreStandardCamera::move (Ogre::Vector3 direction){
	mCamera->move(direction);
}

void OgreStandardCamera::goFordward (float units){
	mCamera->setPosition(mCamera->getDirection()*mCamera->getPosition() + units);
}

void OgreStandardCamera::goBackward (float units){
	mCamera->setPosition(mCamera->getDirection()*mCamera->getPosition() - units);
}

void OgreStandardCamera::yaw (float degrees) {
	mCamera->yaw(Ogre::Degree(degrees));
}

void OgreStandardCamera::pitch (float degrees){
	mCamera->pitch(Ogre::Degree(degrees));
}

void OgreStandardCamera::addToViewport () {
	string eventName = "addToViewport";
	NegotiatorEvent evt(eventName, OgreStandardCamera::ID_CAMERA);
	LogAPI::getInstance().logMessage("Command: " + eventName + " sent.", typeid(this).name());
	notifyMediator(evt);
}
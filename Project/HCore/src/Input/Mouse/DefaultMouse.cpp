#include <Input/Mouse/DefaultMouse.h>
#include <Mediator/OgreMediator.h>

DefaultMouse::DefaultMouse(OgreMediator* mediator, OIS::Mouse* mouse){
	mMediator = mediator;
	mMouse = mouse;
	mStarted = false;
	mPressed = false;
	mMouse->setEventCallback(this);
}
void DefaultMouse::onUpdate (RenderEvent& renderEvent){
	mMouse->capture();
}
bool DefaultMouse::mouseMoved(const OIS::MouseEvent &evt ){
	if (mPressed){
		setMouseAxis(evt);
		//Notify mediator
		string eventName = "manageMouseCamera";
		NegotiatorEvent mediatorEvt(eventName);
		notifyMediator(mediatorEvt);
	}
	return true;
}
bool DefaultMouse::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id){
	LogAPI::getInstance().logMessage("Pressed", typeid(this).name());
	mPressed = true;
	if (id == OIS::MB_Right)
		mMediator->changeInputSystem(InputTypes::MouseTypes::INVERSE);
	return true;
}
bool DefaultMouse::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id){
	LogAPI::getInstance().logMessage("Released", typeid(this).name());
	mPressed = false;
	return true;
}
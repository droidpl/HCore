#include <Input/Mouse/InverseMouse.h>
#include <Mediator/OgreMediator.h>

InverseMouse::InverseMouse(OgreMediator* mediator, OIS::Mouse* mouse){
	mMediator = mediator;
	mMouse = mouse;
	mStarted = false;
	mPressed = false;
	mMouse->setEventCallback(this);
}
void InverseMouse::onUpdate (RenderEvent& renderEvent){
	mMouse->capture();
}
bool InverseMouse::mouseMoved(const OIS::MouseEvent &evt ){
	LogAPI::getInstance().logMessage("Moved", typeid(this).name());
	if (mPressed){
		OIS::Axis xAxis = evt.state.X;
		xAxis.rel = -xAxis.rel;
		OIS::Axis yAxis = evt.state.Y;
		yAxis.rel = -yAxis.rel;
		OIS::Axis zAxis = evt.state.Z;
		zAxis.rel = -zAxis.rel;
		setMouseAxis(xAxis, yAxis, zAxis);
		//Notify mediator
		string eventName = "manageMouseCamera";
		NegotiatorEvent mediatorEvt(eventName);
		notifyMediator(mediatorEvt);
	}
	return true;
}
bool InverseMouse::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id){
	LogAPI::getInstance().logMessage("Pressed", typeid(this).name());
	mPressed = true;
	if (id == OIS::MB_Right)
		mMediator->changeInputSystem(InputTypes::MouseTypes::DEFAULT);
	return true;
}
bool InverseMouse::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id){
	mPressed = false;
	LogAPI::getInstance().logMessage("Released", typeid(this).name());
	return true;
}
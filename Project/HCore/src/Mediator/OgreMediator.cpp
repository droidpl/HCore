#include <Mediator/OgreMediator.h>

OgreMediator::OgreMediator():
	mEngine(0),
	mResourceManager(0),
	mSceneCreator(0),
	mCameraManager(0),
	mObserverRegistry(0),
	mMouseManager(0),
	mKeyboardManager(0){}

OgreMediator::~OgreMediator() {
	if(mKeyboardManager) delete mKeyboardManager;
	if(mMouseManager) delete mMouseManager;
	if(mObserverRegistry) delete mObserverRegistry;
	if(mCameraManager) delete mCameraManager;
	if(mSceneCreator) delete mSceneCreator;
	if(mResourceManager) delete mResourceManager;
	if(mEngine) delete mEngine;
}

void OgreMediator::onOgreChanged(AbstractOgreNegotiator* negotiator, NegotiatorEvent& negotiatorEvent){
	LogAPI::getInstance().logMessage("Command: " + negotiatorEvent.getId() + " received.", typeid(this).name());
	IOgreCommand* command = NULL;
	if(negotiatorEvent.matchEvent("addToViewport")){
		command = new AddToViewportCommand(mCameraManager, mSceneCreator, mEngine);
	}else if (negotiatorEvent.matchEvent("manageRenderListener")){
		command = new ManageRenderListenerCommand(mObserverRegistry, mEngine, negotiatorEvent.getMessage());
	}else if (negotiatorEvent.matchEvent("manageMouseCamera")){
		command = new ManageMouseCameraCommand(mCameraManager, mMouseManager);
	}else if (negotiatorEvent.matchEvent("manageKeyboardCamera")){
		command = new ManageKeyboardCameraCommand(mCameraManager, mKeyboardManager);
	}

	//Execute the created command
	if (command){
		command->execute();
		delete command;
	}
}

bool OgreMediator::initFramework(){
	//Generate a new engine
	mEngine = new OgreEngine(this);
	//Initialize the engine
	bool result = mEngine->initEngine();
	//Initialize the resource manager
	mResourceManager = new OgreResouceManager(this);
	//Use the root to create the scene creator
	mSceneCreator = new OgreSceneCreator(this, mEngine->getRoot());
	//Create the camera and attach it to the viewport
	mCameraManager = (OgreCameraManager*) new OgreStandardCamera(this);
	mCameraManager->addToViewport();
	//Initialize ogre render observer
	mObserverRegistry = new OgreRenderObserverRegistry(this);
	//Initialize input system (alias OIS)
	OgreInputSystem inputSystem = OgreInputSystem::getInstance(mEngine->getWindow());
	mMouseManager = new DefaultMouse(this, static_cast<OIS::Mouse*> (inputSystem.createInputObject(OIS::OISMouse)));
	mMouseManager->startMouse();
	mKeyboardManager = new DefaultKeyboard(this, static_cast<OIS::Keyboard*> (inputSystem.createInputObject(OIS::OISKeyboard)));
	mKeyboardManager->startKeyboard();
	//Parsing scene
	mSceneCreator->parseScene();
	//Print initialized
	LogAPI::getInstance().logMessage("****************\nSimulator framework initialized\n****************", typeid(this).name());
	//Parse the scene
	mSceneCreator->parseScene();
	mSceneCreator->setSkyBox("Global/sky");
	return result;
}

void OgreMediator::startRendering(){
	mEngine->startRendering();
}

void OgreMediator::addRenderListener(RenderListener* renderListener){
	mObserverRegistry->addListener(renderListener);
}

void OgreMediator::detachRenderListener(RenderListener* renderListener){
	mObserverRegistry->detachListener(renderListener);
}


void OgreMediator::changeInputSystem(InputTypes::KeyboardTypes::types type){
	OIS::Type oisType = OIS::OISKeyboard;
	if  (mKeyboardManager) delete mKeyboardManager;
	switch(type){
		case InputTypes::KeyboardTypes::DEFAULT:
			mKeyboardManager = new DefaultKeyboard(this, static_cast<OIS::Keyboard*> (OgreInputSystem::getInstance().createInputObject(oisType)));
		break;
		case InputTypes::KeyboardTypes::INVERSE:
			mKeyboardManager = new InverseKeyboard(this, static_cast<OIS::Keyboard*> (OgreInputSystem::getInstance().createInputObject(oisType)));
		break;
	}
	mKeyboardManager->startKeyboard();
}
void OgreMediator::changeInputSystem(InputTypes::MouseTypes::types type){
	OIS::Type oisType = OIS::OISMouse;
	if (mMouseManager) delete mMouseManager;
	switch(type){
		case InputTypes::MouseTypes::DEFAULT:
			mMouseManager = new DefaultMouse(this, static_cast<OIS::Mouse*> (OgreInputSystem::getInstance().createInputObject(oisType)));
		break;
		case InputTypes::MouseTypes::INVERSE:
			mMouseManager = new InverseMouse(this, static_cast<OIS::Mouse*> (OgreInputSystem::getInstance().createInputObject(oisType)));
		break;
	}
	mMouseManager->startMouse();
}
void OgreMediator::changeInputSystem(InputTypes::HapticTypes::types type){
	switch(type){
		case InputTypes::HapticTypes::DEFAULT:
			//Add haptic negotiator
		break;
	}
}
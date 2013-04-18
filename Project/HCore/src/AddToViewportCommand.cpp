#include <AddToViewportCommand.h>

AddToViewportCommand::AddToViewportCommand(OgreCameraManager* cameraManager, OgreSceneCreator* sceneCreator, OgreEngine* engine){
	mCameraManager = cameraManager;
	mSceneCreator = sceneCreator;
	mEngine = engine;
}

void AddToViewportCommand::execute(){
	//Create or get the scene camera with the name from "MainCamera" property
	mCameraManager->setCamera(
		mSceneCreator->createCamera(
			PropertyLoader::getInstance().getPropertyValue("mainCamera")
		)
	);
	//Add the camera to the viewport
	mEngine->addViewport(mCameraManager->getCamera());
}
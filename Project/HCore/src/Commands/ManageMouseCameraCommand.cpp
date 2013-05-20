#include "Commands/ManageMouseCameraCommand.h"

ManageMouseCameraCommand::ManageMouseCameraCommand(OgreCameraManager* cameraManager, MouseManager* mouseManager)
	:M_SPEED(0.15f){
	mCameraManager = cameraManager;
	mMouseManager = mouseManager;
}

void ManageMouseCameraCommand::execute(){
	mCameraManager->yaw(-mMouseManager->getXAxis().rel * M_SPEED);
	mCameraManager->pitch(-mMouseManager->getYAxis().rel * M_SPEED);
}
/*
Copyright (c) <2013> <Simulator Production Center>

Permission is hereby granted, free of charge, to any
person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the
Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice
shall be included in all copies or substantial portions of
the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef _AddToViewportCommand_H_
#define _AddToViewportCommand_H_

/* INCLUDES */
#include <Commands/IOgreCommand.h>
#include <Camera/OgreCameraManager.h>
#include <OgreSceneCreator.h>
#include <OgreEngine.h>

/**
 * @brief Command that adds a camera manager to the viewport to render elements on the scene.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class AddToViewportCommand: public IOgreCommand {
private:
	OgreCameraManager*		mCameraManager; /**< The camera manager to attach. */
	OgreSceneCreator*		mSceneCreator; /**< The scene creator where a node must be created for the camera. */
	OgreEngine*				mEngine; /**< The engine where this camera must be attached to the window. */
public:
	/**
	 * @brief Constructor of the command.
	 * @param cameraManager The camera manager to attach.
	 * @param sceneCreator The scene creator where a node must be created for the camera.
	 * @param engine The engine where this camera must be attached to the window.
	 */
	AddToViewportCommand(OgreCameraManager* cameraManager, OgreSceneCreator* sceneCreator, OgreEngine* engine);
	void execute();
};
#endif
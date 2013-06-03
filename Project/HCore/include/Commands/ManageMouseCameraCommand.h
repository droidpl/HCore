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

#ifndef _ManageMouseCameraCommand_H_
#define _ManageMouseCameraCommand_H_

/* INCLUDES */
#include <Camera/OgreCameraManager.h>
#include <Commands/IOgreCommand.h>
#include <Input/Mouse/MouseManager.h>

/**
 * @brief The command that moves the camera depending on the mouse movement.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class ManageMouseCameraCommand : public IOgreCommand {
private:
	OgreCameraManager* mCameraManager; /**< The camera manager. */
	MouseManager* mMouseManager; /**< The mouse manager containing the reference to physical mouse. */
	const float M_SPEED; /**< The speed of the Mouse.*/
public:
	/**
	 * @brief Constructor of the camera command.
	 * @param cameraManager The camera manager.
	 * @param mouseManager The mouse manager containing the reference to physical mouse.
	 */
	ManageMouseCameraCommand(OgreCameraManager* cameraManager, MouseManager* mouseManager);
	void execute();
};
#endif
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

#ifndef _ManageKeyboardCameraCommand_H_
#define _ManageKeyboardCameraCommand_H_

/* INCLUDES */
#include <Camera/OgreCameraManager.h>
#include <Commands/IOgreCommand.h>
#include <Input/Keyboard/KeyboardManager.h>

class ManageKeyboardCameraCommand : public IOgreCommand{
private:
	OgreCameraManager*		mCameraManager;
	KeyboardManager*		mKeyboardManager;
	static const int		MAX_SPEED = 250;
public:
	ManageKeyboardCameraCommand(OgreCameraManager* camera, KeyboardManager* keyboardManager);
	void execute();
};
#endif
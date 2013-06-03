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

#ifndef _DefaultKeyboard_H_
#define _DefaultKeyboard_H_

/* INCLUDES */
#include <Input/Keyboard/KeyboardManager.h>

/**
 * @brief Default keyboard used to move the camera on the scene. The keys registered on this keyboard are
 * arrows and 'a', 's', 'd', 'w', 'q', 'e'.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class DefaultKeyboard : public KeyboardManager {
public:
	/**
	 * @brief Constructor of the keyboard negotiator.
	 * @param mediator The mediator attached to this negotiator.
	 * @param keyboard The phisical keyboard instance with an OIS wrapper.
	 */
	DefaultKeyboard(OgreMediator* mediator, OIS::Keyboard* keyboard);
	void onUpdate (RenderEvent& renderEvent);
	bool keyPressed(const OIS::KeyEvent &keyPressed);
    bool keyReleased(const OIS::KeyEvent &keyReleased);
	bool isCommandKey(const OIS::KeyCode &keyCode);
};

#endif
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

#ifndef _DefaultMouse_H_
#define _DefaultMouse_H_

/* INCLUDES */
#include <Input/Mouse/MouseManager.h>

/**
 * @brief Concrete mouse that uses the movement of the camera on default mode.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class DefaultMouse : public MouseManager {
private:
	bool mPressed; /**< Checks if the mouse is pressed. Movement is only produced if it is pressed. */
public:
	/**
	 * @brief Constructor of the default mouse negotiator.
	 * @param mediator The mediator attached to this negotiator.
	 * @param mouse The mouse OIS system.
	 */
	DefaultMouse(OgreMediator* mediator, OIS::Mouse* mouse);
	void onUpdate (RenderEvent& renderEvent);
	bool mouseMoved(const OIS::MouseEvent &evt );
    bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
    bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
};

#endif
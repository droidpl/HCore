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

#ifndef _MouseManager_H_
#define _MouseManager_H_

/* INCLUDES */
#include <OISEvents.h>
#include <OISMouse.h>
#include <Listener/RenderListener.h>
#include <Utils/LogAPI.h>
#include <Input/OgreInputSystem.h>

#include <Mediator/AbstractOgreNegotiator.h>
class OgreMediator;

/**
 * @brief Manager that uses its operations to perform movements with the mouse peripheral.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class MouseManager : public RenderListener, protected AbstractOgreNegotiator, public OIS::MouseListener{
protected:
	OIS::Mouse*			mMouse; /**< The mouse OIS input system. */
	bool				mStarted; /**< Flag that indicates that the mouse system has been set up. */
	OIS::Axis			mXAxis; /**< X axis of the mouse. */
	OIS::Axis			mYAxis; /**< Y axis of the mouse. */
	OIS::Axis			mZAxis; /**< Z axis of the mouse. */
public:
	/**
	 * @brief Destructor that releases the memory allocated by the mouse and its subclasses.
	 */
	~MouseManager();
	/**
	 * @brief Starts receiving inputs from the mouse movements and clicks.
	 */
	void startMouse();
	/**
	 * @brief Stops receiving inputs from the mouse movements and clicks.
	 */
	void stopMouse();
	void onUpdate (RenderEvent& renderEvent) = 0;
	/**
	 * @brief Callback called when the mouse is moved by the user.
	 * @param evt The event received for this movement.
	 * @return True if there is no errors.
	 */
	virtual bool mouseMoved( const OIS::MouseEvent &evt ) = 0;
	/**
	 * @brief Callback called when the mouse is clicked by the user.
	 * @param evt The event received for this click.
	 * @param id The identifier of he button pressed on the mouse.
	 * @return True if there is no errors.
	 */
    virtual bool mousePressed( const OIS::MouseEvent &evt, OIS::MouseButtonID id ) = 0;
	/**
	 * @brief Callback called when the mouse is unclicked by the user.
	 * @param evt The event received for this unclick.
	 * @param id The identifier of he button pressed on the mouse.
	 * @return True if there is no errors.
	 */
    virtual bool mouseReleased( const OIS::MouseEvent &evt, OIS::MouseButtonID id ) = 0;
	/**
	 * @brief Returns the X axis of the mouse.
	 * @return The X axis of the mouse.
	 */
	inline OIS::Axis getXAxis() { return mXAxis; }
	/**
	 * @brief Returns the Y axis of the mouse.
	 * @return The Y axis of the mouse.
	 */
	inline OIS::Axis getYAxis() { return mYAxis; }
	/**
	 * @brief Returns the Z axis of the mouse.
	 * @return The Z axis of the mouse.
	 */
	inline OIS::Axis getZAxis() { return mZAxis; }
	/**
	 * @brief Sets data related to the axis.
	 * @param xAxis The X axis.
	 * @param yAxis The Y axis.
	 * @param zAxis The Z axis.
	 */
	inline void setMouseAxis(OIS::Axis xAxis, OIS::Axis yAxis, OIS::Axis zAxis){ mXAxis = xAxis; mYAxis = yAxis; mZAxis = zAxis; }
	/**
	 * @brief Sets the mouse axis.
	 * @param evt The event that has the data related to axis.
	 */
	inline void setMouseAxis(const OIS::MouseEvent& evt){ setMouseAxis(evt.state.X, evt.state.Y, evt.state.Z); }
};
#endif
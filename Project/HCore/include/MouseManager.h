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
#include <RenderListener.h>
#include <LogAPI.h>
#include <OgreInputSystem.h>

#include <AbstractOgreNegotiator.h>
class OgreMediator;

class MouseManager : public RenderListener, protected AbstractOgreNegotiator, public OIS::MouseListener{
protected:
	OIS::Mouse* mMouse;
	bool mStarted;
	OIS::Axis mXAxis;
	OIS::Axis mYAxis;
	OIS::Axis mZAxis;
public:
	~MouseManager();
	void startMouse();
	void stopMouse();
	void onUpdate (RenderEvent& renderEvent) = 0;
	virtual bool mouseMoved( const OIS::MouseEvent &arg ) = 0;
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ) = 0;
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ) = 0;
	inline OIS::Axis getXAxis() { return mXAxis; }
	inline OIS::Axis getYAxis() { return mYAxis; }
	inline OIS::Axis getZAxis() { return mZAxis; }
	inline void setMouseAxis(OIS::Axis xAxis, OIS::Axis yAxis, OIS::Axis zAxis){ mXAxis = xAxis; mYAxis = yAxis; mZAxis = zAxis; }
	inline void setMouseAxis(const OIS::MouseEvent& evt){ setMouseAxis(evt.state.X, evt.state.Y, evt.state.Z); }
};
#endif
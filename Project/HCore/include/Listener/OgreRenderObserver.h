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

#ifndef _OgreRenderObserver_H_
#define _OgreRenderObserver_H_

/* INCLUDE */
#include <memory>
#include <Listener/RenderListener.h>
#include <OgreFrameListener.h>

/* NAMESPACE */
using namespace std;

/**
 * @brief
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreRenderObserver : protected Ogre::FrameListener {
private:
	RenderListener*		mRenderListener;
	RenderEvent			mLastRenderEvent;
public:
	OgreRenderObserver(RenderListener* renderListener);
	~OgreRenderObserver();
	bool matchListener(RenderListener* renderListener);
	void notify();
	bool frameRenderingQueued (const Ogre::FrameEvent &evt);
};
#endif
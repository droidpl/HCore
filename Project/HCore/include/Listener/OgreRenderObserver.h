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
 * @brief A render observer wrapper that, using Ogre frame listener interface and extending it, can call
 * RenderObserber elements from HCore. This class is only an intermediate between the ogre render observers and
 * HCore observers, hiding the dependency from the Ogre library.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreRenderObserver : protected Ogre::FrameListener {
private:
	RenderListener*		mRenderListener; /**< The render listener prepared to receive some events on each frame. */
	RenderEvent			mLastRenderEvent; /**< Last render event received and sent to the render listener. Something like a cache.*/
public:
	/**
	 * @brief The constructor of the render observer.
	 * @param renderListener Receives the render listener on which the events will be sent.
	 */
	OgreRenderObserver(RenderListener* renderListener);
	/**
	 * @brief Destructor. It frees the memory allocated by this class.
	 */
	~OgreRenderObserver();
	/**
	 * @brief Checks if a render listener passed as a parameter is the same as the one it
	 * stores.
	 * @param renderListener The render listener to compare with.
	 * @return True if they are the same or false in other case.
	 */
	bool matchListener(RenderListener* renderListener);
	/**
	 * @brief Notifies the render listener that a frame has been rendered.
	 */
	void notify();
	/**
	 * @brief This is an Ogre member function that is called each time a frame is rendered.
	 * @param evt The event generated.
	 * @return True if the execution must continue or false if must be stopped.
	 */
	bool frameRenderingQueued (const Ogre::FrameEvent &evt);
};
#endif
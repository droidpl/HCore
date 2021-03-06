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

#ifndef _RenderListener_H_
#define _RenderListener_H_

#include <Listener/RenderEvent.h>

/**
 * @brief Interface implemented by every class that want to listen for rendered frame. In simulator
 * layer it is the only way to take the control and perform some actions once startRendering @see OgreEngine has
 * been called.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class RenderListener {
public:
	/**
	 * @brief The callback implemented by render listeners.
	 * @param renderEvent Event received that has the needed information related to the frame
	 * recently rendered.
	 */
	virtual void onUpdate (RenderEvent& renderEvent) = 0;
};
#endif
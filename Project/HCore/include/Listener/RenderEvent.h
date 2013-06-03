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

#ifndef _RenderEvent_H_
#define _RenderEvent_H_

/**
 * @brief Event sent when a frame has been rendered.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class RenderEvent {
private:
	float		mTimeSinceLastEvent; /**< The time between two consecutive events. */
	float		mTimeSinceLastFrame; /**< The time between two consecutive frames. */
public:
	/**
	 * @brief Constructor of the render event. Initializes elements to default value.
	 */
	RenderEvent();
	/**
	 * @brief Constructor with some parameters needed.
	 * @param timeSinceLastEvent The time between two consecutive events.
	 * @param timeSinceLastFrame The time between two consecutive frames.
	 */
	RenderEvent(float timeSinceLastEvent, float timeSinceLastFrame);
	/**
	 * @brief Returns the time between two consecutive events.
	 * @return Time between two consecutive events.
	 */
	inline float getTimeSinceLastEvent(){ return mTimeSinceLastEvent; }
	/**
	 * @brief Returns the time between two consecutive frames.
	 * @return Time between two consecutive frames.
	 */
	inline float getTimeSinceLastFrame(){ return mTimeSinceLastFrame; }
};
#endif
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

#ifndef _AbstractSimulator_H_
#define _AbstractSimulator_H_

/* INLCUDE */
#include <RenderListener.h>

/**
 * @brief The AbstractSimulator class gives the interface that must be implemented by
 * any simulator that uses the simulator library.
 *
 * AbstactSimulator has three different methods with no implementation:
 * - Run : executes the main operations related to scene creation and listener attaching.
 * - Pause : that function can perform activities to save the state of the simulator and continue when it is runned again.
 * - Resume : resumes the simulator after being paused.
 * - Stop : releases the resources reserved on the simulator and stops the simulation.
 * @author    Javier de Pedro Lopez
 * @version   0.1
 * @date      2013
 */
class AbstractSimulator : public RenderListener {
public:
	/**
	 * @brief Executes the main operations related to scene creation and listener attaching.
	 * 
	 * The one that implements this member function must initialize the scene and all the objects,
	 * including listeners and other needed elements. At last, call the startRendering member function. @see SceneServices::startRendering() 
	 * Unexpected behaviour could happend if the member function is called more than once.
	 */
	virtual void runSimulator() = 0;
	/**
	 * @brief that function can perform activities to save the state of the simulator and continue when it is runned again.
	 * 
	 * When pausing the simulator nothing can keep running and then state must be saved. You must control
	 * what happends if it's called twice.
	 */
	virtual void pauseSimulator() = 0;
	/**
	 * @brief resumes the simulator after being paused.
	 * 
	 * Resets the state to the moment previous to a pause call. You must controll what happends if it's called
	 * twice.
	 */
	virtual void resumeSimulator() = 0;
	/**
	 * @brief releases the resources reserved on the simulator and stops the simulation.
	 * 
	 * Stop the simulator, all it's resources destroy, so don't try to access any member
	 * from the simulator because you can get a Null reference.
	 */
	virtual void stopSimulator() = 0;
};
#endif
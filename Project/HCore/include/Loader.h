/*
Copyright (c) <2012> <Simulator Production Center>

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

#ifndef _Loader_H_
#define _Loader_H_

/* INCLUDE */
#include <SimulatorAPI.h>
#include <memory>
//Memory Leaks check
#ifdef _DEBUG
	#include <vld.h>
#endif

/* NAMESPACE */
using namespace std;

/**
 * @brief This class is the entrance point of a simulator execution.
 * 
 * To begin a simulator program simply extend this class and call super::go() member
 * function. This will init everything on the framework for you. You can call optionally
 * SceneServices::initFramework() instead. @see SceneServices::initFramework()
 * 
 * The order followed in the init by SceneServices::initFramework() process on the Ogre implementation is:
 * - Creates the root element.
 * - Loads plugins and resources files.
 * - Checks the configuration in the default Ogre.cfg file.
 * - Creates the window and attach a FrameListener.
 * @author    Javier de Pedro Lopez
 * @version   0.1
 * @date      2013
 */
class Loader {
private:
	/**
	 * Internal implementation of the graphics render system. Hides all data and functions
	 * using a Facade design pattern. @see pImpl pattern on c++
	 */
	class Facade; 
	shared_ptr<Facade>		pImpl; /**< Private implementation that hides the graphics behaviour. */
public:
	/**
	 * @brief Constructor of the loader. Initializes the private implementation.
	 */
	Loader();
	/**
	 * @brief Releases the posible memory leaks.
	 */
	~Loader();
	/**
	 * @brief Program entrance point. This is the first function executed when the program loads.
	 *
	 * Never call this function directly, only extending this class and using super::go().
	 * @return A boolean explaining if the simulator has initialized on the good way. 
	 */
	virtual bool go(void);
};
#endif
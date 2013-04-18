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

#ifndef _SimulatorAPI_H_
#define _SimulatorAPI_H_

/* INCLUDE */
#include <memory>
#include <RenderListener.h>

/* NAMESPACE */
using namespace std;

/**
 * @brief This service provide the needed information to manage the scene and all it's objects.
 *
 * Provides the functions needed to manage the scene, it's objects and the mayor operations you can perform with them.
 */
class SimulatorAPI {
private:
	class Facade;
	shared_ptr<Facade>			pImpl; /**< Private implementation of the Facade. */
	/**
	 * @brief Constructor of the service. That's private because of a singleton specification.
	 */
	SimulatorAPI();
public:
	/**
	 * @brief Destructor of the service.
	 */
	~SimulatorAPI();
	/**
	 * @brief Returns the instance of the singleton.
	 * @return The unique instance of the service.
	 */
	static SimulatorAPI& getInstance(){
		static SimulatorAPI instance;
		return instance;
	}
	/**
	 * @brief Initializes the surgery framework. You shouldn't call it if you have used the super::Loader call.
	 *
	 * @return A boolean value explaining if everything went oke in the initializationn process.
	 */
	bool initFramework();
	/**
	 * @brief Starts the render loop.
	 *
	 * Every instruction following this will not be executed until the render loop ends, so be careful because
	 * those instructions can cause the death of the program with runtime errors.
	 */
	void startRendering();

	void addRenderListener(RenderListener* renderListener);

	void detachRenderListener(RenderListener* renderListener);
};
#endif
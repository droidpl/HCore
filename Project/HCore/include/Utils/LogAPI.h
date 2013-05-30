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

#ifndef _LogAPI_H_
#define _LogAPI_H_

/* INCLUDE */
#include <memory>
#include <string>

/* NAMESPACE */
using namespace std;

/**
 * @brief This service provide the needed information to manage the scene and all it's objects.
 *
 * Provides the functions needed to manage the scene, it's objects and the mayor operations you can perform with them.
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class LogAPI {
private:
	/**
	 * Facade that encapsulates Ogre inside.
	 */
	class Facade;
	shared_ptr<Facade>			pImpl; /**< Private implementation of the Facade. */
	/**
	 * @brief Constructor of the service. That's private because of a singleton specification.
	 */
	LogAPI();
public:
	/**
	 * @brief Returns the instance of the singleton.
	 * @return The unique instance of the service.
	 */
	static LogAPI& getInstance(){
		static LogAPI instance;
		return instance;
	}
	/**
	 * @brief Logs a message using the defaul log output. (Console or ogre log file).
	 * @param message The message to log.
	 * @param className The name of the class that produces this log.
	 */
	void logMessage(const string message, const string className);
};
#endif
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

#ifndef _OgreInputSystem_H_
#define _OgreInputSystem_H_

/* INCLUDES */
#include <OISInputManager.h>
#include <OgreRenderWindow.h>

/**
 * @brief Input system creator. Depending on the needs it creates OIS systems to interact with the 
 * peripherals (scpecially keyboard and mouse.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreInputSystem {
private:
	OIS::InputManager*		mInputManager; /**< The input manager that can create OIS systems. */
	OgreInputSystem(Ogre::RenderWindow* window); /**< Render window where those systems will be attached. 
												 We can calculate the coordinates of this window and resize the input system. */
public:
	/**
	 * @brief Returns the instance of the singleton.
	 * @return The unique instance of the service.
	 */
	static OgreInputSystem& getInstance(Ogre::RenderWindow* window = 0){
		static OgreInputSystem instance(window);
		return instance;
	}
	/**
	 * @brief Creates the needed input onject.
	 * @param type The type of input to create.
	 * @param bufferMode This mode allows buffered entrance of data or unbuffered.
	 */
	OIS::Object* createInputObject(OIS::Type type, bool bufferMode = true);
	/**
	 * @brief Destroys the input object passed as parameter.
	 * @param inputObject The input object to destroy.
	 */
	void destroyInputObject(OIS::Object* inputObject);
};
#endif
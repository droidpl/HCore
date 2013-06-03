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

#ifndef _StandardCamera_H_
#define _StandardCamera_H_

/* INCLUDES */
#include <Camera/OgreCameraManager.h>
#include <string>

/* NAMESPACE */
using namespace std;

/**
 * @brief Standar camera that moves on a typical way giving all elements necessary to change 
 * its position and direction.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreStandardCamera : private OgreCameraManager {
public:
	static const string ID_CAMERA; /**< The id of the standard camera */
	/**
	 * @brief Constructor of the standard camera.
	 * @param mediator As a negotiator it needs a mediator on which it is attached.
	 */
	OgreStandardCamera(OgreMediator* mediator);
	void setPosition (float x, float y, float z);
	void move (Ogre::Vector3 direction);
	Ogre::Vector3 getPosition () { return mCamera->getPosition(); }
	inline Ogre::Vector3 getDirection() { return mCamera->getDirection(); }
	inline Ogre::Vector3 getRight() { return mCamera->getRight(); }
	inline Ogre::Vector3 getUp() { return mCamera->getUp(); }
	void goFordward (float units);
	void goBackward (float units);
	void yaw (float degrees);
	void pitch (float degrees);
	void addToViewport();
};

#endif
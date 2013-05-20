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

#ifndef _CameraManager_H_
#define _CameraManager_H_

/* INCLUDES */
#include <OgreCamera.h>
#include <string>
#include <Mediator/AbstractOgreNegotiator.h>
#include <Utils/LogAPI.h>
class OgreMediator;

/* NAMESPACE */
using namespace std;

class OgreCameraManager : protected AbstractOgreNegotiator {
protected:
	Ogre::Camera* mCamera;
public:
	static const string ID_CAMERA;
	virtual void setPosition (float x, float y, float z) = 0;
	virtual Ogre::Vector3 getPosition () = 0;
	virtual Ogre::Vector3 getDirection() = 0;
	virtual Ogre::Vector3 getRight () = 0;
	virtual Ogre::Vector3 getUp() = 0;
	virtual void move(Ogre::Vector3 direction) = 0;
	virtual void goFordward (float units) = 0;
	virtual void goBackward (float units) = 0;
	virtual void yaw (float degrees) = 0;
	virtual void pitch (float degrees) = 0;
	virtual void addToViewport () = 0;
	inline Ogre::Camera* getCamera () { return mCamera; }
	inline void setCamera(Ogre::Camera* camera) { mCamera = camera; }
};

#endif
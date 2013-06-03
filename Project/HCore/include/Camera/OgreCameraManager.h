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

/**
 * @brief Negotiator that abstracts all the typical operations with a camera.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreCameraManager : protected AbstractOgreNegotiator {
protected:
	Ogre::Camera* mCamera; /**< The camera of this camera mangaer. */
public:
	static const string ID_CAMERA; /**< The unique identifier of this camera */
	/**
	 * @brief Sets the position of the camera on the scene. It must be attached to an ogre node before
	 * it has any success.
	 * @param x The x axis.
	 * @param y The y axis.
	 * @param z The z axis.
	 */
	virtual void setPosition (float x, float y, float z) = 0;
	/**
	 * @brief Returns the position of the camera on the scene.
	 * @return The vector containing the position of the camera.
	 */
	virtual Ogre::Vector3 getPosition () = 0;
	/**
	 * @brief Returns the direction of the camera on the scene.
	 * @return The vector containing the direction of the camera.
	 */
	virtual Ogre::Vector3 getDirection() = 0;
	/**
	 * @brief Returns the right vector of the camera.
	 * @return A vector containing the right vector of the camera.
	 */
	virtual Ogre::Vector3 getRight () = 0;
	/**
	 * @brief Returns the up vector of the camera.
	 * @return A vector containing the up vector of the camera.
	 */
	virtual Ogre::Vector3 getUp() = 0;
	/**
	 * @brief Moves the camera to the given position.
	 * @param direction The direction on which the camera must move.
	 */
	virtual void move(Ogre::Vector3 direction) = 0;
	/**
	 * @brief Goes forward n given units as a parameter.
	 * @param units The units to move.
	 */
	virtual void goFordward (float units) = 0;
	/**
	 * @brief Goes backward n given units as a parameter.
	 * @param units The units to move.
	 */
	virtual void goBackward (float units) = 0;
	/**
	 * @brief Move the direction of the camera on the y axis. @see Ogre::Camera
	 * @param degrees Degrees to move.
	 */
	virtual void yaw (float degrees) = 0;
	/**
	 * @brief Move the direction of the camera on the x axis. @see Ogre::Camera.
	 * @param degrees Degrees to move.
	 */
	virtual void pitch (float degrees) = 0;
	/**
	 * @brief Adds a camera to the viewport launching an event to the mediator.
	 */
	virtual void addToViewport () = 0;
	/**
	 * @brief Returns the camera object attached to the manager. This camera is
	 * an Ogre type.
	 * @return The camera attached to the manager.
	 */
	inline Ogre::Camera* getCamera () { return mCamera; }
	/**
	 * @brief Sets the camera on the manager. Do not call directlñy to this method, it must be
	 * called by the corresponding event and command on the mediator.
	 * @param camera The camera to attach.
	 */
	inline void setCamera(Ogre::Camera* camera) { mCamera = camera; }
};

#endif
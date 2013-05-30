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

#ifndef _OgreMediator_H_
#define _OgreMediator_H_

/* INCLUDES */
#include <Mediator/IOgreMediator.h>
#include <OgreEngine.h>
#include <OgreSceneCreator.h>
#include <Camera/OgreCameraManager.h>
#include <Camera/OgreStandardCamera.h>
#include <Resources/OgreResourceManager.h>
#include <Commands/AddToViewportCommand.h>
#include <Commands/ManageRenderListenerCommand.h>
#include <Commands/ManageMouseCameraCommand.h>
#include <Commands/ManageKeyboardCameraCommand.h>
#include <Listener/OgreRenderObserverRegistry.h>
#include <Input/OgreInputSystem.h>
#include <Listener/RenderListener.h>
#include <Input/Mouse/DefaultMouse.h>
#include <Input/Mouse/InverseMouse.h>
#include <Input/Keyboard/DefaultKeyboard.h>
#include <Input/Keyboard/InverseKeyboard.h>
#include <Input/InputTypes.h>
#include <Utils/LogAPI.h>

/**
 * @brief
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreMediator: public IOgreMediator {
private:
	OgreEngine*						mEngine; /**< The engine of the framework. */
	OgreSceneCreator*				mSceneCreator; /**< The scene creator elements. */
	OgreCameraManager*				mCameraManager; /**< The camera manager of the scene. */
	OgreResouceManager*				mResourceManager; /**< Manages all the resources needed. */
	OgreRenderObserverRegistry*		mObserverRegistry; /**< Render observer registry for render listeners. */
	MouseManager*					mMouseManager; /**< The mouse manager **/
	KeyboardManager*				mKeyboardManager; /**< The keyboard manager **/
public:
	OgreMediator();
	~OgreMediator();
	void onOgreChanged(AbstractOgreNegotiator* negotiator, NegotiatorEvent& negotiatorEvent);
	bool initFramework();
	void startRendering();
	void addRenderListener(RenderListener* renderListener);
	void detachRenderListener(RenderListener* renderListener);
	void changeInputSystem(InputTypes::MouseTypes::types type);
	void changeInputSystem(InputTypes::KeyboardTypes::types type);
	void changeInputSystem(InputTypes::HapticTypes::types type);
};
#endif
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
#include <IOgreMediator.h>
#include <OgreEngine.h>
#include <OgreSceneCreator.h>
#include <OgreCameraManager.h>
#include <OgreStandardCamera.h>
#include <OgreResourceManager.h>
#include <AddToViewportCommand.h>
#include <ManageRenderListenerCommand.h>
#include <ManageMouseCameraCommand.h>
#include <OgreRenderObserverRegistry.h>
#include <RenderListener.h>
#include <DefaultMouse.h>
#include <OgreInputSystem.h>
#include <DefaultKeyboard.h>
#include <InverseMouse.h>
#include <InputTypes.h>
#include <LogAPI.h>

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
	virtual void onOgreChanged(AbstractOgreNegotiator* negotiator, NegotiatorEvent& negotiatorEvent);
	bool initFramework();
	void startRendering();
	void addRenderListener(RenderListener* renderListener);
	void detachRenderListener(RenderListener* renderListener);
	void changeInputSystem(InputTypes::MouseTypes::types type);
	void changeInputSystem(InputTypes::KeyboardTypes::types type);
	void changeInputSystem(InputTypes::HapticTypes::types type);
};
#endif
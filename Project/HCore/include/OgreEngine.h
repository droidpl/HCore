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

#ifndef _Engine_H_
#define _Engine_H_

/* INCLUDE */
#include <Utils/PropertyLoader.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreString.h>
#include <OgreFrameListener.h>
#include <Listener/OgreRenderObserver.h>
#include <Utils/LogAPI.h>

#include <Mediator/AbstractOgreNegotiator.h>
class OgreMediator;

/**
 * @brief Engine of the application that manages the information related to Root and render.
 *
 * This is an Ogre specific class so DO NOT USE IT ON YOUR IMPLEMENTATIONS or it will be never independent. You
 * can manage every action performed by using the SceneServices.
 * @author    Javier de Pedro Lopez
 * @version   0.1
 * @date      2013
 */
class OgreEngine : private Ogre::FrameListener, protected AbstractOgreNegotiator{
private:
	Ogre::RenderWindow*			mWindow; /**< Window Ogre implementation with a viewport where everything is rendered. */
	Ogre::Root*					mRoot; /**< Root element for Ogre. Creates all the configurations and essential elements managing the memory. */
	Ogre::String				mPluginsCfg; /**< String containing the name of the plugins.cfg file. This file contains all the plugins lodaded by the program. */
	Ogre::Viewport*				mCurrentViewport; /**< The current active viewport. */

	/**
	 * @brief Setups the root, configures the render and initializes the engine needed components.
	 * 
	 * @return A boolean that explains if the engine initialized correctly.
	 */
	bool setup();
	/**
	 * @brief Configures the render properties such us the size of the window or 
	 * the render engine.
	 *
	 * @return A boolean that explains if the configuration was accepted or cancelled.
	 */
	bool configure();
protected:
	/**
	 * @brief Interface inherited that performs operations when a frame is queued to render.
	 *
	 * @param evt The render event with some useful information.
	 * @return A boolean that means the render was correct. False means the render loop must stop.
	 */
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);
public:
	/**
	 * @brief Constructor of the engine.
	 */
	OgreEngine(OgreMediator* mediator);
	/**
	 * @brief Destructor of the engine.
	 */
	~OgreEngine();
	/**
	 * @brief Initializes all the elements of the engine.
	 * 
	 * If you are using the Loader class to start the application you don't need to make
	 * a call directly because it's performed for you.
	 * 
	 * @return A boolean value explaining if everything was setup correctly.
	 */
	bool initEngine();
	/**
	 * @brief Contacts the Root element and starts the loop rendering process.
	 * 
	 * Simply makes a call to startRendering on the Root object to beggin the rendering
	 * process. You must take into account that everything performed later to this call
	 * will not be executed until the loop ends, so call this after all operations.
	 *
	 * If you want to do something while rendering, attach a FrameListener before.
	 */
	void startRendering();
	/**
	 * @brief Allow the access to the Root element.
	 * @return The root of the application.
	 */
	inline Ogre::Root* getRoot(){return mRoot;}
	/**
	 * @brief Adds a new viewport to the scene, setting the aspect ratio of the camera to the value
	 * obtained by dividing the width and height of this viewport.
	 *
	 * @param camera The camera to add on the scene.
	 */
	void addViewport(Ogre::Camera* camera);
	inline Ogre::RenderWindow* getWindow(){return mWindow;}
	void addRenderListener(OgreRenderObserver* renderListener);
	void detachRenderListener(OgreRenderObserver* renderListener);
};
#endif
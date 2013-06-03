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

#ifndef _KeyboardManager_H_
#define _KeyboardManager_H_

/* INLCUDES */
#include <OISEvents.h>
#include <OISKeyboard.h>
#include <Listener/RenderListener.h>
#include <Utils/LogAPI.h>
#include <Input/OgreInputSystem.h>
#include <list>

#include <Mediator/AbstractOgreNegotiator.h>
class OgreMediator;

/**
 * @brief This class manages the keyboard giving a consistent interface to create as much keyboards as needed.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class KeyboardManager : public RenderListener, protected AbstractOgreNegotiator, public OIS::KeyListener {
protected:
	OIS::Keyboard*				mKeyboard; /**< The keyboard used on ogre. */
	bool						mStarted; /**< Variable indicating if the keyboard has started and is listening for keys. */
	list<const OIS::KeyCode>	mKeyCodes; /**< The list of keys pressed. */
	float						mTimeSinceLastFrame; /**< Time between two consecutive buffered events. */
public:
	/**
	 * @brief Destructor that releases needed memory.
	 */
	~KeyboardManager();
	/**
	 * @brief Starts the concrete keyboard behaviour.
	 */
	void startKeyboard();
	/**
	 * @brief Stops the concrete keyboard behaviour.
	 */
	void stopKeyboard();
	/**
	 * @brief Removes from the key list all pressed keys. After this operation, no events will be sent to the mediator
	 * with the pressed keys.
	 */
	void releaseAllPressedKeys();
	/**
	 * @brief Releases a given key if it is on the list.
	 */
	void releasePressedKey(const OIS::KeyCode& keyCode);
	virtual void onUpdate (RenderEvent& renderEvent) = 0;
	/**
	 * @brief Callback that notifies the concrete keyboard that a key on the physical keyboard
	 * has been pressed. Adds to the list the pressed key.
	 * @param evt The event that contains data about the physical keyboard and the key that has been 
	 * pressed.
	 * @return True if there is no error.
	 */
	virtual bool keyPressed(const OIS::KeyEvent &evt) = 0;
	/**
	 * @brief Callback that notifies the concrete keyboard that a key on the physical keyboard
	 * has been released. Release the key from the pressed keys list.
	 * @param evt The event that contains data about the physical keyboard and the key that has been 
	 * released.
	 * @return True if there is no error.
	 */
    virtual bool keyReleased(const OIS::KeyEvent &evt) = 0;
	/**
	 * @brief On the concrete keyboards not all the keys are needed. This method must be called to check if
	 * the key pressed is really a used key.
	 * @param keyCode The code of the key to check as a used key.
	 * @return True if there is no error.
	 */
	virtual bool isCommandKey(const OIS::KeyCode& keyCode) = 0;
	/**
	 * @brief Returns the complete list of used keys.
	 * @return The complete list of pressed keys.
	 */
	inline list<const OIS::KeyCode>* getListOfKeys(){ return &mKeyCodes;}
	/**
	 * @brief Returns the time since last frame rendered.
	 * @return The time since last frame rendered.
	 */
	inline float getTimeSinceLastFrame(){ return mTimeSinceLastFrame; }
};

#endif
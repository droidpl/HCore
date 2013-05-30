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
 * @brief
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class KeyboardManager : public RenderListener, protected AbstractOgreNegotiator, public OIS::KeyListener {
protected:
	OIS::Keyboard*				mKeyboard;
	bool						mStarted;
	list<const OIS::KeyCode>	mKeyCodes;
	float						mTimeSinceLastFrame;
public:
	~KeyboardManager();
	void startKeyboard();
	void stopKeyboard();
	void releaseAllPressedKeys();
	void releasePressedKey(const OIS::KeyCode& keyCode);
	virtual void onUpdate (RenderEvent& renderEvent) = 0;
	virtual bool keyPressed(const OIS::KeyEvent &evt) = 0;
    virtual bool keyReleased(const OIS::KeyEvent &evt) = 0;
	virtual bool isCommandKey(const OIS::KeyCode& keyCode) = 0;
	inline list<const OIS::KeyCode>* getListOfKeys(){ return &mKeyCodes;}
	inline float getTimeSinceLastFrame(){ return mTimeSinceLastFrame; }
};

#endif
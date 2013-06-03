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

#ifndef _AddRenderListenerCommand_H_
#define _AddRenderListenerCommand_H_

/* INCLUDE */
#include <Commands/IOgreCommand.h>
#include <OgreEngine.h>
#include <Listener/OgreRenderObserverRegistry.h>
#include <string>

/* NAMESPACE */
using namespace std;

/**
 * @brief Command that uses the engine and the observer registry to attach the HCore observer to ogre framework.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class ManageRenderListenerCommand : public IOgreCommand{
private:
	OgreRenderObserverRegistry*			mObserverRegistry; /**< Registry containing all attached observers. */
	OgreEngine*							mEngine; /**< The engine as a core of the relation between HCore and Ogre. */
	string								mAction; /**< The action to perform. */
public:
	/**
	 * @brief Constructor that saves the data passed to it.
	 * @param observerRegistry Registry containing all attached observers.
	 * @param engine The engine as a core of the relation between HCore and Ogre.
	 * @param action The action that tells this command what to do. (attach or dettach).
	 */
	ManageRenderListenerCommand(OgreRenderObserverRegistry* observerRegistry, OgreEngine* engine, string action="");
	void execute();
};
#endif
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

#ifndef _OgreRenderObserverRegistry_H_
#define _OgreRenderObserverRegistry_H_

/* INCLUDE */
#include <iostream>
#include <list>
#include <Listener/RenderListener.h>
#include <Listener/OgreRenderObserver.h>
#include <Utils/LogAPI.h>

#include <Mediator/AbstractOgreNegotiator.h>
class OgreMediator;

/* NAMESPACE */
using namespace std;
/**
 * @brief The render registry stores every render observer registered on HCore inside its list. Those observers
 * stored receives the notifications and will be removed when needed.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class OgreRenderObserverRegistry : protected AbstractOgreNegotiator{
private:
	list<OgreRenderObserver*>	mRenderObservers; /**< The list with all the observers registered on the framework. */
	OgreRenderObserver*			mCacheLastObserver; /**< A cache with the las observer that has been used. */
	/**
	 * @brief Remove a render observer from the list freeing the memory. It also detaches the observer from OgreEngine
	 * by launching an event.
	 * @param renderObserver The render observer element to delete.
	 * @return True if it was removed succesfully.
	 */
	bool deleteRenderObserver(OgreRenderObserver* renderObserver);
public:
	/**
	 * @brief Constructor of the registry.
	 * @param mediator The mediator that belongs to this negotiator.
	 */
	OgreRenderObserverRegistry(OgreMediator* mediator);
	/**
	 * @brief Destructor to release memory.
	 */
	~OgreRenderObserverRegistry();
	/**
	 * @brief Adds a new render listener to the registry.
	 * @param renderListener The render listener to add.
	 */
	void addListener(RenderListener* renderListener);
	/**
	 * @brief Remove a render observer and free the memory.
	 * @param renderListener The render listener to detach.
	 */
	void detachListener(RenderListener* renderListener);
	/**
	 * @brief Removes but not frees the observer stored on the cache. The its value is NULL.
	 */
	inline void flushCache(){ mCacheLastObserver = NULL; }
	/**
	 * @brief Returns the value of the cached observer.
	 * @return The value of the cached observer.
	 */
	inline OgreRenderObserver* getCachedObserver() {return mCacheLastObserver; }
};
#endif
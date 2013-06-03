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

#ifndef _AbstractOgreNegotiator_H_
#define _AbstractOgreNegotiator_H_

/* INCLUDES */
#include <Mediator/NegotiatorEvent.h>
class OgreMediator;

/**
 * @brief Abstract class that represents the negotiators. Those negotiators saves the instance of a mediator
 * which receives messages and performs some predefined actions.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class AbstractOgreNegotiator {
protected:
	OgreMediator*			mMediator; /**< The mediator that receives messages and performs predefined operations. */
public:
	/**
	 * @brief Notifies the mediator with an event to order it an actions.
	 *
	 * Actions sent to the mediator are only needed when multiple negotiators are involved in this action. If the 
	 * negotiator can perform this action itself or the only implied negotiator is the one that sends the event, then
	 * this event might not be sent.
	 * @param mediatorEvent The event that will be sent to the mediator.
	 */
	virtual void notifyMediator(NegotiatorEvent& mediatorEvent);
};
#endif
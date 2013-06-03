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

#ifndef _IOgreMediator_H_
#define _IOgreMediator_H_

/* INCLUDES */
#include <Mediator/AbstractOgreNegotiator.h>
#include <Mediator/NegotiatorEvent.h>

/**
 * @brief Interface that might be implemented by a mediator that receives messages and performs actions.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class IOgreMediator {
public:
	/**
	 * @brief Callback that will be called each time a negotiator launches a new event.
	 * @param negotiator The negotiator that launched the event.
	 * @param negotiatorEvent The event that has been launched.
	 */
	virtual void onOgreChanged(AbstractOgreNegotiator* negotiator, NegotiatorEvent& negotiatorEvent) = 0;
};
#endif
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

#ifndef _NegotiatorEvent_H_
#define _NegotiatorEvent_H_

/* INCLUDES */
#include <string>
#include <memory>

/* NAMESPACES */
using namespace std;

/**
 * @brief Event with all data needed to perform an action than a negotiator sends to a mediator.
 *
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class NegotiatorEvent {
private:
	string					mId; /**< Identifier of the events. Unique for each event. */
	string					mMessage; /**< The optional message for a given event. Allow a simulated parameter for a command for this event. */
public:
	/**
	 * @brief Constructor of the negotiator event.
	 * @param id The identifier of the event.
	 * @param message The optional message.
	 */
	NegotiatorEvent(string id, string message="");
	/**
	 * @brief Checks if an event is the same as another by compating its ids.
	 * @param eventId The identifier of the second event that will be compared.
	 * @return True if those events are the same. Elsewhere, false.
	 */
	bool matchEvent(string eventId);
	/**
	 * @brief Returns the message.
	 * @return The message internal value.
	 */
	inline string getMessage(){return mMessage; }
	/**
	 * @brief Returns the id.
	 * @return The id internal value.
	 */
	inline string getId(){ return mId; }
};
#endif
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

#ifndef _PropertyLoader_H_
#define _PropertyLoader_H_

/* INCLUDES */
#include <memory>
#include <string>

/* NAMESPACE */
using namespace std;

/**
 * @brief This class can load .properties files and check some rules specified as a default documented values.
 *
 * Gives flexibility to the simulator by modifying some values without recompiling the source. The documents
 * are formatted as .XML and can be interpreted as:
 * <configuration>
 *		<property key="PROPERTY_NAME">VALUE</property>
 * </configuration>
 * - PROPERTY_NAME: the name of the property that will be accessed.
 * - VALUE: the value to store.
 * Remember that the XML must be well formated and it will be parsed using the TinyXml2 library.
 */
class PropertyLoader {
private:
	class Facade;
	shared_ptr<Facade>			pImpl; /**< Private implementation of the Facade. */

	//METHODS
	/**
	 * @brief Private constructor for the loader to follow the singleton pattern.
	 */
	PropertyLoader();
	/**
	 * @brief Private constructor for the loader to follow the singleton pattern.
	 */
    PropertyLoader(PropertyLoader const&);
	/**
	 * @brief Remove the = operation implementation to disallow the direct assignation.
	 */
    void operator=(PropertyLoader const&);
public:
	/**
	 * @brief Destructor of the property loader.
	 */ 
	~PropertyLoader();
    static PropertyLoader& getInstance(){
		//Create the singleton property loader instance
        static PropertyLoader    instance;
		return instance;
	}
	/**
	 * @brief Loads a file.properties to read any stored property.
	 *
	 * @param propertiesPath The properties path name of the file located on the system. It's frequently using something like
	 * "../YourPath/YourFile.properties.
	 * @return the boolean value indicating a result of the load operation.
	 */
	bool loadProperties(string propertiesPath);
	/**
	 * @brief Marks if there is a property file loaded or it's NULL.
	 *
	 * @return The boolean value that specifies if there is any property loaded.
	 */
	bool propertiesLoaded();
	/**
	 * @brief Returns the string property for the given value on the loaded properties file. If there is no mathing key
	 * the result is NULL.
	 * 
	 * @param propertyKey The name of the property you want to get the value.
	 * @return The value of the property selected.
	 */
	string getPropertyValue(string propertyKey);
	/**
	 * @brief Returns the name of the las file loaded or NULL if there is no loaded file on the memory.
	 *
	 * @return The name of the properties file loaded including the path.
	 */
	string getPropertyFileName();
};

#endif
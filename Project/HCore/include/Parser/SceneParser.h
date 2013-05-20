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

#ifndef _SceneParser_H_
#define _SceneParser_H_


#include <OgreSceneCreator.h>
#include <Utils/PropertyLoader.h>
#include <tinyxml2.h>

/**
 * @brief Creates all the elements on the scene including it's physics and haptics.
 * 
 * Use this class to create all the elements, do not create them one by one because this will
 * free the memory when they are not needed.
 */

class SceneParser {

private:
	string mUriFile;
	const OgreSceneCreator* mSceneCreator;

public:

	SceneParser(const OgreSceneCreator* sceneCreator);

	void parseScene();

};
#endif
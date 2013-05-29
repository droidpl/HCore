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

#include <tinyxml2/tinyxml2.h>
#include <string>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
class OgreSceneCreator;

/* NAMESPACE */
using namespace std;

class SceneParser {
private:
	/* ELEMENTS */
	#define HCORE_GLOBAL_NODE "ogre:simulator-scene"
	#define HCORE_SCENE_NODE "ogre:scene-node"
	#define HCORE_NODE_POSITION "ogre:position"
	#define HCORE_NODE_DIRECTION "ogre:direction"
	#define HCORE_ENTITY_NODE "ogre:entity"
	#define HCORE_ENTITY_VISIBILITY "ogre:visibility"
	/* ATTRIBUTES */
	#define HCORE_ID "id"
	#define HCORE_X "x"
	#define HCORE_Y "y"
	#define HCORE_Z "z"
	#define HCORE_RESOURCE "resource"
	#define HCORE_VALUE "value"

	string							mUriFile; /**Uri where the scene must be parsed */
	OgreSceneCreator*				mSceneCreator; /**The scene creator that helps to build the scene */
	tinyxml2::XMLDocument			mDoc; /** The document that parses elements as tinyxml2 */
	/**
	 * Parses a scene xml node with all its related attributes.
	 */
	Ogre::SceneNode* parseSceneNode(tinyxml2::XMLElement* node);
	/**
	 * Parse an entity of the scene.
	 */
	Ogre::Entity* parseEntityNode(tinyxml2::XMLElement* entity);
public:
	/**
	 * Initializes the parser of the scene.
	 */
	SceneParser(OgreSceneCreator* sceneCreator);
	/**
	 * Parses the scene into a real scene.
	 */
	void parseScene();
};
#endif
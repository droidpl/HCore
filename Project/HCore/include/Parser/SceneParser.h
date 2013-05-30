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

/**
 * @brief This class has to read all the data inside a configuration file and show it as an Ogre scene.
 * 
 * This class takes the file location (relative to the $(Configuration)-dist folder) from the property
 * file. The name of the property is "sceneLocation". If the searched file does not exist it will produce
 * unexpected behaviour.
 * The XML located must follow the XML Schema standar provided on the configuration folder, so, before
 * parsing a scene, you must be sure the XML created is valid.
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
 */
class SceneParser {
private:
	/******
	 * Global elements of the simulator.
	 * Be careful when changing those values because can interact with other predefined elements.
	 ******/
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
	 * @brief Parses a scene xml node with all its related attributes.
	 * @param node The XML element (from the scene file) of the scene that will be parsed as a Ogre node.
	 * @return The Ogre scene node.
	 */
	Ogre::SceneNode* parseSceneNode(tinyxml2::XMLElement* node);
	/**
	 * @brief Parse an entity of the scene in the scene file configuration.
	 * @param entity The XML element that represent an Ogre entity object.
	 * @return The Ogre entity object.
	 */
	Ogre::Entity* parseEntityNode(tinyxml2::XMLElement* entity);
public:
	/**
	 * @brief Constructor that initializes the parser of the scene.
	 * @param sceneCreator The scene creator negotiator that can create elements on the scene.
	 */
	SceneParser(OgreSceneCreator* sceneCreator);
	/**
	 * @brief Parses the scene configuration file into a real scene.
	 */
	void parseScene();
};
#endif
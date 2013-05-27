#include <Parser/SceneParser.h>
#include <OgreSceneCreator.h>

SceneParser::SceneParser(OgreSceneCreator* sceneCreator){
	mSceneCreator = sceneCreator;
	mUriFile = PropertyLoader::getInstance().getPropertyValue("sceneLocation");
	mDoc.LoadFile(mUriFile.c_str());
}

void SceneParser::parseScene(){
	tinyxml2::XMLElement* rootElement = mDoc.FirstChildElement(GLOBAL_NODE);
	tinyxml2::XMLElement* elementNode = rootElement->FirstChildElement(SCENE_NODE);
	while (elementNode){
		Ogre::SceneNode* nodeParsed = parseSceneNode(elementNode);
		mSceneCreator->addNodeToRootNode(nodeParsed);
		elementNode = elementNode->NextSiblingElement(SCENE_NODE);
	}
	//TODO parse other elements like sky or global sounds.
}

Ogre::SceneNode* SceneParser::parseSceneNode(tinyxml2::XMLElement* node){

	return NULL;
}

Ogre::Entity* SceneParser::parseEntityNode(tinyxml2::XMLElement* node){
	Ogre::Entity* entity = mSceneCreator->createEntity(node->Attribute(ID), node->Attribute(RESOURCE));
	bool visible = node->FirstChildElement(ENTITY_VISIBILITY)->Attribute(VALUE);
	entity->setVisible(visible);
	return entity;
}
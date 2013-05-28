#include <Parser/SceneParser.h>
#include <OgreSceneCreator.h>

SceneParser::SceneParser(OgreSceneCreator* sceneCreator){
	mSceneCreator = sceneCreator;
	mUriFile = PropertyLoader::getInstance().getPropertyValue("sceneLocation");
	mDoc.LoadFile(mUriFile.c_str());
}

void SceneParser::parseScene(){
	tinyxml2::XMLElement* rootElement = mDoc.FirstChildElement(HCORE_GLOBAL_NODE);
	tinyxml2::XMLElement* elementNode = rootElement->FirstChildElement(HCORE_SCENE_NODE);
	while (elementNode){
		Ogre::SceneNode* nodeParsed = parseSceneNode(elementNode);
		mSceneCreator->addNodeToRootNode(nodeParsed);
		elementNode = elementNode->NextSiblingElement(HCORE_SCENE_NODE);
	}
	//TODO parse other elements like sky or global sounds.
}

Ogre::SceneNode* SceneParser::parseSceneNode(tinyxml2::XMLElement* node){
	Ogre::SceneNode* returnNode = mSceneCreator->createSceneNode(node->Attribute(HCORE_ID),false,false);

	tinyxml2::XMLElement* position = node->FirstChildElement(HCORE_NODE_POSITION);
	returnNode->setPosition(Ogre::Vector3(position->FloatAttribute(HCORE_X), position->FloatAttribute(HCORE_Y), position->FloatAttribute(HCORE_Z)));
	tinyxml2::XMLElement* direction = node->FirstChildElement(HCORE_NODE_DIRECTION);
	if(direction){
		returnNode->setDirection(Ogre::Vector3(position->FloatAttribute(HCORE_X), position->FloatAttribute(HCORE_Y), position->FloatAttribute(HCORE_Z)));
	}

	tinyxml2::XMLElement* entity = node->FirstChildElement(HCORE_ENTITY_NODE);
	while(entity){
		returnNode->attachObject(parseEntityNode(entity));
		entity = entity->NextSiblingElement(HCORE_ENTITY_NODE);
	}

	tinyxml2::XMLElement* sceneNode = node->FirstChildElement(HCORE_SCENE_NODE);
	while(sceneNode){
		returnNode->addChild(parseSceneNode(sceneNode));
		sceneNode = sceneNode->NextSiblingElement(HCORE_SCENE_NODE);
	}

	return returnNode;
}

Ogre::Entity* SceneParser::parseEntityNode(tinyxml2::XMLElement* node){
	Ogre::Entity* entity = mSceneCreator->createEntity(node->Attribute(HCORE_ID), node->Attribute(HCORE_RESOURCE));
	bool visible = node->FirstChildElement(HCORE_ENTITY_VISIBILITY)->BoolAttribute(HCORE_VALUE);
	entity->setVisible(visible);
	return entity;
}
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
	Ogre::SceneNode* returnNode = mSceneCreator->createSceneNode(node->Attribute(ID),false,false);

	tinyxml2::XMLElement* position = node->FirstChildElement(NODE_POSITION);
	returnNode->setPosition(Ogre::Vector3(position->FloatAttribute(X), position->FloatAttribute(Y), position->FloatAttribute(Z)));
	tinyxml2::XMLElement* direction = node->FirstChildElement(NODE_DIRECTION);
	if(direction){
		returnNode->setDirection(Ogre::Vector3(position->FloatAttribute(X), position->FloatAttribute(Y), position->FloatAttribute(Z)));
	}

	tinyxml2::XMLElement* entity = node->FirstChildElement(ENTITY_NODE);
	while(entity){
		returnNode->attachObject(parseEntityNode(entity));
		entity = entity->NextSiblingElement(ENTITY_NODE);
	}

	tinyxml2::XMLElement* sceneNode = node->FirstChildElement(SCENE_NODE);
	while(sceneNode){
		returnNode->addChild(parseSceneNode(sceneNode));
		sceneNode = sceneNode->NextSiblingElement(SCENE_NODE);
	}

	return returnNode;
}

Ogre::Entity* SceneParser::parseEntityNode(tinyxml2::XMLElement* node){
	Ogre::Entity* entity = mSceneCreator->createEntity(node->Attribute(ID), node->Attribute(RESOURCE));
	bool visible = node->FirstChildElement(ENTITY_VISIBILITY)->Attribute(VALUE);
	entity->setVisible(visible);
	return entity;
}
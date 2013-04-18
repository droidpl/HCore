#include <OgreSceneCreator.h>

//PUBLIC
OgreSceneCreator::OgreSceneCreator(OgreMediator* mediator, Ogre::Root* root){
	mMediator = mediator;
	//Ask for the SceneManager to the root element and use the properties file to select what
	//kind of scene manager we want to use
	mOpticWorld = root->createSceneManager(PropertyLoader::getInstance().getPropertyValue("sceneManager"), "MainSceneManager");
	//TODO create haptics
	//TODO creatre physics
	Ogre::Light* light = mOpticWorld->createLight( "MainLight" );
	light->setPosition(20, 80, 50);
	setAmbientLight(Ogre::ColourValue(0.7f, 0.7f, 0.7f));
}

OgreSceneCreator::~OgreSceneCreator(){}

Ogre::Entity* OgreSceneCreator::createEntity(string id, string resource){
	//TODO check if resource exists, else, load it.
	return mOpticWorld->createEntity(id, resource);
}

void OgreSceneCreator::addEntityToRootNode(Ogre::Entity* entity){
	mOpticWorld->getRootSceneNode()->attachObject(entity);
}

void OgreSceneCreator::addEntityToRootNode(string idEntity, string resource){
	addEntityToRootNode(createEntity(idEntity, resource));
}

void OgreSceneCreator::addEntityToNode(Ogre::Entity* entity, string idNode){
	mOpticWorld->getSceneNode(idNode)->attachObject(entity);
}

void OgreSceneCreator::addEntityToNode(string idEntity, string resource, string idNode){
	addEntityToNode(createEntity(idEntity, resource), idNode);
}

Ogre::SceneNode* OgreSceneCreator::createSceneNode(string idNode, bool hasPhysics, bool hasHaptics){
	Ogre::SceneNode* node = mOpticWorld->createSceneNode(idNode);
	addInteractionToNode(node, hasPhysics, hasHaptics);
	return node;
}

Ogre::SceneNode* OgreSceneCreator::createSceneNode(string idNode, Ogre::Entity* entity, bool hasPhysics, bool hasHaptics){
	Ogre::SceneNode* node = createSceneNode(idNode, hasPhysics, hasHaptics);
	addEntityToNode(entity, idNode);
	return node;
}

Ogre::SceneNode* OgreSceneCreator::createSceneNodeOnNode(string idNode, string idNodeWhere, bool hasPhysics, bool hasHaptics){
	Ogre::SceneNode* node = mOpticWorld->getSceneNode(idNodeWhere)->createChildSceneNode(idNode);
	addInteractionToNode(node, hasPhysics, hasHaptics);
	return node;
}

Ogre::SceneNode* OgreSceneCreator::createSceneNodeOnNode(string idNode, string idNodeWhere, Ogre::Entity* entity, bool hasPhysics, bool hasHaptics){
	Ogre::SceneNode* nodeCreated = createSceneNodeOnNode(idNode, idNodeWhere, hasPhysics, hasHaptics);
	addEntityToNode(entity, idNode);
	return nodeCreated;
}

Ogre::SceneNode* OgreSceneCreator::createSceneNodeOnNode(string idNode, string idNodeWhere, string idEntity, string resource, bool hasPhysics, bool hasHaptics){
	return createSceneNodeOnNode(idNode, idNodeWhere, createEntity(idEntity, resource), hasPhysics, hasHaptics);
}

void OgreSceneCreator::addInteractionToNode(Ogre::SceneNode* node, bool hasPhysics, bool hasHaptics){
	if (hasPhysics){
		//TODO Add physics to object
	}
	if (hasHaptics){
		//TODO Add haptics to object
	}
}

void OgreSceneCreator::addInteractionToNode(string idNode, bool hasPhysics, bool hasHaptics){
	addInteractionToNode(mOpticWorld->getSceneNode(idNode), hasPhysics, hasHaptics);
}

void OgreSceneCreator::setAmbientLight(Ogre::ColourValue const color){
	mOpticWorld->setAmbientLight(color);
}

void OgreSceneCreator::attachToExistingNode(string idNodeFrom, string idNodeTo){
	Ogre::SceneNode* sceneNodeFrom = mOpticWorld->getSceneNode(idNodeFrom);
}

void OgreSceneCreator::removeObject(string objectId){
	mOpticWorld->getRootSceneNode()->removeChild(objectId);
	//TODO remove physics and haptics if exist
}

void OgreSceneCreator::setSkyBox(string material, float distance, bool enabled, bool drawFirst){
	mOpticWorld->setSkyBox(enabled, material, distance, drawFirst);
}

Ogre::Light* OgreSceneCreator::createLight(string name, Ogre::Vector3 position){
	Ogre::Light* light = mOpticWorld->createLight(name);
	light->setPosition(position);
	return light;
}

Ogre::Camera* OgreSceneCreator::createCamera(string cameraId){
	Ogre::Camera* camera;
	try{
		//Get if exist
		camera = mOpticWorld->getCamera(cameraId);
	}catch(Ogre::Exception ex){
		//Create it instead
		camera = mOpticWorld->createCamera(cameraId);
		mOpticWorld->createSceneNode("camera")->attachObject(camera);
	}
	camera->setPosition(Ogre::Vector3(0,0,80));
	camera->lookAt(Ogre::Vector3(0,0,-300));
	camera->setNearClipDistance(5);
	return camera;
}
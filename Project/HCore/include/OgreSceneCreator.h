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

#ifndef _SceneCreator_H_
#define _SceneCreator_H_

/* INCLUDE */
#include <Utils/PropertyLoader.h>
#include <string>
#include <OgreSceneManager.h>
#include <OgreBulletDynamicsRigidBody.h>
#include <OgreCamera.h>
#include <HapticWorld.h>
#include <OgreString.h>
#include <OgreColourValue.h>
#include <OgreLight.h>

#include <Mediator/AbstractOgreNegotiator.h>
class OgreMediator;

/**
 * @brief Creates all the elements on the scene including it's physics and haptics.
 * 
 * Use this class to create all the elements, do not create them one by one because this will
 * free the memory when they are not needed.
 */
class OgreSceneCreator: protected AbstractOgreNegotiator {
private:
	//TODO add a tree with all the objects created
	Ogre::SceneManager*					mOpticWorld; /**< Graphic world (alias SceneManager for Ogre). */
	OgreBulletDynamics::DynamicsWorld*	mDynamicsWorld; /**< Dynamic world with physics. */
	HOgre::HapticWorld*					mHapticWorld; /**< Haptic world with all the haptics performance */
public:
	/**
	 * @brief Constructor for the scene creator element.
	 * 
	 * @param Needs the root to initialize the SceneManager.
	 */
	OgreSceneCreator(OgreMediator* mediator, Ogre::Root* root);
	/**
	 * @brief The destructor for the scene creator element.
	 */
	~OgreSceneCreator();
	 
	Ogre::Entity* createEntity(string id, string resource);
	
	void addEntityToRootNode(Ogre::Entity* entity);

	void addEntityToRootNode(string idEntity, string resource);

	void addEntityToNode(Ogre::Entity* entity, string idNode);

	void addEntityToNode(string idEntity, string resource, string idNode);

	Ogre::SceneNode* createSceneNode(string idNode, bool hasPhysics = true, bool hasHaptics = true);

	Ogre::SceneNode* createSceneNode(string idNode, Ogre::Entity* entity, bool hasPhysics = true, bool hasHaptics = true);

	Ogre::SceneNode* createSceneNodeOnNode(string idNode, string idNodeWhere, bool hasPhysics = true, bool hasHaptics = true);

	Ogre::SceneNode* createSceneNodeOnNode(string idNode, string idNodeWhere, Ogre::Entity* entity, bool hasPhysics = true, bool hasHaptics = true);

	Ogre::SceneNode* createSceneNodeOnNode(string idNode, string idNodeWhere, string idEntity, string resource, bool hasPhysics = true, bool hasHaptics = true);

	void addInteractionToNode(Ogre::SceneNode* node, bool hasPhysics, bool hasHaptics);

	void addInteractionToNode(string idNode, bool hasPhysics, bool hasHaptics);

	void setAmbientLight(Ogre::ColourValue const color = Ogre::ColourValue(0.7f, 0.7f, 0.7f));

	void setSkyBox(string material, float distance = 5000, bool enabled = true, bool drawFirst = false);

	Ogre::Light* createLight(string name, Ogre::Vector3 position = Ogre::Vector3(0,0,0));
	/**
	 * @brief Attaches one scene node into another.
	 * 
	 * @param idNodeAttached The node name we want to attach.
	 * @param idNode The node name of the node where we want to attach the previously
	 */
	void attachToExistingNode(string idNodeAttached, string idNode);
	/**
	 * @brief Removes one node from the scene.
	 *
	 * Remember that if you delete a node all it's referenced nodes will be deleted.
	 * @param The node name we want to remove.
	 */
	void removeObject(string objectId);
	/**
	 * @brief Creates a new camera with the id provided.
	 * 
	 * @param cameraId The camera identifier on the scene.
	 * @return The camera node of the scene.
	 */
	Ogre::Camera* createCamera(string cameraId);
};
#endif
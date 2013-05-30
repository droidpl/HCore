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
#include <Parser/SceneParser.h>

#include <Mediator/AbstractOgreNegotiator.h>
class OgreMediator;

/**
 * @brief Creates all the elements on the scene including it's physics and haptics.
 * 
 * Use this class to create all the elements, do not create them one by one because this will
 * free the memory when they are not needed. It also manages the physics and haptics behaviour on the 
 * objects of the scene. Do not free the memory alocated for this class yourself, that means, objects
 * created by this class are managed by ogre and must not be freed.
 * @author    Javier de Pedro Lopez
 * @version   1.0
 * @date      2013
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
	 /**
	  * @brief Creates a new Ogre entity to display elements on the scene.
	  *
	  * This function must be used everytime an entity is needed. DO NOT CREATE ENTITIES YOURSELF.
	  * @param id Identifier of the object in the scene graph.
	  * @param resource The resource to load (ex. ogrehead.mesh)
	  * @return The created entity.
	  */
	Ogre::Entity* createEntity(string id, string resource);
	/**
	  * @brief Adds the given entity to the root node on the scene graph.
	  *
	  * If you want to add an entity on the root scene element you have to use this function, not 
	  * the scene manager itself.
	  * @param entity The entity that will be added.
	  */
	void addEntityToRootNode(Ogre::Entity* entity);
	/**
	  * @brief Creates and adds an entity to the root node on the scene graph.
	  *
	  * If you want to add an entity on the root scene element you have to use this function, not 
	  * the scene manager itself.
	  * @param idEntity Identifier of the entity in the scene graph.
	  * @param resource The resource to load (ex. ogrehead.mesh)
	  */
	void addEntityToRootNode(string idEntity, string resource);
	/**
	  * @brief Adds the given node to the root scene element of the scene graph.
	  * If you want to add a Scene Node (Ogre) to the root of the scene graph use this function, 
	  * not the scene manager itself.
	  * @param node The node that will be added.
	  */
	void addNodeToRootNode(Ogre::SceneNode* node);
	/**
	  * @brief Adds an entity to the node referenced.
	  * 
	  * Perform a search on the scene graph in order to find a node with the given id. Once it
	  * is found, it attaches the entity to the node.
	  * @param entity The entity to add.
	  * @param idNode The identifier of the node.
	  */
	void addEntityToNode(Ogre::Entity* entity, string idNode);
	/**
	  * @brief Adds and creates a new entity to the given node.
	  * Perform a search on the scene graph in order to find a node with the given id. Once it
	  * is found, it attaches the new entity recently created to the node.
	  * @param idEntity Identifier of the entity in the scene graph.
	  * @param resource The resource to load (ex. ogrehead.mesh)
	  * @param idNode The identifier of the node.
	  */
	void addEntityToNode(string idEntity, string resource, string idNode);
	/**
	  * @brief Creates a new scene node.
	  *
	  * @param idNode The identifier of the created node. Must be unique.
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  * @return The node created.
	  */
	Ogre::SceneNode* createSceneNode(string idNode, bool hasPhysics = true, bool hasHaptics = true);
	/**
	  * @brief Creates a new scene node with a passed entity.
	  *
	  * @param idNode The identifier of the created node. Must be unique.
	  * @param entity Creates the node with the given entity.
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  * @return The node created.
	  */
	Ogre::SceneNode* createSceneNode(string idNode, Ogre::Entity* entity, bool hasPhysics = true, bool hasHaptics = true);
	/**
	  * @brief Creates a scene node inside another node that previously exists.
	  *
	  * @param idNode The identifier of the created node. Must be unique.
	  * @param idNodeWhere The identifier of the node that is previusly present on the scene.
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  * @return The node created.
	  */
	Ogre::SceneNode* createSceneNodeOnNode(string idNode, string idNodeWhere, bool hasPhysics = true, bool hasHaptics = true);
	/**
	  * @brief Creates a scene node inside another node that previously exists, attaching a given entity.
	  *
	  * @param idNode The identifier of the created node. Must be unique.
	  * @param idNodeWhere The identifier of the node that is previusly present on the scene.
	  * @param entity Creates the node with the given entity.
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  * @return The node created.
	  */
	Ogre::SceneNode* createSceneNodeOnNode(string idNode, string idNodeWhere, Ogre::Entity* entity, bool hasPhysics = true, bool hasHaptics = true);
	/**
	  * @brief Creates a scene node inside another node that previously exists, attaching a given entity.
	  *
	  * @param idNode The identifier of the created node. Must be unique.
	  * @param idNodeWhere The identifier of the node that is previusly present on the scene.
	  * @param idEntity Identifier of the entity in the scene graph.
	  * @param resource The resource to load (ex. ogrehead.mesh)
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  * @return The node created.
	  */
	Ogre::SceneNode* createSceneNodeOnNode(string idNode, string idNodeWhere, string idEntity, string resource, bool hasPhysics = true, bool hasHaptics = true);
	/**
	  * @brief Adds physics and habptic interaction to the node.
	  * @param node The node that will change its behaviour.
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  */
	void addInteractionToNode(Ogre::SceneNode* node, bool hasPhysics, bool hasHaptics);
	/**
	  * @brief Adds physics and habptic interaction to the node.
	  * @param idNode The unique identifier to search on  the scene graph.
	  * @param hasPhysics Include physic interaction (gravity and collisions) to the node.
	  * @param hasHaptics Include haptic interaction to the node.
	  */
	void addInteractionToNode(string idNode, bool hasPhysics, bool hasHaptics);
	/**
	  * @brief Creates the ambient light on the scene.
	  *
	  * @param color The color of the light.
	  */
	void setAmbientLight(Ogre::ColourValue const color = Ogre::ColourValue(0.7f, 0.7f, 0.7f));
	/**
	  * @brief Creates a skybox to decorate the scene.
	  * 
	  * Creates the skybox.
	  * @param material The name of the material the box will use.
	  * @param distance Distance in world coorinates from the camera to each plane of the box. The default is normally OK.
	  * @param enabled True to enable the skybox, false to disable it.
	  * @param drawFirst Identifies if the skybox must be drawn first.
	  */
	void setSkyBox(string material, float distance = 5000, bool enabled = true, bool drawFirst = false);
	/**
	  * @brief Creates a scene light.
	  *
	  * Creates a new light an places it on the scene depending on the given location.
	  * @param name The name that identifies the light created.
	  * @param position Place to put this light.
	  * @return The new light.
	  */
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
	/**
	  * @brief Using the default properties, it parses a scene from the XML uri stored in this properties.
	  * 
	  * Parses a scene following the HCore Scene XML Schema (It is stored on Media folder).
	  */
	void parseScene();
	/**
	 * @brief Adds or changes the pointer that will be displayed on the screen. It allows the change between tools in the surgery.
	 * @param resource The resource to load as a pointer.
	 */
	void addPointer(string resource);
};
#endif
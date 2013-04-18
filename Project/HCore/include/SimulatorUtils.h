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

#ifndef _SimulatorUtils_H_
#define _SimulatorUtils_H_

/* INCLUDE */
#include <Utils\OgreBulletCollisionsMeshToShapeConverter.h>
#include <OgreOggSoundManager.h>
#include <OgreOggISound.h>
#include <string>

/* NAMESPACE */
using namespace std;

/**
 * @brief Provides some useful options to perform activities like playing music or
 * modifying the triangle constructions of the figures.
 */
class SimulatorUtils {
private:
	/**
	 * @brief Constructor of the simulator utils. It's  not public because all it's members will be static.
	 */
	SimulatorUtils();
public:
	/**
	 * @brief Returns the ConvexHull for collisions.
	 * 
	 * @param entity The entity to convert.
	 * @return A ConvexHull to calculate the collisions.
	 */
	static OgreBulletCollisions::ConvexHullCollisionShape* getConvex(Ogre::Entity* entity);
	/**
	 * @brief Returns the TriangleMesh for collisions.
	 * 
	 * @param entity A entity to convert,
	 * @return The trimesh representation.
	 */
	static OgreBulletCollisions::TriangleMeshCollisionShape* getTrimesh(Ogre::Entity* entity);
	/**
	 * @brief Plays a sound in a place on the scene.
	 * 
	 * @param soundResource The resource name for the sound value.
	 * @param loop True if you want the sound to loop or false either.
	 * @return The boolean value that specifies if the sound initializes it's state.
	 */
	static bool playSound(string soundId, string soundResource, bool loop = false);
};
#endif
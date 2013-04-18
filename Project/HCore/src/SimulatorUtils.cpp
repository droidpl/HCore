#include <SimulatorUtils.h>

OgreBulletCollisions::ConvexHullCollisionShape* SimulatorUtils::getConvex (Ogre::Entity* entity){
	OgreBulletCollisions::StaticMeshToShapeConverter* converter = new OgreBulletCollisions::StaticMeshToShapeConverter();
	converter->addEntity(entity);
	OgreBulletCollisions::ConvexHullCollisionShape* convex = converter->createConvex();
	delete converter;
	return convex;
}

OgreBulletCollisions::TriangleMeshCollisionShape* SimulatorUtils::getTrimesh (Ogre::Entity* entity){
	OgreBulletCollisions::StaticMeshToShapeConverter* converter = new OgreBulletCollisions::StaticMeshToShapeConverter();
	converter->addEntity(entity);
	OgreBulletCollisions::TriangleMeshCollisionShape* trimesh = converter->createTrimesh();
	delete converter;
	return trimesh;
}

bool SimulatorUtils::playSound(string soundId, string soundResource, bool loop){
	bool result = true;
	//Load the sound and run it
	OgreOggSound::OgreOggSoundManager* soundManager = OgreOggSound::OgreOggSoundManager::getSingletonPtr();
	if (result = soundManager->init()){
		OgreOggSound::OgreOggISound* sound = NULL;
		// Create a sound and play
		if ((sound = soundManager->getSound(soundId)) || (sound = soundManager->createSound(soundId, soundResource))){
			sound->loop(loop);
			sound->play();
		}else{
			result = false;
		}
	}
	return result;
}
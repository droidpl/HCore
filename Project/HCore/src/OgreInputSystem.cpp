#include <OgreInputSystem.h>

OgreInputSystem::OgreInputSystem(Ogre::RenderWindow* window){
	//Standard OIS render system creation
	OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    window->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    mInputManager = OIS::InputManager::createInputSystem( pl );
}

OIS::Object* OgreInputSystem::createInputObject(OIS::Type type, bool bufferMode){
	return mInputManager->createInputObject(type, bufferMode);
}

void OgreInputSystem::destroyInputObject(OIS::Object* inputObject){
	mInputManager->destroyInputObject(inputObject);
}
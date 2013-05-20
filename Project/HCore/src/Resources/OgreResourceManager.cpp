#include <Resources/OgreResourceManager.h>

OgreResouceManager::OgreResouceManager(OgreMediator* mediator){
	mMediator = mediator;
	#ifdef _DEBUG
		mResourcesCfg = "./Configuration/resources_d.cfg";
	#else
		mResourcesCfg = "./Configuration/resources.cfg";
	#endif

	//Load resource paths from config file
    Ogre::ConfigFile configFile;
    configFile.load(mResourcesCfg);
	//Go through all sections & settings in the file and load them
	Ogre::ConfigFile::SectionIterator seci = configFile.getSectionIterator();
	//Declare sectionName, type (zip or fileSystem) and document to load
	Ogre::String secName, typeName, archName;
	while (seci.hasMoreElements()){
		secName = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i){
			typeName = i->first;
			archName = i->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
				archName, typeName, secName);
		}
	}
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
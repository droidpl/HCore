#include <Parser/SceneParser.h>
#include <OgreSceneCreator.h>

SceneParser::SceneParser(OgreSceneCreator* sceneCreator){
	mSceneCreator = sceneCreator;
	mUriFile = PropertyLoader::getInstance().getPropertyValue("sceneLocation");
}


void SceneParser::parseScene(){

}
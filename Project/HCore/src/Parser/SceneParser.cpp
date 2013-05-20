#include <Parser/SceneParser.h>


SceneParser::SceneParser(const OgreSceneCreator* sceneCreator){
	//mSceneCreator = sceneCreator;
	mUriFile = PropertyLoader::getInstance().getProperty("sceneLocation");
}


void SceneParser::parseScene(){

}
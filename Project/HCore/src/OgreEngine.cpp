#include <OgreEngine.h>

//PRIVATE
bool OgreEngine::setup(){
	//Construct Ogre::Root with plugin configuration
	mRoot = new Ogre::Root(mPluginsCfg);
	//Set properties
	PropertyLoader::getInstance().loadProperties("./Configuration/simulator.properties");
	//Set window configuration and show the dialog if needed
	bool mustContinue = configure();
	if (!mustContinue) return false;
	else{
		//Initialize all components
		return true;
	}
}

bool OgreEngine::configure(){
	#ifdef _DEBUG
		Ogre::RenderSystem *renderSystem = mRoot->getRenderSystemByName("Direct3D9 Rendering Subsystem");
		mRoot->setRenderSystem(renderSystem);
		renderSystem->setConfigOption("Full Screen", "No");
		renderSystem->setConfigOption("Video Mode", "1680 x 1050 @ 32-bit colour");
	#else
		//Show configuration dialog for the first time
		if(!(mRoot->restoreConfig() || mRoot->showConfigDialog()))
		{
			return false;
		}
	#endif
	//Initialize the window
	mWindow = mRoot->initialise(true, PropertyLoader::getInstance().getPropertyValue("simulatorName"));
	mRoot->addFrameListener(this);
	return true;
}

//PROTECTED
bool OgreEngine::frameRenderingQueued(const Ogre::FrameEvent& evt){
	//If we close the window we must stop the render process and 
	//return the control to the user.
	return !mWindow->isClosed();
}

//PUBLIC
OgreEngine::OgreEngine(OgreMediator* mediator){
	mMediator = mediator;
	mCurrentViewport = NULL;
	//Select the resources and plugin name files
	#ifdef _DEBUG
		mPluginsCfg = "./Configuration/plugins_d.cfg";
	#else
		mPluginsCfg = "./Configuration/plugins.cfg";
	#endif
}

OgreEngine::~OgreEngine(){
	//The only element created is Ogre::Root. It removes also the window and everithing related to Ogre::Root
	delete mRoot;
}

bool OgreEngine::initEngine(){
	//Try to do the setup of the application
	if (!setup())
		return false;
	return true;
}

void OgreEngine::startRendering(){
	LogAPI::getInstance().logMessage("Rendering process started.", typeid(this).name());
	//Start the render process loop
	mRoot->startRendering();
}

void OgreEngine::addViewport(Ogre::Camera* camera){
	//Remove the current viewport
	if (mCurrentViewport) {
		mWindow->removeViewport(mCurrentViewport->getZOrder());
	}
	//Add the new viewport with the camera
	mCurrentViewport = mWindow->addViewport(camera);
	//Change the aspect retio
	camera->setAspectRatio(Ogre::Real(mCurrentViewport->getActualWidth()) / Ogre::Real(mCurrentViewport->getActualHeight()));
	LogAPI::getInstance().logMessage("New camera added to viewport.", typeid(this).name());
}

void OgreEngine::addRenderListener(OgreRenderObserver* renderListener){
	mRoot->addFrameListener((Ogre::FrameListener*)renderListener);
	LogAPI::getInstance().logMessage("New render listener added.", typeid(this).name());
}

void OgreEngine::detachRenderListener(OgreRenderObserver* renderListener){
	mRoot->removeFrameListener((Ogre::FrameListener*)renderListener);
	LogAPI::getInstance().logMessage("Render listener detached.", typeid(this).name());
}
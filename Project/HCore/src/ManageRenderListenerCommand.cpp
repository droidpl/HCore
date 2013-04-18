#include <ManageRenderListenerCommand.h>

ManageRenderListenerCommand::ManageRenderListenerCommand(
	OgreRenderObserverRegistry* observerRegistry, 
	OgreEngine* engine,
	string action):
		mObserverRegistry(observerRegistry),
		mEngine(engine),
		mAction(action){
}

void ManageRenderListenerCommand::execute(){
	if (mAction.compare("add") == 0){
		mEngine->addRenderListener(mObserverRegistry->getCachedObserver());
	}else if (mAction.compare("detach") == 0){
		mEngine->detachRenderListener(mObserverRegistry->getCachedObserver());
	}
}
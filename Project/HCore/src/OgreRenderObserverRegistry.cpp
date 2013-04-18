#include <OgreRenderObserverRegistry.h>

//PRIVATE
bool OgreRenderObserverRegistry::deleteRenderObserver(OgreRenderObserver* renderObserver){ 
	//Release the memory of the list detaching all render listeners
	mCacheLastObserver = renderObserver;
	string commandName = "manageRenderListener";
	string commandType = "detach";
	LogAPI::getInstance().logMessage("Command: " + commandName + " " + commandType + " sent.", typeid(this).name());
	NegotiatorEvent evt(commandName, commandType);
	notifyMediator(evt);
	flushCache();
	delete renderObserver; 
	return true;
}

//PUBLIC
OgreRenderObserverRegistry::OgreRenderObserverRegistry(OgreMediator* mediator){
	mMediator = mediator;
	mCacheLastObserver = NULL;
}

OgreRenderObserverRegistry::~OgreRenderObserverRegistry(){
	//Remove_if used to release the memory on the heap if there are elements on mRenderObservers
	//bind1st(mem_fun(&OgreRenderObserverRegistry::deleteRenderObserver), this) binds the member function to this object to be passed as argument
	remove_if(mRenderObservers.begin(), mRenderObservers.end(), bind1st(mem_fun(&OgreRenderObserverRegistry::deleteRenderObserver), this));
}

void OgreRenderObserverRegistry::addListener(RenderListener* renderListener){
	////Add a new render observer
	string commandName = "manageRenderListener";
	string commandType = "add";
	mCacheLastObserver = new OgreRenderObserver(renderListener);
	mRenderObservers.push_back(mCacheLastObserver);
	//LogAPI::getInstance().logMessage("Command: " + commandName + " " + commandType + " sent.", typeid(this).name());
	NegotiatorEvent evt(commandName, commandType);
	notifyMediator(evt);
}

void OgreRenderObserverRegistry::detachListener(RenderListener* renderListener){
	//Create the event to detach
	string commandName = "manageRenderListener";
	string commandType = "detach";
	LogAPI::getInstance().logMessage("Command: " + commandName + " " + commandType + " sent.", typeid(this).name());
	NegotiatorEvent evt(commandName, commandType);

	//Select the render listener
	list<OgreRenderObserver*>::iterator it;
	it = mRenderObservers.begin();
	while(it != mRenderObservers.end() && 
		!(*it)->matchListener(renderListener))
	{ ++it; }

	//Cache it
	mCacheLastObserver = *it;

	//Remove from engine before delete
	notifyMediator(evt);

	//Delete observer memory allocation
	delete *it;

	//Remove the pointer from the list
	mRenderObservers.remove(*it);
	LogAPI::getInstance().logMessage("Render observer deleted.", typeid(this).name());

	//Flush this cache
	flushCache();
}
#include <LogAPI.h>

/* OGRE INCLUDES */
#include <OgreLogManager.h>

class LogAPI::Facade {
public:
	void logMessage(const string message, const string className){
		Ogre::LogManager::getSingleton().logMessage("|---> " + className + " - \n" + message);
	}
};

LogAPI::LogAPI(): pImpl(new Facade()){}

void LogAPI::logMessage(const string message, const string className){
	pImpl->logMessage(message, className);
}
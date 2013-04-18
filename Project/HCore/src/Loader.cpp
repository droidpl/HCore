#include <Loader.h>

/* FACADE INCLUDES */
#include <OgreException.h>
#include <windows.h>

//PRIVATE
/**
 * @brief Hides the framework initialization and exception management.
 *
 * @author    Javier de Pedro Lopez
 * @version   0.1
 * @date      2013
 */
class Loader::Facade {
public:
	/**
	 * @brief Initializes the surgery framework and all its components.
	 */
	bool initFramework (){
		try {
			//Init the framework using the SceneServices singleton
			return SimulatorAPI::getInstance().initFramework();
		} catch( Ogre::Exception& e ) {
			//Print the Ogre exception if needed to understand somo Ogre related errors
			#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
				MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
			#else
				std::cerr << "An exception has occured: " <<
					e.getFullDescription().c_str() << std::endl;
			#endif
			return false;
		}
	}
};

//PUBLIC
Loader::Loader() : pImpl(new Facade()){}

Loader::~Loader(){}

bool Loader::go(){
	//Initialize the framework if the subclass call super::go();
	return pImpl->initFramework();
}

#include <SimulatorAPI.h>

/* FACADE INCLUDES */
#include <Mediator/OgreMediator.h>

//PRIVATE
/**
 * @brief The facade that contains the private implementation of the scene services.
 *
 * You can't use it directrly because it's part of the implementation, but you also don't need it. @see Facade pattern
 */
class SimulatorAPI::Facade {
public:
	OgreMediator*		mMediator; /**< The mediator between components of the simulator.*/

	Facade(){
		mMediator = new OgreMediator();
	}

	/**
	 * @brief Initializes the surgery framework. You shouldn't call it if you have used the super::Loader call.
	 *
	 * @return A boolean value explaining if everything went oke in the initializationn process.
	 */
	bool initFramework(){
		return mMediator->initFramework();
	}

	/**
	 * @brief Starts the render loop.
	 *
	 * Every instruction following this will not be executed until the render loop ends, so be careful because
	 * those instructions can cause the death of the program with runtime errors.
	 */
	void startRendering(){
		mMediator->startRendering();
	}

	void addRenderListener(RenderListener* renderListener){
		mMediator->addRenderListener(renderListener);
	}

	void detachRenderListener(RenderListener* renderListener){
		mMediator->detachRenderListener(renderListener);
	}

	/**
	 * @brief Destructor of the facade element.
	 */
	~Facade(){
		delete mMediator;
	}
};

SimulatorAPI::SimulatorAPI() : pImpl(new Facade()){}
SimulatorAPI::~SimulatorAPI(){}

bool SimulatorAPI::initFramework(){
	return pImpl->initFramework();
}

void SimulatorAPI::startRendering(){
	pImpl->startRendering();
}

void SimulatorAPI::addRenderListener(RenderListener* renderListener){
	pImpl->addRenderListener(renderListener);
}

void SimulatorAPI::detachRenderListener(RenderListener* renderListener){
	pImpl->detachRenderListener(renderListener);
}
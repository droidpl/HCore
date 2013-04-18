#include "CataractSimulator.h"

//PUBLIC
CataractSimulator::CataractSimulator(){}
CataractSimulator::~CataractSimulator(){}
void CataractSimulator::runSimulator(){
	//SimulatorAPI::getInstance().addRenderListener((RenderListener*)this);
	SimulatorAPI::getInstance().startRendering();
}
void CataractSimulator::pauseSimulator(){}
void CataractSimulator::resumeSimulator(){}
void CataractSimulator::stopSimulator(){}
void CataractSimulator::onUpdate (RenderEvent& renderEvent){
	LogAPI::getInstance().logMessage("Rendering", typeid(this).name());
	//SimulatorAPI::getInstance().detachRenderListener((RenderListener*)this);
}
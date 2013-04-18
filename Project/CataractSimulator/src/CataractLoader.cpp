#include "CataractLoader.h"

//PUBLIC
bool CataractLoader::go() {
	bool result = super::go();
	mSimulator->runSimulator();
	return result;
}

//STARTING SCRIPT
//-------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

#if _DEBUG
    int main(int argc, char *argv[])
#else
	#include "windows.h"
	INT WINAPI WinMain ( HINSTANCE hInst, HINSTANCE, LPSTR strCmpLine, INT)
#endif
    {
        // Create application object
        CataractLoader application;
        application.go();
        return 0;
    }
#ifdef __cplusplus
}
#endif
//-------------------------------------------------------------------------------------
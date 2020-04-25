#include "VRSystem.h"


using namespace vr;

void VRHandler::initializeVRSystem() {

	//VRsuitable();


	HmdError errorCode;
	ivrSystem = VR_Init(&errorCode, EVRApplicationType::VRApplication_Utility);





	std::cout << "VR System Successfully initialized";

}


void VRHandler::isVRsuitable() {

	if (!VR_IsHmdPresent()) {
		std::cout << "HMD Not Detected" << std::endl;
		cleanUpVRSystem();
	}

	if (!VR_IsRuntimeInstalled()) {
		std::cout << "VR Runtime not found" << std::endl;
		cleanUpVRSystem();
	}


}

void VRHandler::cleanUpVRSystem() {

	VR_Shutdown();
}
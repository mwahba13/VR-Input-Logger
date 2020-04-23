#include "VRSystem.h"


using namespace vr;

void VRHandler::initializeVRSystem() {

	isVRsuitable();



	HmdError errorCode;
	ivrSystem = VR_Init(&errorCode, EVRApplicationType::VRApplication_Utility);

	if (errorCode != HmdError::VRInitError_None) {
		std::cout << GetEnglishStringForHmdError(errorCode) << std::endl;
		cleanUpVRSystem();
	}

	for (int i = k_unTrackedDeviceIndex_Hmd; i < k_unMaxTrackedDeviceCount; i++) {

		if (ivrSystem->IsTrackedDeviceConnected(i)) {
			*deviceClass = ivrSystem->GetTrackedDeviceClass(i);
		}

	}

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
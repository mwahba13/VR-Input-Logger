// VR Input Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "VRSystem.h"
#include "CSVLogger.h"

//NOTE: Comment out appropriate line if you plan on standing or sitting
//ETrackingUniverseOrigin ABS_TRACKING_POSE = TrackingUniverseSeated;
ETrackingUniverseOrigin ABS_TRACKING_POSE = TrackingUniverseStanding;



int main()
{


	VRHandler handler;
	handler.initializeVRSystem();
	//CSVLogger logger();



	while (true) {


		for (unsigned int deviceId = 0; deviceId < k_unMaxTrackedDeviceCount; deviceId++) {
			TrackedDevicePose_t trackedDevicePose;
			VRControllerState001_t controllerState;

			ETrackedDeviceClass deviceClass = handler.ivrSystem->GetTrackedDeviceClass(deviceId);

			if (!handler.ivrSystem->IsTrackedDeviceConnected(deviceId)) {
				continue;
			}

			if (deviceClass == ETrackedDeviceClass::TrackedDeviceClass_HMD) {
				//get head tracker stuff
				handler.ivrSystem->GetDeviceToAbsoluteTrackingPose(ABS_TRACKING_POSE, 0, &trackedDevicePose, 1);

				

			}

			if (deviceClass == ETrackedDeviceClass::TrackedDeviceClass_Controller) {
				handler.ivrSystem->GetControllerStateWithPose(ABS_TRACKING_POSE, deviceId, &controllerState, sizeof(controllerState), &trackedDevicePose);
				

				if (handler.ivrSystem->GetControllerRoleForTrackedDeviceIndex(deviceId) == ETrackedControllerRole::TrackedControllerRole_LeftHand) {
					//get left hand stuff
					std::cout << controllerState.ulButtonPressed << std::endl;
				}

				else if (handler.ivrSystem->GetControllerRoleForTrackedDeviceIndex(deviceId) == ETrackedControllerRole::TrackedControllerRole_RightHand) {
					//get right hand stuff

				}
			}



		}
		

	}

	
}


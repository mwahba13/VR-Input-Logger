// VR Input Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <csignal>
#include <Windows.h>
#include "VRSystem.h"
#include "CSVLogger.h"


ETrackingUniverseOrigin ABS_TRACKING_POSE = TrackingUniverseStanding;
std::string FILE_NAME = "VR_Input_Logger.csv";


using namespace std;


int main()
{

	bool inputFlag = false;
	bool enoughTimePassed = true;

	

	std::string begin;
	std::cout << "Once your headset is on and you are ready to start logging, Type B into the console to begin."<<std::endl;
	std::cin >> begin;
	if (begin == "b" || begin == "B")
		inputFlag = !inputFlag;
		
	VRHandler handler;
	handler.initializeVRSystem();

	CSVLogger logger(FILE_NAME);
	logger.openFile();

	std::cout << "\nLogging...When done, please turn off the HMD or let it go to sleep"<<std::endl;

	logger.setStartTimer();
	while (inputFlag) {


		if (enoughTimePassed) {


			logger.then = logger.timer.now();

			logger.setTimepoint();
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
					logger.setHMD(trackedDevicePose);

				}

				if (deviceClass == ETrackedDeviceClass::TrackedDeviceClass_Controller) {

					handler.ivrSystem->GetControllerStateWithPose(ABS_TRACKING_POSE, deviceId, &controllerState, sizeof(controllerState), &trackedDevicePose);

					if (handler.ivrSystem->GetControllerRoleForTrackedDeviceIndex(deviceId) == ETrackedControllerRole::TrackedControllerRole_LeftHand) {
						//get left hand stuff
						logger.setController(controllerState, trackedDevicePose, handler.ivrSystem, deviceId, false);
					}

					else if (handler.ivrSystem->GetControllerRoleForTrackedDeviceIndex(deviceId) == ETrackedControllerRole::TrackedControllerRole_RightHand) {
						//get right hand stuff
						logger.setController(controllerState, trackedDevicePose, handler.ivrSystem, deviceId, true);
					}
				}



			}

			logger.writeToFile();



			enoughTimePassed = !enoughTimePassed;

		}


		VREvent_t event;
		handler.ivrSystem->PollNextEvent(&event, sizeof(event));
		if (event.eventType == VREvent_EnterStandbyMode || event.eventType == VREvent_TrackedDeviceUserInteractionEnded) {
			std::cout << "Standby mode entered" << std::endl;
			inputFlag = !inputFlag;
		}

		

		logger.timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(logger.timer.now() - logger.then);
		if (logger.timeElapsed.count() >= 1.0) {
			enoughTimePassed = !enoughTimePassed;
		}


	}



		

	handler.cleanUpVRSystem();
	logger.closeFile();
	std::cout << "Logging complete" << std::endl;
}


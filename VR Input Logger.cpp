// VR Input Lovver.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	CSVLogger logger;



	while (true) {


		//get right controller
		handler.ivrSystem->GetControllerStateWithPose(ABS_TRACKING_POSE, 2, handler.r_deviceState, sizeof(handler.r_deviceState), handler.r_devicePose);

		//get left controller
		handler.ivrSystem->GetControllerStateWithPose(ABS_TRACKING_POSE, 1, handler.l_deviceState, sizeof(handler.l_deviceState), handler.l_devicePose);




	}


}


// VR Input Lovver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "VRSystem.h"

//NOTE: Comment out appropriate line if you plan on standing or sitting
ETrackingUniverseOrigin ABS_TRACKING_POSE = TrackingUniverseSeated;
//ETrackingUniverseOrigin ABS_TRACKING_POSE = TrackingUniverseStanding;



int main()
{

	VRHandler handler;
	handler.initializeVRSystem();


	while (true) {

		if (handler.ivrSystem != NULL) {

			

			handler.ivrSystem->GetDeviceToAbsoluteTrackingPose(TrackingUniverseSeated, 0,handler.devicePose , k_unMaxTrackedDeviceCount);

			for (int i = 0; i < k_unMaxTrackedDeviceCount; i++) {

				if ((handler.devicePose[i]))

			}

		}


	}


}


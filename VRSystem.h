#pragma once

#include "includes/openvr.h"
#include "includes/hmderrors_public.h"
#include <stdexcept>
#include <iostream>

using namespace vr;


	class VRHandler
	{

	public:
		void initializeVRSystem();
		void cleanUpVRSystem();

		IVRSystem* ivrSystem;
		TrackedDevicePose_t* devicePose;


	private:
		
		void isVRsuitable();

		
		ETrackedDeviceClass* deviceClass;
		ETrackedDeviceProperty* deviceName;



	};


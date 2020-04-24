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

		TrackedDevicePose_t* l_devicePose;
		VRControllerState001_t* l_deviceState;

		TrackedDevicePose_t* r_devicePose;
		VRControllerState001_t* r_deviceState;

	private:
		
		void isVRsuitable();





	};


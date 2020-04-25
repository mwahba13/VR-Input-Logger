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

		IVRSystem* ivrSystem = NULL;

		TrackedDevicePose_t* devicePose = NULL;

		VRControllerState001_t* l_controlState = nullptr;
		VRControllerState001_t* r_controlState = nullptr;

		
	private:
		
		void isVRsuitable();



		

	};


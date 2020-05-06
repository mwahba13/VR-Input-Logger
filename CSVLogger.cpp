//#define AXIS_TRACKPAD = 1;
//#define AXIS_JOYSTICK = 2;
//#define AXIS_TRIGGER = 3;




#include "CSVLogger.h"

using namespace vr;
using namespace std::chrono;

CSVLogger::CSVLogger(std::string path) {

	filename = path;
	
}

void CSVLogger::setStartTimer() {
	start = timer.now();
}

void CSVLogger::setTimepoint() {
	nextTime = timer.now();

	timeStamp = duration_cast<duration<double>>(nextTime - start);

}

void CSVLogger::openFile() {

	outputFile.open(filename, std::fstream::out);


	outputFile <<"Time," <<"Head Position," << "Right Controller Position," <<"Right Trigger,"<<"Right Trackpad," << "Left Controller Position," << "Left Trigger,"<<"Left Trackpad,"<<std::endl;
}

void CSVLogger::writeToFile() {
	
	std::string debugString = std::to_string(timeStamp.count()) + "," + convertVec3ToString(headSet.position) + "," + convertControllerToString(rightController) + ","
		+ convertControllerToString(leftController);
		
	//std::cout << debugString << std::endl;
	outputFile << timeStamp.count() << "," << convertVec3ToString(headSet.position) << "," << convertControllerToString(rightController) << "," << convertControllerToString(leftController) << std::endl;
}

void CSVLogger::closeFile() {

	outputFile.close();
}



void CSVLogger::setHMD(TrackedDevicePose_t pose) {

	HMD tempHMD;
	tempHMD.position = convertMatrixToVec3(pose.mDeviceToAbsoluteTracking);

	headSet = tempHMD;

}

void CSVLogger::setController( VRControllerState001_t state, TrackedDevicePose_t pose,IVRSystem* system,unsigned int deviceID,  bool isRight) {

	controller tempControl;


	//get analog trigger and trackpad data
	VRControllerAxis_t axis_trig = state.rAxis[1];
	tempControl.trigger1 = axis_trig.x;

	VRControllerAxis_t axis_pad = state.rAxis[k_eControllerAxis_TrackPad];
	tempControl.x_trackpad = axis_pad.x;
	tempControl.y_trackpad = axis_pad.y;
	

	
	//get position and rotational data
	tempControl.position = convertMatrixToVec3(pose.mDeviceToAbsoluteTracking);

	if (isRight)
		rightController = tempControl;
	else
		leftController = tempControl;

}

std::string CSVLogger::convertVec3ToString(HmdVector3_t vec) {

	return( "(" + std::to_string(vec.v[0]) + ";" + std::to_string(vec.v[1]) + ";" + std::to_string(vec.v[2]) + ")");

}


std::string CSVLogger::convertControllerToString(controller control) {

	std::string out;
	return out = convertVec3ToString(control.position) + "," + std::to_string(control.trigger1) + "," +"(" + std::to_string(control.x_trackpad)+ ";" + std::to_string(control.y_trackpad) + ")";
}

HmdVector3_t CSVLogger::convertMatrixToVec3(HmdMatrix34_t mat) {
	HmdVector3_t temp;
	temp.v[0] = mat.m[0][3];
	temp.v[1] = mat.m[1][3];
	temp.v[2] = mat.m[2][3];

	return temp;

}




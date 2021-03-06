#pragma once
#include "includes/openvr.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include "VRSystem.h"

using namespace vr;




struct HMD {

	HmdVector3_t position;

};

struct controller {


	float trigger1 = 0.;
	float x_trackpad = 0.;
	float y_trackpad = 0.;

	HmdVector3_t position;

};

class CSVLogger
{



private:


	std::ofstream outputFile;
	std::string filename;

	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> nextTime;



	std::chrono::duration<double> timeStamp;

	

	controller leftController;
	controller rightController;
	HMD headSet;
	

	HmdVector3_t convertMatrixToVec3(HmdMatrix34_t);

	std::string convertControllerToString(controller);
	std::string convertVec3ToString(HmdVector3_t);

public:

	std::chrono::steady_clock timer;
	std::chrono::time_point<std::chrono::steady_clock> now;
	std::chrono::time_point<std::chrono::steady_clock> then;
	std::chrono::duration<double> timeElapsed;
	
	void setController(VRControllerState001_t,  TrackedDevicePose_t , IVRSystem*,unsigned int, bool );
	void setHMD(TrackedDevicePose_t);
	void setTimepoint();
	void setStartTimer();
	void logTime();
	bool ifEnoughTimePassed();

	void openFile();
	void writeToFile();
	void closeFile();

	CSVLogger(std::string path);

};






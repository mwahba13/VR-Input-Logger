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
	float trigger2 = 0.;
	int trigAxisNum = 0;
	bool button1 = 0;
	bool button2 = 0;
	bool button3 = 0;
	bool button4 = 0;

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
	std::chrono::steady_clock timer;
	

	controller leftController;
	controller rightController;
	HMD headSet;
	

	HmdVector3_t convertMatrixToVec3(HmdMatrix34_t);

	std::string convertControllerToString(controller);
	std::string convertVec3ToString(HmdVector3_t);

public:
	
	void setController(VRControllerState001_t,  TrackedDevicePose_t , IVRSystem*,unsigned int, bool );
	void setHMD(TrackedDevicePose_t);
	void setTimepoint();
	void setStartTimer();
	void logTime();

	void openFile();
	void writeToFile();
	void closeFile();

	CSVLogger(std::string path);

};






#pragma once
#include "includes/openvr.h"
#include <fstream>
#include <iostream>
#include <string>
#include "VRSystem.h"

using namespace vr;

class CSVLogger
{



private:

	std::ofstream outputFile;
	std::ofstream fs;
	std::string filename = "VR_Input_Data.csv";


	void closeFile();

public:
	
	void logInput(VRHandler*);

	CSVLogger();

};


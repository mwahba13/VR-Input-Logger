//#define AXIS_TRACKPAD = 1;
//#define AXIS_JOYSTICK = 2;
//#define AXIS_TRIGGER = 3;




#include "CSVLogger.h"

using namespace vr;


CSVLogger::CSVLogger() {

	outputFile.open(filename, std::fstream::out);

	outputFile << "Right Position," << "Right Trigger," << "Left Position," << "Left Trigger";


}


void
CSVLogger::closeFile() {

	outputFile.close();
}

void
CSVLogger::logInput(VRHandler* handler) {


	
	
		



}
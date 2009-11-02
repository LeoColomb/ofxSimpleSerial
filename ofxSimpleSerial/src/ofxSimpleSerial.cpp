#include "ofxSimpleSerial.h" 


//------------------------------------------------- 
void ofxSimpleSerial::setup()
{
	initSetup();
	serial.setup();
}
void ofxSimpleSerial::setup(int deviceNumber, int baud)
{
	initSetup();
	serial.setup(deviceNumber,baud);
}
void ofxSimpleSerial::setup(string portName, int baud)
{ 
	initSetup();
	serial.setup(portName, baud);
}
void ofxSimpleSerial::initSetup()
{ 
	bReadSerialMessage = false;
	countCycles = 0;
	readInterval = 5;
	
	ofAddListener(ofEvents.update, this, &ofxSimpleSerial::update);
}

void ofxSimpleSerial::update(ofEventArgs & args)
{
	// only read when ready
	if (bReadSerialMessage)
	{
		// clear the message buffer
		memset(bytesReturned,0,NUM_BYTES);
		
		// Read all bytes from serial message
		while (serial.readBytes(bytesReturned, NUM_BYTES) > 0) { }
		
		bReadSerialMessage = false;
	}
	
	// let's make sure we don't read faster than the Arduino for example can handle
	countCycles++;
	if(countCycles == readInterval)
	{
		bReadSerialMessage = true;
		countCycles = 0;
	}
}


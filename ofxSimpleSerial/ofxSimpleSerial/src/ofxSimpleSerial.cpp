#include "testApp.h"


//--------------------------------------------------------------

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
	message = "";
	messageBuffer = "";
}

void ofxSimpleSerial::sendRequest()
{
	serial.writeByte('r');
	read();
}

void ofxSimpleSerial::startContinuesRead()
{
	ofAddListener(ofEvents.update, this, &ofxSimpleSerial::update);
}
void ofxSimpleSerial::stopContinuesRead()
{
	ofRemoveListener(ofEvents.update, this, &ofxSimpleSerial::update);
}
void ofxSimpleSerial::update(ofEventArgs & args)
{
	sendRequest();
}


void ofxSimpleSerial::read()
{
	// if we've got new bytes
	if(serial.available() > 0)
	{
	   // we wil keep reading until nothing is left
		while (serial.available() > 0)
		{
		   // we'll put the incoming bytes into bytesReturned
		   serial.readBytes(bytesReturned, NUM_BYTES);
		
		   // if we find the splitter we put all the buffered messages 
		   //   in the final message.
		   // else we just keep filling the buffer with incoming bytes. 
		   if(*bytesReturned == '|')
			{
			   message = messageBuffer;
			   messageBuffer = "";
			}
			else 
			{
			   messageBuffer += *bytesReturned;
			}
		}
		
		// clear the message buffer
		memset(bytesReturned,0,NUM_BYTES);
	}
}
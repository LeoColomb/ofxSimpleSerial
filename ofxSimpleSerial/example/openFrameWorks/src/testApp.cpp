#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	serial.setup("/dev/tty.usbserial-A70060V8", 9600);
}

void testApp::update()
{
	bytesReturned = *serial.bytesReturned;
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	if(bytesReturned == 'r')
		ofBackground(255, 0, 0);
	else if(bytesReturned == 'g')
		ofBackground(0, 255, 0);
	else if(bytesReturned == 'b')
		ofBackground(0, 0, 255);
	else if(bytesReturned == 'x')
		ofBackground(0, 0, 0);
}
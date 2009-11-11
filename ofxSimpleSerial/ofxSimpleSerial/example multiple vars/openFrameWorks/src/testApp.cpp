#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	serial.startContinuesRead();
	ofAddListener(serial.NEW_MESSAGE,this,&testApp::onNewMessage);
	
	message = "";
}

void testApp::onNewMessage(string & message)
{
	cout << "onNewMessage, message: " << message << "\n";
	
	vector<string> input = ofSplitString(message, ",");
	
	if(input.size() >= 3)
	{
	   red =	input.at(0) == "r";
	   green =	input.at(1) == "g";
	   blue =	input.at(2) == "b";
	}
}

void testApp::update()
{
	if(requestRead)
	 {
		cout << "sendRequest\n";
		serial.sendRequest();
		requestRead = false;
	 }
}

//--------------------------------------------------------------
void testApp::draw()
{
	if(red)
	 {
		ofSetColor(255, 0, 0);
		ofRect(0, 0, 33, 100);
	 }
	if(green)
	 {
		ofSetColor(0, 255, 0);
		ofRect(33, 0, 33, 100);
	 }
	if(blue)
	 {
		ofSetColor(0, 0, 255);
		ofRect(66, 0, 33, 100);
	 }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	requestRead = true;
}
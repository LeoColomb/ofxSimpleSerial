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
	
	red = (message == "r");
	green = (message == "g");
	blue = (message == "b");
}

void testApp::update()
{
	if(requestRead)
	 {
		serial.sendRequest();
		requestRead = false;
	 }
}

//--------------------------------------------------------------
void testApp::draw()
{
	int redColor = (red)? 255 : 0;
	int greenColor = (green)? 255 : 0;
	int blueColor = (blue)? 255 : 0;
	
	ofBackground(redColor, greenColor, blueColor);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	requestRead = true;
}
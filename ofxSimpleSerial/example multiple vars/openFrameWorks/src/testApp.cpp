#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	//serial.setup("/dev/tty.usbserial-A6008e4J", 9600);
	serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	serial.startContinuesRead();
	ofAddListener(serial.NEW_MESSAGE,this,&testApp::onNewMessage);
	
	message = "";
	
	ofSetFrameRate(20);
}

void testApp::onNewMessage(string & message)
{
	cout << "onNewMessage, message: " << message << "\n";
	if(message.length() == 3)
	 {
		red = (message.at(0) == 'n');
		green = (message.at(1) == 'g');
		blue = (message.at(2) == 'b');
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
	
	/*message = serial.message;
	//cout << "serial.message: " << serial.message << "\n";
	
	if(message.length() == 3)
	 {
		red = (message.at(0) == 'n');
		green = (message.at(1) == 'g');
		blue = (message.at(2) == 'b');
	 }*/
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
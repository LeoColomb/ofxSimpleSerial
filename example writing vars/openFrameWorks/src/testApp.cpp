#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	serial.startContinuesRead(false);
	ofAddListener(serial.NEW_MESSAGE,this,&testApp::onNewMessage);
	
	message = "";
	remember = false;
}

void testApp::onNewMessage(string & message)
{
	cout << "onNewMessage, message: " << message << "\n";
	
}

void testApp::update()
{
	if(message != "" && remember == false)
	 {
		cout << "sending message: " << message << "\n"; 
		serial.writeString(message);
		message = "";
	 }
}

//--------------------------------------------------------------
void testApp::draw()
{
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		case 32: //space
			remember = true;
			break;
	}
}
//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
	//cout << "key: " << key << endl;
	switch (key) {
		case 49: // 1
			message += "a";
			break;
		case 50: // 2
			message += "?";
			break; 
		case 51: // 3
			message += "3";
			break;
		case 52: // 4
			message = "a?3a?33?a";
			break;
		case 32: // space
			remember = false;
			break;
	}
}
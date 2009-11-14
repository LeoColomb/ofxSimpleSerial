#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	serial.startContinuesRead(false);
	ofAddListener(serial.NEW_MESSAGE,this,&testApp::onNewMessage);
	
	key1Down = false;
	key2Down = false;
	key3Down = false;
}

void testApp::onNewMessage(string & message)
{
	cout << "onNewMessage, message: " << message << "\n";
	
}

void testApp::update()
{
	if(sendMessage)
	{
	   string message = "";
		message += (key1Down)? "a" : "x";
		message += (key2Down)? "?" : "x";
		message += (key3Down)? "3" : "x";
		message += "|";
		cout << "sending message: " << message << "\n"; 
		serial.writeString(message);
		sendMessage = false;
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch (key) {
		case 49: // 1
			key1Down = true;
			break;
		case 50: // 2
			key2Down = true;
			break; 
		case 51: // 3
			key3Down = true;
			break;
	}

}
//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
	cout << "key: " << key << endl;
	
	switch (key) {
		case 49: // 1
			key1Down = false;
			break;
		case 50: // 2
			key2Down = false;
			break; 
		case 51: // 3
			key3Down = false;
			break;
		case 32: // space
			sendMessage = true;
			break;
	}
}
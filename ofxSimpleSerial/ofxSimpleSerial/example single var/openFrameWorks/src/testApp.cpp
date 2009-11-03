#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	serial.startContinuesRead();
	
	message = "";
}

void testApp::update()
{
	/*if(requestRead)
	 {
		serial.sendRequest();
		requestRead = false;
	 }*/
	
	message = serial.message;
	cout << "serial.message: " << serial.message << "\n";
	
	red = (message == "r");
	green = (message == "g");
	blue = (message == "b");
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
/*void testApp::mousePressed(int x, int y, int button){
	requestRead = true;
}
*/
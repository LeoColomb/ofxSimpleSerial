#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxSimpleSerial.h"

class testApp : public ofBaseApp{
	
	public:
		
		ofxSimpleSerial	serial;
		int bytesReturned;
	
		void setup();
		void update();
		void draw();
		
		
};	

#endif	


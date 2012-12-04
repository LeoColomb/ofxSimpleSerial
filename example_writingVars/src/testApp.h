#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxSimpleSerial.h"

using namespace std;

class testApp : public ofBaseApp{
	
	public:
		ofxSimpleSerial	serial;

		string		message;
		bool		remember;
	
		void		setup();
		void		update();
		void		draw();
		void		keyPressed  (int key);
		void		keyReleased(int key);
		void		onNewMessage(string & message);
	
	protected:
	
};	

#endif	


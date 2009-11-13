#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxSimpleSerial.h"

using namespace std;

class testApp : public ofBaseApp{
	
	public:
		ofxSimpleSerial	serial;

		string		message;
	
		bool		red;
		bool		green;
		bool		blue;
		bool		requestRead;
	
		void		setup();
		void		update();
		void		draw();
		void		mousePressed(int x, int y, int button);
		void		onNewMessage(string & message);
	
	protected:
	
	
		
};	

#endif	


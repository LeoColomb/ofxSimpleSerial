#ifndef _OFX_SIMPLE_SERIAL
#define _OFX_SIMPLE_SERIAL

#include "ofSerial.h"
#include "ofEvents.h"

#define NUM_BYTES 1

using namespace std;

class ofxSimpleSerial : public ofSerial{
	
	public:
	
		string		message;
	
		ofxSimpleSerial();
		void		sendRequest();
		void		startContinuesRead(bool writeByte);
		void		stopContinuesRead();
		void		writeString(string message);
	
		ofEvent< string > NEW_MESSAGE;
	
	protected:
	
		string		messageBuffer;
		unsigned char bytesReturned[NUM_BYTES];	
		bool		continuesRead;
	bool		bWriteByte;
		void		initSetup();
		void		update(ofEventArgs & args);
		void		read();
		
};	

#endif	


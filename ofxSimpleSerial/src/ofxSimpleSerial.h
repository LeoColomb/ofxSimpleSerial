#ifndef _OFX_SIMPLE_SERIAL
#define _OFX_SIMPLE_SERIAL

#define NUM_BYTES 1

using namespace std;

class ofxSimpleSerial : public ofSerial{
	
	public:
	
		string		message;
	
		ofxSimpleSerial();
		void		sendRequest();
		void		startContinuesRead();
		void		stopContinuesRead();
	
		ofEvent< string > NEW_MESSAGE;
	
	protected:
	
		string		messageBuffer;
		unsigned char bytesReturned[NUM_BYTES];	
		bool		continuesRead;
	
		void		initSetup();
		void		update(ofEventArgs & args);
		void		read();
		
};	

#endif	


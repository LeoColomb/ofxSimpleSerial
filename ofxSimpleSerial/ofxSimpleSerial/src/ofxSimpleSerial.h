#ifndef _OFX_SIMPLE_SERIAL
#define _OFX_SIMPLE_SERIAL

#define NUM_BYTES 1

using namespace std;

class ofxSimpleSerial{
	
	public:
	
		string		message;
	
		void		setup();
		void		setup(int deviceNumber, int baud);
		void		setup(string portName, int baud);
		void		sendRequest();

		void		startContinuesRead();
		void		stopContinuesRead();
	
	protected:
	
		ofSerial	serial;
		string		messageBuffer;
		unsigned char bytesReturned[NUM_BYTES];			
		
		void		initSetup();
		void		update(ofEventArgs & args);
		void		read();
		
};	

#endif	


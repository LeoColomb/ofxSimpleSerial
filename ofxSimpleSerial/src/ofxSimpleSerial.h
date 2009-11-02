#ifndef _OFX_SIMPLE_SERIAL_H
#define _OFX_SIMPLE_SERIAL_H

#include "ofConstants.h"
#include "ofSerial.h"
#include "ofEvents.h"

//TODO: dynamic num bytes
#define NUM_BYTES 1

//TODO: fix: OF_ERROR: ofSerial: trouble reading from port

class ofxSimpleSerial{

	public:
		
		unsigned char bytesReturned[NUM_BYTES];
		int readInterval;						// per how many frames we can read (min 5)
		//int numBytes;							// how many bytes, the message can be
	
		void setup();
		void setup(int deviceNumber, int baud);
		void setup(string portName, int baud);
		
	
	protected:
	
		ofSerial	serial;
		bool		bReadSerialMessage;			// a flag for sending serial
		int			countCycles;
	
		void initSetup();
		void update(ofEventArgs & args);
};

#endif

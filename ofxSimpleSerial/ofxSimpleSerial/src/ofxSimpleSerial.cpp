#include "ofxSimpleSerial.h"

ofxSimpleSerial::ofxSimpleSerial()
{
	message = "";
	messageBuffer = "";
	continuesRead = false;
}

void ofxSimpleSerial::startContinuesRead()
{
	continuesRead = true;
	sendRequest();
}
void ofxSimpleSerial::stopContinuesRead()
{
	continuesRead = false;
	ofRemoveListener(ofEvents.update, this, &ofxSimpleSerial::update);
}
/*
 * Request new data from the device your connected to.
 */
void ofxSimpleSerial::sendRequest()
{
	writeByte('r');
	ofAddListener(ofEvents.update, this, &ofxSimpleSerial::update);
}

void ofxSimpleSerial::update(ofEventArgs & args)
{
	read();
	if(continuesRead)
		sendRequest();
}

void ofxSimpleSerial::read()
{
	// if we've got new bytes
	if(available() > 0)
	{
	   // we wil keep reading until nothing is left
		while (available() > 0)
		{
		   // we'll put the incoming bytes into bytesReturned
		   readBytes(bytesReturned, NUM_BYTES);
		
		   // if we find the splitter we put all the buffered messages 
		   //   in the final message, stop listening for more data and 
		   //   notify a possible listener
		   // else we just keep filling the buffer with incoming bytes. 
		   if(*bytesReturned == '\n')
			{
			   message = messageBuffer;
			   messageBuffer = "";
			   ofRemoveListener(ofEvents.update, this, &ofxSimpleSerial::update);
			   ofNotifyEvent(NEW_MESSAGE,message,this);
			   
			   break;
			}
			else 
			{
			   messageBuffer += *bytesReturned;
			}
		    //cout << "  messageBuffer: " << messageBuffer << "\n";
		}
	   
		// clear the message buffer
		memset(bytesReturned,0,NUM_BYTES);
	}
}
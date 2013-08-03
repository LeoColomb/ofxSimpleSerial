#include "ofxSimpleSerial.h"

ofxSimpleSerial::ofxSimpleSerial() {
	message = "";
	messageBuffer = "";
	continuousRead = false;
	bWriteByte = true;
}

/*
* Make ofxSimpleSerial listen continuously for new messages.
* @param	writeByte		Should I do a writeByte('r') to request new messages? (true is default).
*							Disable this when you want to send your own messages.
*/
void ofxSimpleSerial::startContinuousRead(bool writeByte) {
	continuousRead = true;
	bWriteByte = writeByte;
	sendRequest();
}
void ofxSimpleSerial::stopContinuousRead() {
	continuousRead = false;
	ofRemoveListener(ofEvents().update, this, &ofxSimpleSerial::update);
}
/*
* Request new data from the device you're connected to.
*/
void ofxSimpleSerial::sendRequest()
{
	if (bWriteByte) writeByte('r');
	ofAddListener(ofEvents().update, this, &ofxSimpleSerial::update);
}

void ofxSimpleSerial::update(ofEventArgs & args)
{
	read();
	if (continuousRead)
		sendRequest();
}

void ofxSimpleSerial::read()
{
	// if we've got new bytes
	if (available() > 0)
	{
		// we will keep reading until nothing is left
		while (available() > 0)
		{
			// we'll put the incoming bytes into bytesReturned
			readBytes(bytesReturned, NUM_BYTES);

			// if we find the splitter we put all the buffered messages
			//   in the final message, stop listening for more data and
			//   notify a possible listener
			// else we just keep filling the buffer with incoming bytes.
			if (*bytesReturned == '\n')
			{
				message = messageBuffer;
				messageBuffer = "";
				ofRemoveListener(ofEvents().update, this, &ofxSimpleSerial::update);
				ofNotifyEvent(NEW_MESSAGE, message, this);

				break;
			}
			else
			{
				if (*bytesReturned != '\r')
					messageBuffer += *bytesReturned;
			}
			//cout << "  messageBuffer: " << messageBuffer << "\n";
		}

		// clear the message buffer
		memset(bytesReturned, 0, NUM_BYTES);
	}
}
void ofxSimpleSerial::writeString(string message)
{
	unsigned char* chars = (unsigned char*) message.c_str(); // cast from string to unsigned char*
	int length = message.length();
	writeBytes(chars, length);
}

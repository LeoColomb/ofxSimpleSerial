ofxSimpleSerial
---------------

**An addon that simplifies the Serial Communication from [openFrameworks](http://www.openframeworks.cc/)**

* Automatic message completion  
Complete messages exist between `\n`'s, sent for example from Arduino with `Serial.println()`. If the complete message cannot be read during one "update" it will keep listening for updates for it to be completed. 

* Simply use the message property to get the latest complete message
* Listen for the `NEW_MESSAGE` event to get properly notified
* Write to the serial connection using a string

### Examples
* Reading one piece of data
* Reading multiple pieces of data
* Writing one piece of data (string)
* Writing multiple pieces of data (string)

###### All examples are made with openFrameworks and Arduino

### Simple protocol to read data
* The addon writes an `r` to the serial connection
* The other party (Arduino for example) sends an update after it recieves this.

###### This ensures an in-sync transfer of data

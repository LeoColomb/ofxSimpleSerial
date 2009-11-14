char message[] = "";
char messageBuffer[] = "";
int numBufferedChars = 0;
int numMessageChars = 0;

int ledPin1 = 10;
int ledPin2 = 11;
int ledPin3 = 12;

void setup()
{
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  /*if(Serial.available() > 0)
  {
    Serial.println(Serial.read(),DEC);
    delay(100);
  }*/
  
  //Serial.println("Serial.available(): "+Serial.available() );
  
  if(Serial.available() > 0)
  {
    Serial.println("loop: available bytes");
    //int bytesRead = Serial.read();
    
    while(Serial.available() > 0)
    {
      char readChar = Serial.read();
      Serial.print("readChar: ");
      Serial.println(readChar);
      //int bytesRead = Serial.read();
      if(readChar == '|')
      {
        //message = messageBuffer
        //message[] = {};
        //message = {};
        //message = "";
        
        /*for(int i = 0;i<numMessageChars;i++)
        {
          message[i] = 0;
        }*/
        Serial.println("copy buffer to message");
        Serial.print("  messageBuffer: ");
        Serial.println(messageBuffer);
        for(int i = 0;i<numBufferedChars;i++)
        {
          Serial.print("  i: ");
          Serial.println(i);
          
          Serial.print("  messageBuffer[i]: ");
          Serial.println(messageBuffer[i]);
          
          message[i] = messageBuffer[i];
          
          Serial.print("  message[i]: ");
          Serial.println(message[i]);
          messageBuffer[i] = 0;
        }
        Serial.print("  message: ");
        Serial.println(message);
        //messageBuffer = "";
        numMessageChars = numBufferedChars;
        numBufferedChars = 0;
        useMessage(message);
      }
      else
      {
        Serial.println("add to buffer");
        messageBuffer[numBufferedChars] = readChar;
        Serial.print("  numBufferedChars: ");
        Serial.println(numBufferedChars);
        Serial.print("  messageBuffer: ");
        Serial.println(messageBuffer);
        
          
        //messageBuffer[numBufferedChars] = bytesRead;
        numBufferedChars++;
        //Serial.print("messageBuffer: ");
        //Serial.println(messageBuffer);
      }
      delay(100);
    }
  }
}
void useMessage(char* message)
{
  Serial.println("useMessage");
  Serial.print("numMessageChars: ");
  Serial.println(numMessageChars);
  for(int i = 0;i<numMessageChars;i++)
  {
    int ledPin = i+10;
    int value = (message[i] == 'x')? LOW : HIGH;
    Serial.print(ledPin);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(", ");
    digitalWrite(ledPin,value);
  }
  Serial.println("");
}

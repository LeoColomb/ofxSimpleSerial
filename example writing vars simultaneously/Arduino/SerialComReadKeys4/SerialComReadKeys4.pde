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
  if(Serial.available() > 0)
  {
    while(Serial.available() > 0)
    {
      char readChar = Serial.read();
      if(readChar == '|')
      {
        for(int i = 0;i<numBufferedChars;i++)
        {
          message[i] = messageBuffer[i];
          messageBuffer[i] = 0;
        }
        numMessageChars = numBufferedChars;
        numBufferedChars = 0;
        useMessage(message);
      }
      else
      {
        messageBuffer[numBufferedChars] = readChar;
        numBufferedChars++;
      }
    }
  }
}
void useMessage(char* message)
{
  for(int i = 0;i<numMessageChars;i++)
  {
    int ledPin = i+10;
    int value = (message[i] == 'x')? LOW : HIGH;
    digitalWrite(ledPin,value);
  }
}

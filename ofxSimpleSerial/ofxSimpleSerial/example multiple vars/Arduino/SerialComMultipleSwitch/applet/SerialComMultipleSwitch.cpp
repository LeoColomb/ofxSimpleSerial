#include "WProgram.h"
void setup();
void loop();
int switchPinR = 2;
int switchPinG = 3;
int switchPinB = 4;
int ledPin = 12;   

void setup()
{
  pinMode(switchPinR, INPUT);
  digitalWrite(switchPinR, HIGH);
  pinMode(switchPinG, INPUT);
  digitalWrite(switchPinG, HIGH);
  pinMode(switchPinB, INPUT);
  digitalWrite(switchPinB, HIGH);
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()                     
{
  if(Serial.available() > 0 && Serial.read() == 'r')
  {
    int switchValueR = digitalRead(switchPinR);
    int switchValueG = digitalRead(switchPinG);
    int switchValueB = digitalRead(switchPinB);
 
    int numOffSwitches = 0;
 
    if(switchValueR == LOW)
    {
      Serial.print("r");
      digitalWrite(ledPin, HIGH);
    }
     else
    {
      Serial.print("x");
      numOffSwitches++;
    }
    
    Serial.print(",");
    if(switchValueG == LOW)
    {
      Serial.print("g");
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      Serial.print("x");
      numOffSwitches++;
    }
    
    Serial.print(",");
    if(switchValueB == LOW)
    {
      Serial.print("b");
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      Serial.print("x");
      numOffSwitches++;
    }
    
    if(numOffSwitches >= 3)
    {
      digitalWrite(ledPin, LOW);
    }
    
    //Serial.print("|");
    Serial.println(",");
    Serial.flush();
  }
  
  delay(100);
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}


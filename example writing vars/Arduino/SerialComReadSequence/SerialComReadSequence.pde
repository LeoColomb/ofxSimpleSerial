int ledPin1 = 10;
int ledPin2 = 11;
int ledPin3 = 12;

void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  Serial.begin(9600);
}

void loop () {
  if(Serial.available() > 0)
  {
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    char readBytes = Serial.read(); 
    if(readBytes == 'a')
      digitalWrite(ledPin1,HIGH);
    if(readBytes == '?')
      digitalWrite(ledPin2,HIGH);
    if(readBytes == '3')
      digitalWrite(ledPin3,HIGH);
  }
  delay(100);
} 

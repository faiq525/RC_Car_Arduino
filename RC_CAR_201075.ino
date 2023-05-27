char val;
#include <Servo.h>
Servo steer;
void setup() {
   steer.attach(9);
   Serial.begin(9600);
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
}
void loop() {
  if (Serial.available()){
    val = Serial.read();
    Serial.println(val);
  }
  
  if(val=='L'){
    steer.write(90);
    steer.write(55);
    delay(50);
  }
  else if(val=='0'){
    steer.write(125);
    steer.write(90);
    delay(50);
  }
  
  Serial.println(val);

  if(val=='R'){
    steer.write(90);
    steer.write(125);
    delay(50);
  }
  else if(val=='0'){
    steer.write(55);
    steer.write(90);
    delay(50);
  }
  
  if(val=='F'){
    digitalWrite(6,HIGH);
  }
  else if(val=='M'){
    digitalWrite(6,LOW);
  }

  if(val=='B'){
    digitalWrite(7,HIGH);
  }  
  else if(val=='M'){
    digitalWrite(7,LOW);
  }       
}

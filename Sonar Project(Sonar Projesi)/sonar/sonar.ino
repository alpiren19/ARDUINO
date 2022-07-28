#include <Servo.h>. 

const int trigPin = 10;
const int echoPin = 11;
int led = 7;
int buzzer = 2;
long duration;
int distance;
Servo myServo;


void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  myServo.attach(9); 
  
}


void loop() {

  
  
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
    if(distance<30){
      digitalWrite(led,HIGH);
      digitalWrite(buzzer,HIGH);
      }
     else{
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
      }
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance);
  Serial.print(".");
  }
  

  
 
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  if(distance<30){
      digitalWrite(led,HIGH);
      digitalWrite(buzzer,HIGH);
      }
     else{
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
      }
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}



int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;

}

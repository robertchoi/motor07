
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(12, 13);   
Servo myservo;

int motor1PinA = 2;
int motor1PinB = 3;
int enablelPin = 11;   

int motor2PinA = 4;
int motor2PinB = 5;
int enablerPin = 10;  

int relay_pin = 7;

char in;

void setup() {

  BTSerial.begin(9600);
  Serial.begin(9600);
  
  pinMode(relay_pin, OUTPUT);
  pinMode(motor1PinA, OUTPUT);
  pinMode(motor1PinB, OUTPUT);
  
  pinMode(motor2PinA, OUTPUT);
  pinMode(motor2PinB, OUTPUT);
  //pinMode(enablerPin, OUTPUT);
  //pinMode(enablelPin, OUTPUT);

  analogWrite(enablerPin, 250);
  analogWrite(enablelPin, 250);
}

void loop() {
  if (BTSerial.available()){
    in = BTSerial.read();
    Serial.write(in);
  }
  
  if (Serial.available()){
    BTSerial.write(Serial.read());
    //Serial.print("data =");
    //Serial.println(in);
  }
    
  switch(in){
    case 'F':
    Forward(); break;
    case 'R': 
    Right(); break; 
    case 'S': 
    Stop(); break;
    case 'L': 
    Left(); break;
    case 'B': 
    Back(); break;
    case 'G': 
    Back(); break;
    case 'W': 
    FrontLightOn(); break;
    case 'w': 
    FrontLightOff(); break;
  } 
}

void Forward(){
  digitalWrite(motor1PinA, LOW);
  digitalWrite(motor1PinB, HIGH);
  digitalWrite(motor2PinA, HIGH);
  digitalWrite(motor2PinB, LOW);
}  
 
void Back(){
  digitalWrite(motor1PinA, HIGH);
  digitalWrite(motor1PinB, LOW);
  digitalWrite(motor2PinA, LOW);
  digitalWrite(motor2PinB, HIGH); 
}

void Right(){
  digitalWrite(motor1PinA, LOW);
  digitalWrite(motor1PinB, LOW);
  digitalWrite(motor2PinA, HIGH);
  digitalWrite(motor2PinB, LOW);
}

void Left(){ 
  digitalWrite(motor1PinA, LOW);
  digitalWrite(motor1PinB, HIGH);
  digitalWrite(motor2PinA, LOW);
  digitalWrite(motor2PinB, LOW);
}

void FrontLightOn(){ 
  digitalWrite(9, LOW);
  digitalWrite(relay_pin, HIGH);
  delay(3000);   
}
  
void FrontLightOff(){ 
   digitalWrite(relay_pin, LOW);     
}

void Stop(){
   digitalWrite(motor1PinA, LOW);
   digitalWrite(motor1PinB, LOW);
   digitalWrite(motor2PinA, LOW);
   digitalWrite(motor2PinB, LOW);
}

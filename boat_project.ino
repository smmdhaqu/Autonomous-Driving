/*
   project name: boat project
   author: team
   date: 15-8-2023
   descryption:



*/



/**************************** initialize library ************************/
#include "CommunicationParser.h"
#include "ServoControl.h"
#include "motor.h"
#include "config.h"




/*************************** object create *****************************/
CommunicationParser communicationParser;
ServoControl servoControl;
Robot robot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //use as serial monitor
  Serial1.begin(9600);  //use for communication with esp32 
  
  robot.robotSetup();  //motor pin mode select
  servoControl.AttachServos();  //servo pin mode selecr
  servoControl.radarIdlePosition();  //set servo to ideal position
  delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:
  robot.moveForward();
  communicationParser.checkSerial();
  delay(200);
}

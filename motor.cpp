/************************************************ Robot.cpp *****************************************************/

#include "motor.h"


void Robot :: robotSetup()
{
  pinMode(motorLeftPin1, OUTPUT); //to controll motor of a robot
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);
}



void Robot :: moveStop()
{
  Serial.println("moveStop");
  digitalWrite( motorLeftPin1, LOW);  // to give output high or low of a pin
  digitalWrite( motorLeftPin2, LOW);
  digitalWrite( motorRightPin1, LOW);
  digitalWrite( motorRightPin2, LOW);
}


void Robot :: moveForward()
{
  Serial.println("moveforward");
  digitalWrite( motorLeftPin1, HIGH);
  digitalWrite( motorLeftPin2, LOW);
  digitalWrite( motorRightPin1, HIGH);
  digitalWrite( motorRightPin2, LOW);
}


void Robot :: moveBackward()
{
  digitalWrite( motorLeftPin1, LOW);
  digitalWrite( motorLeftPin2, HIGH);
  digitalWrite( motorRightPin1, LOW);
  digitalWrite( motorRightPin2, HIGH);
}

void Robot :: moveLeft()
{
  digitalWrite( motorLeftPin1, LOW);
  digitalWrite( motorLeftPin2, HIGH);
  digitalWrite( motorRightPin1, HIGH);
  digitalWrite( motorRightPin2, LOW);
}

void Robot :: moveRight()
{
  digitalWrite( motorLeftPin1, HIGH);
  digitalWrite( motorLeftPin2, LOW);
  digitalWrite( motorRightPin1, LOW);
  digitalWrite( motorRightPin2, HIGH);
}


/**************************** servoControl.cpp ************************************/

#include "ServoControl.h"
#include "config.h"
#include "pinMapping.h"
/****************************************** servo position init ******************************************/
//for servo
int servoPins[] = {3, 5, 6, 9}; //pin define
Servo servos[servoCount];
int servosValue[] = {90,90, 90, 90};



void ServoControl :: AttachServos() {
  for (int i = 0; i < servoCount; i++)
  {
    servos[i].attach(servoPins[i]);
  }
}


void ServoControl :: servoRotate(int channel, int pos)
{

  while ( servosValue[channel] <= pos )
  {

    servos[channel].write( servosValue[channel] );
    servosValue[channel]++;
    delay(delayTime);
  }

  while ( servosValue[channel] > pos )
  {

    servos[channel].write( servosValue[channel] );
    servosValue[channel]--;
    delay(delayTime);
  }

  servosValue[channel] = pos;
  Serial.print("Channel: ");
  Serial.print(channel  );
  Serial.print("\tPosition: ");
  Serial.println(pos);

}

void ServoControl :: turnLeft()
{
  Serial.println("turnLeft");
  for (int i = 0; i < servoCount; i++)
  {
    servos[i].write(turnLeftAngle);  
  }              
  delay(500); 
}


void ServoControl :: turnRight()
{
  Serial.println("turnRight");             
  for (int i = 0; i < servoCount; i++)
  {
    servos[i].write(turnRightAngle);  
  }              
  delay(500); 
}

void ServoControl :: radarIdlePosition()
{
  Serial.println("radarIdlePosition");
  for( int i = 0; i < servoCount; i++ )
  {
      servos[i].write(idealPosition);              
      delay(500); 
  }
}


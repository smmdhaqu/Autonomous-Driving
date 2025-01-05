/********************************* servoControl.h ********************************************/
#ifndef __SERVO_CONTROL_H__
#define __SERVO_CONTROL_H__

#include "Arduino.h"
#include <Servo.h>    ///third party library 

class ServoControl
{
  private:
    uint8_t _pin;
  public:
    void ServoControl :: servoRotate(int channel, int pos);
    void turnLeft();
    void turnRight();
    void radarIdlePosition();
    void AttachServos();
};

#endif

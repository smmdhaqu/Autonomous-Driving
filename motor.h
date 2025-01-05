/************************************************** Robot.h *****************************************************/
#ifndef  ROBOT_H //header guard
#define ROBOT_H

#include "pinMapping.h"
#include "Arduino.h"


class Robot
{
  private:
  public:
    void robotSetup();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveStop();
};

#endif


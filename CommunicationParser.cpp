/********************************* communicationParser.cpp *******************************/


#include "CommunicationParser.h"
#include "ServoControl.h"
#include "motor.h"
#include "pinMapping.h"

/*************************** object create *****************************/
extern CommunicationParser communicationParser;
extern ServoControl servoControl;
extern Robot robot;


void CommunicationParser :: checkSerial()
{
  if ( Serial1.available() )
  {
    String serialReceiveValue = Serial1.readStringUntil('\n');
    Serial.println( F("serialReceiveValue: ") );
    Serial.println( serialReceiveValue );
    requestHandle( serialReceiveValue ) ;
  }

}

void CommunicationParser :: requestHandle( String serialReceiveValue )
{
  if ( serialReceiveValue == "LEFT" ) //turn left
  {
    //take action based on CMD
    servoControl.turnLeft();
    responseHandle( "OK" ) ;  //for ACK to esp32
  }
  else if (serialReceiveValue == "RIGHT" ) //turn right
  {
    //take action based on CMD
    servoControl.turnRight();
    responseHandle( "OK" ) ;  //for ACK to esp32
  }
  else
  {
    Serial.println("do nothing");
  }
}




void CommunicationParser :: responseHandle( String responsePayload )   //to send data from arduino to esp32
{
  Serial.println( F("responseHandle value") );
  Serial1.println( responsePayload );
}


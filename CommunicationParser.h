/********************************* communicationParser.h **************************************/


#ifndef __COMMUNICATION_PARSER_H__
#define __COMMUNICATION_PARSER_H__

#include "Arduino.h"

class CommunicationParser
{
  public:
  void checkSerial();  //to chaeck any data from esp32 to arduino
  void requestHandle( String serialReceiveValue );
  void responseHandle( String responsePayload );  //to send data from arduino to esp32
};


#endif


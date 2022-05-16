#include <SPI.h>
#include <mcp2515.h>

#define CS 10

struct can_frame canMsg1; //ogni struct è un messaggio
MCP2515 mcp2515(CS);  //oggetto


void setup() {
  canMsg1.can_id=0x037;
  canMsg1.can_dlc=1;
  canMsg1.data[0]=18;
  

  while(!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();
  
  Serial.println("------- Write to CAN----------");
 
}

void loop() {
  mcp2515.sendMessage(&canMsg1);
  Serial.println("Message sent");
  delay(100);
}

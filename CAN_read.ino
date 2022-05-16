#include <SPI.h>
#include <mcp2515.h>

#define CS 10 
struct can_frame canMsg;
MCP2515 mcp2515(CS);


void setup() {
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();
  
  Serial.println("------- CAN Read ----------");

}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {  //se non ci sono errori
    Serial.print("ID: ");
    Serial.print(canMsg.can_id, HEX); // print ID del trasmittente
    Serial.print("DLC: "); 
    Serial.print(canMsg.can_dlc, HEX); // print DLC (lunghezza dei dati
    Serial.print("DATA: ");

    //inizio lettura dati
    for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");
    }

    Serial.println();      
  }
}

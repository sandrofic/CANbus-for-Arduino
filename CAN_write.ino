#include <SPI.h> //per poter comunicare con il modulo
#include <mcp2515.h>

#define CS 10

struct can_frame canMsg1; //ogni struct è un messaggio
//struct can_frame canMsg2 ecc..
MCP2515 mcp2515(CS);  //oggetto


void setup() {
  canMsg1.can_id=0x037; //identificativo del dispositivo
  canMsg1.can_dlc=2;  //lunghezza dei dati
  canMsg1.data[0]=18; //dati
  canMsg1.data[1]=13; //dati
  

  while(!Serial);
  Serial.begin(115200); //baud
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();
  
  Serial.println("------- Write to CAN----------");
 
}

void loop() {
  mcp2515.sendMessage(&canMsg1); //dobbiamo passare l'indirizzo di memoria della struct
  Serial.println("Message sent");
  delay(100);
}

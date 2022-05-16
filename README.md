# CANbus-for-Arduino
Comunicazione tramite CANbus tra due Arduino.
Nell'esempio vengono trasmessi dati contenuti in un array di 2 elementi.
Sono necessari due moduli MCP2515.

I collegamenti sono: 
D13->SCK
D12->SO
D11->SI
D10->CS

GND e VCC.
CANH E CANL devono essere collegate tra i due moduli: si può fare sia con i morsetti sia con i pin H,L.
J1 è una resistenza da 120 ohm che deve essere collegata se i moduli sono inizio e fine del bus, quindi in questo caso si dovrà collegare in entrambe.

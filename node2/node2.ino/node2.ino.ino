#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define ID  2
char data[32];
String valSplit[7];
char dataKirim[32];
String valSplitNode[10];
char x[32];
int n;
int banyakNodeYgDiLalui;
String IdNextNodeRREP;
int longRute = 0;
int samePackage = 0;

//format
// RREQ,        ID_Sender,  ID_Destination, Message,  Route
// valSplit[0], [1],        [2],            [3],      [4]
void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"2222");
  Mirf.payload = 32;
  Mirf.channel = 99;
  Mirf.config();
  Serial.println("Listening..."); 
}

void loop(){

  receiveData();
  
}

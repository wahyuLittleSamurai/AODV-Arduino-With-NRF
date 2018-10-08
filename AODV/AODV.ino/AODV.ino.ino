#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <stdio.h>

#define ID  1
#define nodeClient  4
#define ulangRouting  1
#define ulangAodvSession 1

String hasilRouting[nodeClient+1][2];
boolean active[nodeClient+1];

double millisNow;
char data[32];
char dataKirim[32];
String valSplitNode[10];
char x[9];
char xx[2];
int n;
String valSplit[7];
int banyakNodeYgDiLalui;
int timeOut = 10000;
boolean flag = false;
boolean startAodv = false;

//format
// RREQ, ID_Sender, ID_Destination, Message, Route

void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"2222");
  Mirf.payload = 32;
  Mirf.channel = 99;
  Mirf.config();
  Serial.println("Beginning ... "); 
}

void loop(){
  /*
  millis();
  for(int node = 2; node <= nodeClient; node++)
  {
    flag = false;
    millisNow = millis();
    while((millis()-millisNow) <= timeOut)
    {
      if(!flag)
      {
        String newRoute = "";
        newRoute = String(node);
        n = newRoute.length() + 1;
        xx[n];
        newRoute.toCharArray(xx, n);
        
        sendingData(xx,"hi");
        //delay(100);
        flag = true;
      }
      receiveData();
    }
  }
 */
  
  //receiveData();
  //sendingData("3","hi");
  //delay(200);
  //sendingData("2","hi");
  //delay(200);

  routingNode("hello",5);
  while(!startAodv)
  {
    aodvSession("hello",5);
    Serial.println("Please Wait... Evaluasi Rute Node");
    for(int evaluasiNode = 2; evaluasiNode <= nodeClient; evaluasiNode++)
    {
      showTblRouting();//lihat table routing
      if(active[evaluasiNode] == false) // jika salah satu dari node putus ulangi routingNode
      {
        Serial.print("Node ");
        Serial.print(evaluasiNode);
        Serial.println(" not connected \nRouting Ulang... \n");
        startAodv = false;
      }
    }
    for(int y = 2; y <= nodeClient; y++)
    {
      active[y] = false;
    }
    while(1)
    {
      
    }
   
  }
  
} 


  
  

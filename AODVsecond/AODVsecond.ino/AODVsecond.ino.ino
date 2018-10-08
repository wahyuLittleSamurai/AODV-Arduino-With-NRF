#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <stdio.h>
#include <EEPROM.h>

#define ID  1
#define nodeClient 4
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
boolean flag = false;
boolean startAodv = true;
char readSerial;
boolean startRREQ = false;
boolean startMessage = false;
boolean startNode = false;
String dataSerial;
String sendDataString;
boolean afterRouting = false;

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
  Serial.println("*** MENU ***");
  Serial.println("Type Q= Start Sending RREQ");
  Serial.println("Type T= Show Table Routing");
  Serial.println("Type M= Input Message For Send With AODV (format: message+! example: hola!)");
}

void loop(){
 
  if(Serial.available())//Tunggu inputan dari serial port
  {
    readSerial = Serial.read(); //simpan data serial ke var readSerial
    if(readSerial == 'Q') // jika data yg di terima Q maka jalankan RREQ
    {
      startRREQ = true;
    }
    if(readSerial == 'T') // jika data yg diterima T maka tampilkan Table Routing
    {
      Serial.println("Please Wait... \nShow Table Routing");
      showTblRouting();//lihat table routing
      Serial.println("*** End Table Routing ***");
    }
    if(readSerial == 'M') // jika data M, maka lakukan inputan pesan
    {
      Serial.println("Input Message:");
      startMessage = true;
    }
   
  }
  while(startMessage) //tunggu data pesan
  {
    if(Serial.available())  
    {
      char cc = Serial.read();  //baca data message yg akan dikirim
      if(cc == '!')             //apabila variable "cc" mendapatkan character !(sebagai ending pesan yg dikirim)
      {
        valMessage(dataSerial); //panggil func valMessage
        dataSerial = "";
        startMessage = false;
        startAodv = false;
      }
      else                    //selama data character yang di baca bukan ! maka data tersebut di simpan di variable "dataSerial"
      {
        dataSerial += cc;
      }
    }
  }
  while(startRREQ)      //perulangan untuk pengiriman RREQ
  {
    routingNode("hello",15);  //panggil func untuk pengiriman RREQ
    Serial.println("*** PROSES RREQ IS DONE ***");
    startRREQ = false;
    if(afterRouting)  //variable penanda jika sudah pernah ada node yg putus,,,
    {
      startAodv = false;
    }
  }
  while(!startAodv) //perulangan untuk memulai AODV
  {
    afterRouting = true;
    int panjangDataString = sendDataString.length() + 1;  //hitung banyaknya jumlah data yg akan dikirim (exmpl: halo, berarti 4)
    char dataToChar[panjangDataString];                   //declar variable dataToChar array untuk menampung data pesan (exmpl:halo)
    sendDataString.toCharArray(dataToChar, panjangDataString);  //ubah data String ke Char Array
    
    aodvSession(dataToChar,15); // panggil func untuk pengiriman AODV, dengan jeda waktu tunggu 15second
    Serial.println("Please Wait... Evaluasi Rute Node");
    for(int evaluasiNode = 2; evaluasiNode <= nodeClient; evaluasiNode++) //perulangan untuk mencari node yg terputus
    {
      showTblRouting();//lihat table routing
      if(active[evaluasiNode] == false) // jika salah satu dari node putus ulangi routingNode
      {
        Serial.print("Node ");
        Serial.print(evaluasiNode);
        Serial.println(" not connected \nRouting Ulang... \n");
        startAodv = true;
        startRREQ = true;
        startMessage = false;
      }
    }
    for(int y = 2; y <= nodeClient; y++) //kosongkan semua penanda untuk node yg putus
    {
      active[y] = false;
    }
   
  }
  
} 


  
  

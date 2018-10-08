
void sendingData(char dest[], char text[])
{
  Mirf.setTADDR((byte *)"2222");
  
  strcpy(dataKirim, "Q"); //RREQ code
  strcat(dataKirim, ","); //Separator
  sprintf(x,"%d",ID);
  strcat(dataKirim, x);  //ID sender
  strcat(dataKirim, ",");
  strcat(dataKirim, dest);  //ID destination
  strcat(dataKirim, ",");
  strcat(dataKirim, text);  //message
  strcat(dataKirim, ",");
  sprintf(x,"%d",ID);
  strcat(dataKirim, x);//route masih kosong 
  strcat(dataKirim, ",");

  Serial.print("Sending to: ");
  Serial.println(dataKirim);
  
  Mirf.send((byte *)&dataKirim);
  
  while(Mirf.isSending()){
  }
}
void sendingAodv(char dest[], char text[], String route)
{
  Mirf.setTADDR((byte *)"2222");
  
  strcpy(dataKirim, "A"); //RREQ code
  strcat(dataKirim, ","); //Separator
  sprintf(x,"%d",ID);
  strcat(dataKirim, x);  //ID sender
  strcat(dataKirim, ",");
  strcat(dataKirim, dest);  //ID destination
  strcat(dataKirim, ",");
  strcat(dataKirim, text);  //message
  strcat(dataKirim, ",");

  String newRoute = "";
  newRoute = route;//ambil jalur routing
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);//route yg akan dilalui
  strcat(dataKirim, ",");

  Serial.print("Sending AODV to: ");
  Serial.println(dataKirim);
  
  Mirf.send((byte *)&dataKirim);
  
  while(Mirf.isSending()){
  }
}

void aodvSession(char text[], double timeOut)//func untuk pengiriman AODV
{
  millis();
  for(int ulang = 0; ulang <= ulangAodvSession; ulang++)//ulang berapa kali pengiriman AODV
  {
    for(int node = 2; node <= nodeClient; node++) //ulang sebanyak node yg tersedia
    {
      flag = false;
      millisNow = millis();
      while((millis()-millisNow) <= timeOut*1000)// ulang selama belum timeout
      {
        if(!flag)
        {
          hasilRouting[node][0];  
          //Serial.println(hasilRouting[node][0]);
          parseNodeBefore(hasilRouting[node][0],">");//panggil func untuk memisahkan data
          //Serial.println(valSplitNode[banyakNodeYgDiLalui]);
          
          String newRoute = "";
          newRoute = valSplitNode[banyakNodeYgDiLalui]; //ambil banyaknya rute yg dilalui
          n = newRoute.length() + 1;  //cari panjang dari rute
          xx[n];
          newRoute.toCharArray(xx, n);//ubah panjang rute yg awalnya String ke Char Array
          
          sendingAodv(xx,text,hasilRouting[node][0]);//panggil func untuk mengirim data AODV 
          
          receiveData(true);//panggil func untuk menerima balasan
          
          flag = true;
        }
        receiveData(true);//panggil func untuk menerima balasan
      }
    }
  }
  
}


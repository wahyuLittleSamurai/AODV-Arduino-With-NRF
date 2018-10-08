
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

void aodvSession(char text[], int timeOut)
{
  millis();
  for(int ulang = 0; ulang <= ulangAodvSession; ulang++)
  {
    for(int node = 2; node <= nodeClient; node++)
    {
      flag = false;
      millisNow = millis();
      while((millis()-millisNow) <= timeOut*1000)
      {
        if(!flag)
        {
          hasilRouting[node][0];
          //Serial.println(hasilRouting[node][0]);
          parseNodeBefore(hasilRouting[node][0],">");
          //Serial.println(valSplitNode[banyakNodeYgDiLalui]);
          
          String newRoute = "";
          newRoute = valSplitNode[banyakNodeYgDiLalui];
          n = newRoute.length() + 1;
          xx[n];
          newRoute.toCharArray(xx, n);
          
          sendingAodv(xx,text,hasilRouting[node][0]);
          
          receiveData(true);
          
          flag = true;
        }
        receiveData(true);
      }
    }
  }
  
}


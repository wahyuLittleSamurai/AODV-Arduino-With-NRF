void sendingDataQ()
{
  String newRoute = "";
  Mirf.setTADDR((byte *)"2222");
  
  strcpy(dataKirim, "Q"); //RREQ code
  strcat(dataKirim, ","); //Separator
  sprintf(x,"%d",ID);
  strcat(dataKirim, x);  //ID sender
  strcat(dataKirim, ",");

  newRoute = valSplit[2];
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);  //ID destination
  strcat(dataKirim, ",");

  newRoute = valSplit[3];
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);  //message
  strcat(dataKirim, ",");

  newRoute = valSplit[1] + ">" + String(ID);
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);   //route yg tersedia 
  strcat(dataKirim, ",");

  Serial.println(dataKirim);
  Serial.println("-----------");
  
  Mirf.send((byte *)&dataKirim);
  
  while(Mirf.isSending()){
  }
}
void sendingDataP(char text[])// sending RREP Node Selanjutnya
{
  String newRoute = "";
  Mirf.setTADDR((byte *)"2222");
  
  strcpy(dataKirim, text); //RREP code
  strcat(dataKirim, ","); //Separator
  sprintf(x,"%d",ID);
  strcat(dataKirim, x);  //ID sender
  strcat(dataKirim, ",");
  
  newRoute = IdNextNodeRREP;//ambil node selanjutnya
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);  //ID sender selanjutnya
  strcat(dataKirim, ",");

  newRoute = valSplit[3];
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);  //message
  strcat(dataKirim, ",");

  newRoute = valSplit[4];
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);   //route yg tersedia 
  strcat(dataKirim, ",");

  Serial.println("teruskan : ");
  Serial.println(dataKirim);

  Mirf.send((byte *)&dataKirim);
  
  while(Mirf.isSending()){
  }
}
void sendingDataLastP(char text[])// sending RREP Data Terakhir
{
  String newRoute = "";
  Mirf.setTADDR((byte *)"2222");
  
  strcpy(dataKirim, text); //RREP code
  strcat(dataKirim, ","); //Separator
  sprintf(x,"%d",ID);
  strcat(dataKirim, x);  //ID sender
  strcat(dataKirim, ",");
  
  newRoute = valSplitNode[banyakNodeYgDiLalui];//ambil node terakhir
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);  //ID sender sebelumnya
  strcat(dataKirim, ",");

  newRoute = valSplit[3];
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);  //message
  strcat(dataKirim, ",");

  newRoute = valSplit[4] + ">" + String(ID);
  n = newRoute.length() + 1;
  x[n];
  newRoute.toCharArray(x, n);
  
  strcat(dataKirim, x);   //route yg tersedia 
  strcat(dataKirim, ",");

  Mirf.send((byte *)&dataKirim);
  
  while(Mirf.isSending()){
  }
}

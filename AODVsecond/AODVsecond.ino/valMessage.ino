void valMessage(String dataReceived)//func digunakan untuk merecord pesan yg akan dikirim
{
  dataReceived += "#";  //penanda untuk akhir pesan
  int countSplitSecond=0;
  int lastIndexSecond=0;
  for(int j = 0; j < dataReceived.length(); j++)  //ulang banjang pesan
  {
    if(dataReceived.substring(j, j+1) == "#")//cari pesan dengan nilai "#"
    {
      sendDataString = dataReceived.substring(lastIndexSecond,j);//simpan pesan tersebut ke variable sendDataString
      lastIndexSecond = j + 1;
      Serial.println(sendDataString);
      countSplitSecond++;
    }
  }
}


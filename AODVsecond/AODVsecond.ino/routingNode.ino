void routingNode(char text[], double timeOut) //func untuk mengirim RREQ
{
  millis();//start time
  for(int ulang2x = 0; ulang2x<=ulangRouting; ulang2x++)  //ulang sebanyak variable ulangRouting (default 2x pengiriman RREQ)
  {
    for(int node = 2; node <= nodeClient; node++) //ulang sebanyak node yg tersedia (default 4 node, 1 node server, 3 node client)
    {
      flag = false; //tanda untuk selesai pengiriman RREQ dan penanda untuk start menunggu RREP
      millisNow = millis();
      while((millis()-millisNow) <= timeOut*1000) //waktu tunggu sebsar variable timeOut(default 15 detik)
      {
        if(!flag) //jika tanda !flag maka lakukan pengiriman RREQ
        {
          String newRoute = "";
          newRoute = String(node);
          n = newRoute.length() + 1;  //cari panjang message
          xx[n];                      //simpan di variable char array
          newRoute.toCharArray(xx, n);
          
          sendingData(xx,text); //func untuk mengirim data RREQ
          
          receiveData(false); //panggi func receiveData, untuk RREQ
          
          flag = true;//penanda untuk mulai receive data
        }
        receiveData(false); //panggil func receiveData,
      }
    }
  }
}


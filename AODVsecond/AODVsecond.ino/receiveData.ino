void receiveData(boolean routingOrAodv) //func untuk menerima data
{
  if(!Mirf.isSending() && Mirf.dataReady()){  //apabila mirf mendapatkan pesan dan tidak dalam proses mengirim maka...
    Mirf.getData((byte *)&data);              //simpan data yg diterima ke dalam variable byte array "data"
    //Serial.print("Data RAW: ");
    //Serial.println(data);
     parseData(data,",");                     // panggil func untuk memisah data
    if(!routingOrAodv)                        //apakah data yg diterima merupakan proses AODV atau RREQ, jika RREQ maka...
    {
      parseNodeBefore(valSplit[4],">");//cari node terakhir
      cekDest(ID);                    //dan panggil func cekDest();
    }
    else                              //jika data yg diterima merupakan data AODV maka...
    {
      cekDestAodv(ID);                //panggil func cekDestAodv();
    }
  }
}
void parseData(char text[], String key) //func untuk memisah data
{
  String dataString = String(text); //ubah dan simpan data text kedalam variable String "dataString"
  int countSplitSecond=0;
  int lastIndexSecond=0;
  for(int j = 0; j < dataString.length(); j++)  // ulang sampai panjang data tersebut (exmpl: data RAW = Q,1,2,asdf,1, maka bnyak data = 13 charakter)
  {
    if(dataString.substring(j, j+1) == key) //apabila data yg diterima = separatore(exmpl separator adalah ",")
    {
      valSplit[countSplitSecond] = dataString.substring(lastIndexSecond,j); //simpan data tersebut ke variabl String Array valSplit[] (exmpl: valSplit[0] = Q, valSplit[1]=1,...)
      lastIndexSecond = j + 1;
      //Serial.print(countSplitSecond);
      //Serial.print(":");
      //Serial.println(valSplit[countSplitSecond]);
      countSplitSecond++;
    }
  }
}
void cekDest(int myId)  //func cekDest 
{
  if(valSplit[2] == String(myId)) //jika data yang diterima valSplit[2](kolom ID penerima) sama dengan ID milik...
  {
    if(valSplit[0] == "P")  //cek apakah kolom Header Data merupakan RREP(tanda "P")
    {
      Serial.println(data);
      Serial.println("Received RREP");
      tableRouting(); //panggil func tableRouting
      Serial.println();
    }
    else
    {
      //Serial.println("Got RREQ");
    }
  }
  
}
void cekDestAodv(int myId)  //func untuk cekDestAodv, digunakan untuk proses aodv
{
  if(valSplit[2] == String(myId))
  {
    if(valSplit[0] == "V")
    {
      Serial.println("Received AODV");
      showFromNodeData(); //panggil func untuk menampilkan data aodv
      Serial.println();
    }
    else
    {
      //Serial.println("Got RREQ");
    }
  }
  
}

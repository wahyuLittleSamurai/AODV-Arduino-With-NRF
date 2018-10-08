void tableRouting()
{
  int idNode = valSplitNode[banyakNodeYgDiLalui].toInt();   //dari id node X
  int panjangString = valSplit[4].length();                 //panjang Route Sekarang
  int panjangRouteBefore = hasilRouting[idNode][0].length();//panjang Route Sebelumnya
  if(panjangString < panjangRouteBefore || panjangRouteBefore == 0)//cari jalur terpendek dari sebelumnya
  {
    hasilRouting[idNode][0] = valSplit[4];
    //Serial.println(hasilRouting[idNode][0]);
  }
  else
  {
    //Serial.println("Lebih Jauh");
  }
}
void showTblRouting()
{
  Serial.println("########## Table Routing #######");
  for(int node = 2; node <= nodeClient; node++)
  {
    Serial.print("Node Ke ");
    Serial.print(node);
    Serial.print(" ");
    Serial.println(hasilRouting[node][0]);
  }
  Serial.println("########## ------------- #######");
}
void showFromNodeData()
{
  Serial.println("########## Data AODV #######");
  Serial.print("Data RAW: ");
  Serial.println(data);
  Serial.print("From    :");
  Serial.println(valSplitNode[banyakNodeYgDiLalui]);
  Serial.print("Route   :");
  Serial.println(valSplit[4]);
  Serial.print("Message :");
  Serial.println(valSplit[3]);
  Serial.println("########### END ################");
  int nodeActive = valSplitNode[banyakNodeYgDiLalui].toInt();
  active[nodeActive] = true;
}


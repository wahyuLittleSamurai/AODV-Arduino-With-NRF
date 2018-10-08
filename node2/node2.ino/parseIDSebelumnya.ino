void parseNodeBefore(String text, String key) //sama dengan Server
{
  String nodeId = String(text);
  nodeId += key;
  int countSplitNode=0;
  int lastIndexNode=0;
  for(int j = 0; j < nodeId.length(); j++)
  {
    if(nodeId.substring(j, j+1) == key)
    {
      valSplitNode[countSplitNode] = nodeId.substring(lastIndexNode,j);
      lastIndexNode = j + 1;
      //Serial.println();
      //Serial.print(countSplitNode);
      //Serial.print(":");
      //Serial.println(valSplitNode[countSplitNode]);
      banyakNodeYgDiLalui = countSplitNode;
      countSplitNode++;
    }
  }
  longRute = countSplitNode;
  //Serial.println();
  //Serial.println(banyakNodeYgDiLalui);
}
void putNodeBefore(int myID)//func untuk mengambil nilai ID pada rute
{
  String idString = String(myID);
  for(int node = 0; node <= banyakNodeYgDiLalui; node++)//ulang sampai panjang rute
  {
    if(valSplitNode[node] == idString)  //jika rute sama dengan id milik (exmpl: data rute= 1>2>3>4, id sendiri = 2, maka id yg akan di ambil adalah 1)
    {
      IdNextNodeRREP = valSplitNode[node-1];//ambil ID yg sama dengan id milik-1
      Serial.print("Node selanjutnya: ");
      Serial.println(IdNextNodeRREP);
    }
  }
}


void parseNodeBefore(String text, String key) //func untuk memisahkan data
{
  String nodeId = String(text); //ambil ID milik sendiri
  nodeId += key;  //data yang akan digunakan sebagai separator (exmpl: data RAW= 1>2>3 separatore = ">")
  int countSplitNode=0;
  int lastIndexNode=0;
  for(int j = 0; j < nodeId.length(); j++)  //ulang panjang data
  {
    if(nodeId.substring(j, j+1) == key) //apabila ada data RAW = ">", maka...
    {
      valSplitNode[countSplitNode] = nodeId.substring(lastIndexNode,j); //pisah data tersebut ke dalam sebuah variable String Array (valSplitNode[])
                                                                        //exmpl : 1>2>3 ==>> valSplitNode[0] = 1, valSplitNode[2] = 2 .... valSplitNode[n]=n
      lastIndexNode = j + 1;
      //Serial.println();
      //Serial.print(countSplitNode);
      //Serial.print(":");
      //Serial.println(valSplitNode[countSplitNode]);
      banyakNodeYgDiLalui = countSplitNode;
      countSplitNode++;
    }
  }
  //Serial.println("Node pengirim: ");
  //Serial.println(banyakNodeYgDiLalui);
}

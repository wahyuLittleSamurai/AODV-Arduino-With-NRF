void parseNodeBefore(String text, String key) //jika Node Dest RREQ = myID
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
  //Serial.println("Node pengirim: ");
  //Serial.println(banyakNodeYgDiLalui);
}

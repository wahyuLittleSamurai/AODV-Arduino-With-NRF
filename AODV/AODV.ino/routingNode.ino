void routingNode(char text[], int timeOut)
{
  millis();
  for(int ulang2x = 0; ulang2x<=ulangRouting; ulang2x++)
  {
    for(int node = 2; node <= nodeClient; node++)
    {
      flag = false;
      millisNow = millis();
      while((millis()-millisNow) <= timeOut*1000)
      {
        if(!flag)
        {
          String newRoute = "";
          newRoute = String(node);
          n = newRoute.length() + 1;
          xx[n];
          newRoute.toCharArray(xx, n);
          
          sendingData(xx,text);
          
          receiveData(false);
          
          flag = true;
        }
        receiveData(false);
      }
    }
  }
}


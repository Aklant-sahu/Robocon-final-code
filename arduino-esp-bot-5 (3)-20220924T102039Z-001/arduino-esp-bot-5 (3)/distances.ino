double distance1()
{

  int VoRaw1 = analogRead(IR1);

  float Vo1 = (5.0 * VoRaw1) / 1024.0;
 

  float dist1 = 0;
  if ( Vo1 > b )
  {
    dist1 = a / (Vo1 - b);
    dist1=dist1/10;
    if(dist1<=3){
      dist1=3;
    }
  }

 
//
//dist1=SharpIRfrontleft.distance();
//dist2=SharpIRfrontright.distance();
  Serial.print(dist1);
   Serial.print(" ");
   return dist1;
  
    
}
double distance2(){
   int VoRaw2 = analogRead(IR2);

  float Vo2 = (5.0 * VoRaw2) / 1024.0;

  float dist2 = 0;
  if ( Vo2 > b ) 
  {
    dist2 = a / (Vo2 - b);
    dist2=dist2/10;
    if(dist2<=3){
      dist2=3;
    }
  }
  Serial.print(dist2);
     Serial.print(" ");
      return dist2;
}

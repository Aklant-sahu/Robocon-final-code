void autopickup()
{
     double dist1=distance1();
     double dist2=distance2();
  if (rr1 != prevrr1) {

    if (rr1== HIGH) {
      if( rr1mod==0){
     Serial.println("Auto Rack activated");
        rr1mod=1;
   }
    else if (rr1mod==1){
      
      Serial.println("Stopped Auto rack");
      rr1mod=0;
    }
    }
 
  }
prevrr1=rr1;

if(rr1mod==1){
  double err=dist1-dist2;
//  double err=2-1;

  Serial.print(err);
  
  Serial.print(" ");

  
  if(dist1>=0 ){

if(dist1>mindist3){

if(err>0){
  int output=kp*err;
  if(output>=255){
    output=255;
  }
  
 clk(output);
}
else if(err<0){
    int output=-kp*err;
    if(output>=255){
    output=255;
  }
anticlk(output);
}
moveF(60);


}
  
else if(dist1>=mindist2 && dist1<mindist3){
moveF(60);
  leftIntake.setDir(HIGH);
  leftIntake.setPwm(spb);
  rightIntake.setDir(HIGH);
  rightIntake.setPwm(spb);
}
else if(dist1>=mindist1 && dist1<mindist2){
moveF(40);
  leftIntake.setDir(HIGH);
  leftIntake.setPwm(spb);
  rightIntake.setDir(HIGH);
  rightIntake.setPwm(spb);
}
else{
   moveF(0);
  leftIntake.setDir(HIGH);
  leftIntake.setPwm(spb);
  rightIntake.setDir(HIGH);
  rightIntake.setPwm(spb);
  
}

}
}
else if(rr1mod==0){
  if(ll1<50){
      leftIntake.setDir(HIGH);
  leftIntake.setPwm(0);
  rightIntake.setDir(HIGH);
  rightIntake.setPwm(0);
  }
  else{
     
       int val=map(ll1,50,255,0,spb);
        leftIntake.setDir(LOW);
        leftIntake.setPwm(val);
        rightIntake.setDir(LOW);
        rightIntake.setPwm(val);
        Serial.println("Release Balls");
        
  }




  
}
}
void clk(int output){
      leftFront.setDir(HIGH);
  leftBack.setDir(HIGH);
   rightFront.setDir(LOW);
   rightBack.setDir(LOW);
  
  leftFront.setPwm(output);
  leftBack.setPwm(output);
  rightFront.setPwm(output);
  rightBack.setPwm(output);

  Serial.print("Rotating clk");
    Serial.println(output);
}
void anticlk(int output){
  leftFront.setDir(LOW);
  leftBack.setDir(LOW);
   rightFront.setDir(HIGH);
   rightBack.setDir(HIGH);
  
  leftFront.setPwm(output);
  leftBack.setPwm(output);
  rightFront.setPwm(output);
  rightBack.setPwm(output);

  Serial.print("Rotating anti-clk");
  Serial.println(output);
}
void moveF(int speeding){
  leftFront.setDir(LOW);
leftBack.setDir(LOW);
rightFront.setDir(LOW);
rightBack.setDir(LOW);
leftFront.setPwm(speeding);
leftBack.setPwm(speeding);
rightFront.setPwm(speeding);
rightBack.setPwm(speeding);
}

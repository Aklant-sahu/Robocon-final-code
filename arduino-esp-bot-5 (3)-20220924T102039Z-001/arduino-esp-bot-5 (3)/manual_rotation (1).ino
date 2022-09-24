void clockwise()
{

 
speed_slow=map(rr2, 40, 255, 0, slow);

   leftFront.setDir(HIGH);
  leftBack.setDir(HIGH);
   rightFront.setDir(LOW);
   rightBack.setDir(LOW);
  
  leftFront.setPwm(speed_slow);
  leftBack.setPwm(speed_slow);
  rightFront.setPwm(speed_slow);
  rightBack.setPwm(speed_slow);

  Serial.println("CLockwise");

  
}



void anticlockwise()
{
speed_slow=map(ll2, 40, 255, 0, slow);

 leftFront.setDir(LOW);
  leftBack.setDir(LOW);
   rightFront.setDir(HIGH);
   rightBack.setDir(HIGH);
  
  leftFront.setPwm(speed_slow);
  leftBack.setPwm(speed_slow);
  rightFront.setPwm(speed_slow);
  rightBack.setPwm(speed_slow);

  Serial.println("Anti-CLockwise");

  
}
void manualRotation()
{
  if (rr2>40)
  {
    clockwise();
  }
  else if(ll2>40)
  {
    anticlockwise();
  }
}

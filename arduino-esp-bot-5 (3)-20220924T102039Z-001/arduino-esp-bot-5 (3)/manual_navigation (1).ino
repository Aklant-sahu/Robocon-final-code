void forward_fast(int speed_fast){
 
  leftFront.setDir(HIGH);
  leftBack.setDir(HIGH);
   rightFront.setDir(HIGH);
   rightBack.setDir(HIGH);
  
  leftFront.setPwm(speed_fast);
  leftBack.setPwm(speed_fast);
  rightFront.setPwm(speed_fast);
  rightBack.setPwm(speed_fast);
    
  
}

void forward_slow(int speed_slow)
{
   

  leftFront.setDir(HIGH);
  leftBack.setDir(HIGH);
   rightFront.setDir(HIGH);
   rightBack.setDir(HIGH);
  
  leftFront.setPwm(speed_slow);
  leftBack.setPwm(speed_slow);
  rightFront.setPwm(speed_slow);
  rightBack.setPwm(speed_slow);
 
  
  
}


void backward_fast(int speed_fast){ 
 
 leftFront.setDir(LOW);
  leftBack.setDir(LOW);
   rightFront.setDir(LOW);
   rightBack.setDir(LOW);
  
  leftFront.setPwm(speed_fast);
  leftBack.setPwm(speed_fast);
  rightFront.setPwm(speed_fast);
  rightBack.setPwm(speed_fast);

  
}

void backward_slow(int speed_slow)
{
 
  leftFront.setDir(LOW);
  leftBack.setDir(LOW);
   rightFront.setDir(LOW);
   rightBack.setDir(LOW);
  
  leftFront.setPwm(speed_slow);
  leftBack.setPwm(speed_slow);
  rightFront.setPwm(speed_slow);
  rightBack.setPwm(speed_slow);

 
}

void right_fast(int speed_fast)
{

  leftFront.setDir(HIGH);
  leftBack.setDir(LOW);
   rightFront.setDir(LOW);
   rightBack.setDir(HIGH);
  leftFront.setPwm(speed_fast);
  leftBack.setPwm(speed_fast);
  rightFront.setPwm(speed_fast);
  rightBack.setPwm(speed_fast);

}


void right_slow(int speed_slow)
{
  
 leftFront.setDir(HIGH);
  leftBack.setDir(LOW);
   rightFront.setDir(LOW);
   rightBack.setDir(HIGH);
  leftFront.setPwm(speed_slow);
  leftBack.setPwm(speed_slow);
  rightFront.setPwm(speed_slow);
  rightBack.setPwm(speed_slow);
  

  
}

void left_fast(int speed_fast)
{

  leftFront.setDir(LOW);
  leftBack.setDir(HIGH);
   rightFront.setDir(HIGH);
   rightBack.setDir(LOW);
  leftFront.setPwm(speed_fast);
  leftBack.setPwm(speed_fast);
  rightFront.setPwm(speed_fast);
  rightBack.setPwm(speed_fast);

  
}

void left_slow(int speed_slow)
{
 leftFront.setDir(LOW);
  leftBack.setDir(HIGH);
   rightFront.setDir(HIGH);
   rightBack.setDir(LOW);
  leftFront.setPwm(speed_slow);
  leftBack.setPwm(speed_slow);
  rightFront.setPwm(speed_slow);
  rightBack.setPwm(speed_slow);


}
void stop_Motors(){
  leftFront.killMotor();
  leftBack.killMotor();
  rightFront.killMotor();
   rightBack.killMotor();
}

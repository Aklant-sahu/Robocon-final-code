void manualIntake(){
  
      if(ll1>50){
        
          if(digitalRead(intakeretract)==HIGH){
            leftIntake.setDir(LOW);
        leftIntake.setPwm(0);
        rightIntake.setDir(LOW);
        rightIntake.setPwm(0);
         Serial.println("intake limit switch trigerred");
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
          else if(rr1>=1){
        
       leftIntake.setDir(HIGH);
        leftIntake.setPwm(spb);
        rightIntake.setDir(HIGH);
        rightIntake.setPwm(spb);
        Serial.println("Hold balls");

   }
   else{
    

        leftIntake.setPwm(0);

        rightIntake.setPwm(0);
        Serial.println("stop intake");

   }
}

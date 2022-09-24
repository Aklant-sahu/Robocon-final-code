

void lift_up(){

 megaTorque.setDir(HIGH);
 megaTorque.setPwm(spg);
        Serial.println("Lift up");
}

void lift_down(){
 megaTorque.setDir(LOW);
 megaTorque.setPwm(spg);       
        Serial.println("Lift down");
      
}

void manualLift(){

  if (tri != lastliftupstate) {

    if (tri== HIGH) {
      if( lifting_up==0){
//     Serial.println("liftup");
        lifting_up=1;

   }
    else if (lifting_up==1){
       megaTorque.setPwm(0);
      Serial.println("stop lift");
      lifting_up=0;
    }
    }
 
  }
lastliftupstate = tri;

  if (cro != lastliftdownstate) {

    if (cro== HIGH) {
      if( lifting_down==0){
//     Serial.println("liftdown");
        lifting_down=1;

   }
    else if (lifting_down==1){
       megaTorque.setPwm(0);
      Serial.println("stop lift");
      lifting_down=0;
    }
    }
 
  }
lastliftdownstate = cro;

if(lifting_up==1 && lifting_down==1){
  megaTorque.setPwm(0);
  lifting_up=0;
  lifting_down=0;
  
}
else{
  if(lifting_up==1){
    if(digitalRead(megaup)==LOW){
      lifting_up=0;
      Serial.println("megaup limit switch");
    }
    else{
     lift_up();
    }
  }
  else if(lifting_down==1){
    if(digitalRead(megadown)==LOW){
      countermega=0;
      megaposcount=0;
//     
      lifting_down=0;
       Serial.println("megadown limit switch");
    }
    else{
     lift_down();
    }
 }

else{
   megaTorque.setPwm(0);
   Serial.println("stop lift");
}
 
}

}

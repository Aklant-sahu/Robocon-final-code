 void chax() {

  if(digitalRead(chBx)==LOW) {
  counterx++;
  }else{
  counterx--;
  }

  }
   
  void chbx() {
 
  if(digitalRead(chAx)==LOW) {
  counterx--;
  }else{
  counterx++;
  }

  }
   
  void chay() {

  if(digitalRead(chBy)==LOW) {
  countery++;
  }else{
  countery--;
  }

  }
   
  void chby() {

  if(digitalRead(chAy)==LOW) {
  countery--;
  }else{
  countery++;
  }

  }
  void megacha() {

  if( megaTorque.getDir()==HIGH) {
  countermega++;
  }
  else if(megaTorque.getDir()==LOW){
  countermega--;
  }

  }

    void intakecha() {

  if( leftIntake.getDir()==HIGH) {
  counterintake++;
  }
  else if(leftIntake.getDir()==LOW){
  counterintake--;
  }

  }

void switchNavigationDecision()
{
  if( (lx!=0 || ly!=0) ) // this condition wasnt working because lx and ly can range from 127 to -128
  {
 if (ly<buff2 && (lx>bufneg && lx<bufpos))
      {
        speed_fast=map(ly, buff2, -128, 0, fast);
        backward_fast(speed_fast);
      }
   
  else if(ly>buff1 && (lx>bufneg && lx<bufpos))
      {
         speed_fast=map(ly, buff1, 127, 0, fast);
        forward_fast(speed_fast);
      }
  else if(lx<buff2 && (ly>bufneg && ly<bufpos))
      {
          speed_fast=map(lx, buff2, -128, 0, fast);
        right_fast(speed_fast);
        
      }
  else if(lx>buff1 && (ly>bufneg && ly<bufpos))
      {
         speed_fast=map(lx, buff1, 127, 0, fast);
        
        left_fast(speed_fast);
        //Serial.print(lx);
      }

  }
  else if((rx!=0 || ry!=0) )
  {
    
if(ry<buff2 && (rx>bufneg && rx<bufpos))
      {
        
         speed_slow = map(ry, buff2, -128, 0, slow);
        backward_slow(speed_slow);
       
      }
  else if(ry>buff1 &&( rx>bufneg && rx<bufpos))
      {
        speed_slow = map(ry,buff1, 127, 0,slow);
        forward_slow(speed_slow);
      }
  else if(rx<buff2 && (ry>bufneg && ry<bufpos))
      {
         speed_fast=map(rx, buff2, -128, 0,slow);
        right_slow(speed_slow);
        
      }
  else if(rx>buff1 && (ry>bufneg && ry<bufpos))
      {
         speed_fast=map(rx, buff1, 127, 0, slow);
       
        left_slow(speed_slow);
      }
  }

 else if(ll2<10 && rr2<10 && rr1mod==0){

            stop_Motors();
           Serial.println("stopMotors");
      }
}

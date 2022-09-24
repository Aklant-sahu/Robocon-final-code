#include <Ps3Controller.h>
int lX,lY,rX,rY,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,ll2,rr1,rr2,start;
#include<HardwareSerial.h>
#define RXp2 16
#define TXp2 17
void send(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,int m,int n,int o,int p,int q)
{


    Serial2.print(a); 
    Serial2.print("A");
    Serial2.print(b);
    Serial2.print("B");
    Serial2.print(c); 
    Serial2.print("C");
    Serial2.print(d);
    Serial2.print("D");
    Serial2.print(e);
    Serial2.print("E");
    Serial2.print(f);
    Serial2.print("F");
    Serial2.print(g);
    Serial2.print("G");
    Serial2.print(h);
    Serial2.print("H");
    Serial2.print(i);
    Serial2.print("I");
    Serial2.print(j);
    Serial2.print("J");
    Serial2.print(k);
    Serial2.print("K");
    Serial2.print(l);
    Serial2.print("L");
    Serial2.print(m);
    Serial2.print("M");
    Serial2.print(n);
    Serial2.print("N");
    Serial2.print(o);
    Serial2.print("O");
    Serial2.print(p);
    Serial2.print("P");
      Serial2.print(q);
    Serial2.print("Q");
    Serial2.print("!");
    // Serial.print(a); 

}

void setup()
{   Serial.begin(115200);
    Serial2.begin(57600, SERIAL_8N1, RXp2, TXp2);
    //Ps3.begin("b4:e6:2d:e9:58:9d");// myesp
//Ps3.begin("c8:c9:a3:fb:21:ee"); //  aayush1
Ps3.begin("00:12:34:56:78:9b"); 

//
//  Serial2.println("AT+IPR=9600");
//  delay(1000);
//  Serial2.end();
//  // Start the software serial for communication with the ESP8266
//  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
//
//  Serial.println("Ready");
//  Serial2.println("AT+GMR");
}

void loop()
{

  if (Ps3.isConnected()){
    
 lX =(Ps3.data.analog.stick.lx);
 lY =(Ps3.data.analog.stick.ly);
 rX =(Ps3.data.analog.stick.rx);
 rY =(Ps3.data.analog.stick.ry);
 cro=(Ps3.data.analog.button.cross);
 squ=(Ps3.data.analog.button.square);
 tri=(Ps3.data.analog.button.triangle);
 cir=(Ps3.data.analog.button.circle);
// upp=(Ps3.data.analog.button.up);
//downn=(Ps3.data.analog.button.down);
// leftt=(Ps3.data.analog.button.left);
// rightt=(Ps3.data.analog.button.right);
  upp=(Ps3.data.button.up);
downn=(Ps3.data.button.down);
 leftt=(Ps3.data.button.left);
 rightt=(Ps3.data.button.right);
 
ll1=(Ps3.data.analog.button.l1);
rr1=(Ps3.data.button.r1);
//ll1=(Ps3.data.button.l1);
//rr1=(Ps3.data.button.r1);

ll2=(Ps3.data.analog.button.l2);
rr2=(Ps3.data.analog.button.r2);
start=(Ps3.data.button.start);
 
// Serial.println(ll1);
 
 
if (lX==-1){lX=0;}
if (lY==-1){lY=0;}
if (rX==-1){rX=0;}
if (rY==-1){rY=0;}
// Serial.print(lX); Serial.print("A");
//    Serial.print(lY); Serial.print("B");
//    Serial.print(rX); Serial.print("C");
//    Serial.print(rY); Serial.print("D");
//    Serial.print("\n");
send(lX,lY,rX,rY,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,ll2,rr1,rr2,start);
  }

}

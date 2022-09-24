#include <Pid.h>
#include <Base_chasis.h>
#include<SharpIR.h>

/*-----Limit Switches and control parameters-----------*/
#define megaup A8
#define megadown A7
#define intakeretract 52
int mindist1=4,mindist2=7,mindist3=9,pre_intake=0,kp=30;
int prevrr1=0,rr1mod=0;


/*-----distance sensors-----------*/
  const float a = 118.875;
  const float b = 0.03875;
#define IR1 A10
#define IR2 A9
#define IR3 A1
#define IR4 A2
#define model 430
int dist1=0,dist2=0,dist3=0,dist4=0;
//SharpIR SharpIRfrontleft(IR1, model); //left side
//SharpIR SharpIRfrontright(IR2, model);
//SharpIR SharpIRbackleft(IR3, model); //left side
//SharpIR SharpIRbackright(IR4, model);// right side


/*----------------------Start button state--------------------------*/
     
int lastButtonState = 0,lastSelectState=0;
int mode=0;
int emergencyStop=0;



/*----------------------Interrupts--------------------------*/
long counterx=0,countery=0,countermega=0,counterintake=0;
int chAy=21,chBy=20;
int chAx=2,chBx=3;
int megachA=18;
//int intakechA=19;

/*----------------------Stepper motor--------------------------*/

const int stepPin1 = 44; 
const int dirPin1 =51; 
const int enPin1 = 49;
const int stepPin2 = 45; 
const int dirPin2 =47; 
const int enPin2 = 43;
//const int stepdelay=700;
int prev_state=0;
char prev_step_state='H';
int stepcount=0;
int stepclosestate=0,stepopenstate=0;
int targetstep=0,prevstep=0;

int stepopenmode=0,stepclosemode=0;
int steppos[]={0,200,400,500,600,800};


/*---------------------Base motor--------------------------*/

const int maxspeed=100;
Base_chasis leftFront(33,HIGH,7,1,HIGH,LOW);
Base_chasis leftBack(31,HIGH,8,2,HIGH,LOW);
Base_chasis rightFront(35,HIGH,6,3,HIGH,LOW);
Base_chasis rightBack(29,HIGH,5,4,HIGH,LOW);


//Pid Left1(counterx,int dirpin1,int refdir1,int &dir1);
//Pid Left2(counterx,int dirpin1,int refdir1,int &dir1);
//Pid Right1(counterx,int dirpin1,int refdir1,int &dir1);
//Pid Right2(counterx,int dirpin1,int refdir1,int &dir1);


/*----------------------Mega torque motor---lift--------------------------*/

int spg =255;
int mega_dir=HIGH;
int lifting_up=0,lifting_down=0,lastliftupstate=0,lastliftdownstate=0;
Base_chasis megaTorque(27,mega_dir,10,5,HIGH,LOW);
Pid mega(10,mega_dir);

int megaposcount=0;
int lastsqu=0,lastcir=0;
int cirmode=0;

/*----------------------Intake motor--------------------------*/


int spb = 180;
int left_int=HIGH;
Base_chasis leftIntake(39,left_int,4,1,HIGH,LOW);
Base_chasis rightIntake(25,LOW,3,1,HIGH,LOW);
//Pid intake(4,HIGH,left_int);


/*----------------------Data parsing--------------------------*/
char c;
int indexA,indexB,indexC,indexD,indexE,indexF,indexG,indexH,indexI,indexJ,indexK,indexL,indexM,indexN,indexO,indexP,indexQ,indexR;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14,data15,data16,data17,data18;
int lx,ly,rx,ry,cro,squ,tri,cir,upp,downn,leftt,rightt,ll1,ll2,rr1,rr2,start,select;

int upc=0, gripc=0, lc=0, rc=0;
int speedm = 25;
int speed_fast =0;
int speed_slow =0;
int fast = 180;
int slow = 120;

/*----------------------Timing operations--------------------------*/
int bufpos=40;
int bufneg=-40;
int buff1=40;
int buff2=-40;
//unsigned long timer=millis();
static uint32_t timer1=0,timer2=2,timer3=3;

unsigned long currentMicros;
int interval1=10;
int interval2=10;


 String datain ;
/*------------------------------------------------*/



void setup() {
  mega.setGains(0.5,0.001,0);
  mega.setSetPoint(megaposcount);
  mega_dir=HIGH;
  Serial.begin(74880);
  Serial2.begin(38400);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(chAx,INPUT_PULLUP);
  pinMode(chBx,INPUT_PULLUP);
  pinMode(chAy,INPUT_PULLUP);
  pinMode(chBy,INPUT_PULLUP);
  pinMode(enPin1,OUTPUT);
  digitalWrite(enPin1,LOW);
  pinMode(enPin2,OUTPUT);
  digitalWrite(enPin2,LOW);

//  attachInterrupt(digitalPinToInterrupt(chAx), chax,RISING);
//  attachInterrupt(digitalPinToInterrupt(chBx), chbx, RISING);
//  attachInterrupt(digitalPinToInterrupt(chAy), chay,RISING);
//  attachInterrupt(digitalPinToInterrupt(chBy), chby, RISING);
  attachInterrupt(digitalPinToInterrupt(megachA), megacha,CHANGE);
//  attachInterrupt(digitalPinToInterrupt(intakechA), intakecha,CHANGE);

    leftFront.killMotor();
     leftBack.killMotor();
    rightFront.killMotor();
    rightBack.killMotor();
    megaTorque.killMotor();
    leftIntake.killMotor();
    rightIntake.killMotor();
           Serial.println("stopMotors");

 
 leftFront.begin(true,maxspeed);
 leftBack.begin(true,maxspeed);
 rightFront.begin(true,maxspeed);
 rightBack.begin(true,maxspeed);
 megaTorque.begin(true,spg);
 leftIntake.begin(true,spb);
 rightIntake.begin(true,spb);


}

void loop() {
  
  fetch_data();
  parse_data(datain); 
  ps_print();

//Serial.println(megaposcount);




if (cir != lastcir) {

    if (cir== HIGH) {
      if(cirmode==0){
      cirmode=1;
 
     megaposcount=megaposcount+4151;
     mega.setSetPoint(megaposcount);
   
    }
    else if(cirmode==1){
      cirmode=0;
    }
    }
 
  }
lastcir =cir;

if (select != lastSelectState) {

    if (select== HIGH) {
      if( emergencyStop==0){
     Serial.println("Emergency stopped");
        emergencyStop=1;

   }
    else if (emergencyStop==1){
      
      Serial.println("Normal mode");
      emergencyStop=0;
    }
    }

  }
lastSelectState= select;

  if (start != lastButtonState) {
  
   if (start== HIGH) {
      if( mode==0){
         leftFront.setPwm(0);
     leftBack.setPwm(0);
    rightFront.setPwm(0);
    rightBack.setPwm(0);
    megaTorque.setPwm(0);
    leftIntake.setPwm(0);
    rightIntake.setPwm(0);
     Serial.println("Autonomus");
        mode=1;

   }
    else if (mode==1){
             leftFront.setPwm(0);
     leftBack.setPwm(0);
    rightFront.setPwm(0);
    rightBack.setPwm(0);
    megaTorque.setPwm(0);
    leftIntake.setPwm(0);
    rightIntake.setPwm(0);
      Serial.println("Manual");
      mode=0;
    }
    }
 
  }
lastButtonState = start;

if(emergencyStop==0){

   if( mode==1){
      Serial.println("Autonomus");
    switchNavigationDecision();

   manualRotation();
    autopickup();

   

   }
    else if( mode==0){
      
      manualNavigationDecision();
      manualRotation();
      manualLift();
      manualIntake();
  if(upp==1){
    countermega=0;
    megaposcount=0;
     mega.setSetPoint(megaposcount);
  }
  if(cirmode==1){
if(digitalRead(megaup)==LOW){
     megaTorque.setDir(mega_dir);
   megaTorque.setPwm(0);
     megaposcount=0;
     //
      mega.setSetPoint(megaposcount);
      //
     
      Serial.println("megaup limit switch");
         cirmode=0;
    }
    else{
    if(abs(megaposcount-countermega)>80){
   double op= mega.calculate(countermega,mega_dir);
    Serial.println(op);
    Serial.println(mega_dir);
   megaTorque.setDir(mega_dir);
   megaTorque.setPwm(op);
   
    }
     else{
    megaTorque.setDir(mega_dir);
   megaTorque.setPwm(0);
   cirmode=0;
  }
    }
  }
      
      Serial.println(megaposcount);
        
//            manualGripper();
      
      if ((leftt==1 || rightt==1)){
            manualGripper();
            }
             Serial.println(stepcount);
             Serial.println(targetstep);
//       Serial.println("Manual");
   }
}
else if(emergencyStop==1){
   leftFront.killMotor();
     leftBack.killMotor();
    rightFront.killMotor();
    rightBack.killMotor();
    megaTorque.killMotor();
    leftIntake.killMotor();
    rightIntake.killMotor();
     Serial.println("Emergency stopped");
}
// 

  datain="";



}

void Servo0()
 {

if(CPS.Button(PSB_PAD_UP)) {
  
  angle = angle + angleStep;  
  writeServos(0, angle);  
  }
      
else if(CPS.Button(PSB_PAD_DOWN)) {
  
   angle = angle - angleStep;  
   writeServos(0, angle);  }
 }  

void Servo1()
 {
    
if(CPS.Button(PSB_PAD_LEFT)) {    
            
  angle1 = angle1 + angleStep;  
  writeServos(1, angle1);  }

else if(CPS.Button(PSB_PAD_RIGHT)) {
      
  angle1 = angle1 - angleStep;  
  writeServos(1, angle1);  }    
 }  

void Servo2()
 {
    
if(CPS.Button(PSB_L1)) {    
      
   angle2 = angle2 + angleStep;  
   writeServos(2, angle2); }

else if(CPS.Button(PSB_R1)) { 

   angle2 = angle2 - angleStep;  
   writeServos(2, angle2); }
 }  

void Servo3()
 {

if(CPS.Button(PSB_L2)) {  
  
  angle3 = angle3 + angleStep;  
  writeServos(3, angle3); }

else if(CPS.Button(PSB_R2)) { 
   
   angle3 = angle3 - angleStep;  
   writeServos(3, angle3); }
 }  

void Servo4()
 {
    
if(CPS.Button(PSB_PINK)) {   
  
  angle4 = angle4 + angleStep;  
  writeServos(4, angle4); }

else if(CPS.Button(PSB_BLUE)) { 
  
  angle4 = angle4 - angleStep;  
  writeServos(4, angle4); }
 }  

void Servo5()
  {

if(CPS.Button(PSB_GREEN)) {   
            
   angle5 = angle5 - angleStep;  
   writeServos(5, angle5); }
      
else if(CPS.Button(PSB_RED)) {   
  
  angle5 = angle5 + angleStep;  
  writeServos(5, angle5);  }
 }

 
//============ Void Setup ================//


void writeServos(int nServo, int posicao) {
#define SERVOMIN  205 
#define SERVOMAX  409 

  int pos = map ( posicao , 0 , 180 , SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo , 0, pos);
}

void beginServos() {

#define Frequencia 50 

  pwm.begin(); 
  pwm.setPWMFreq(Frequencia); 
}  

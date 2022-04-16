//================== Wesley Seven:  =======================//

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <PS2X_lib.h>  
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <NewPing.h>
#include "DFRobotDFPlayerMini.h"
#include <Adafruit_NeoPixel.h>

#define endereco 0x27
#define colunas 16
#define linhas 2
#define trigger 8 
#define echo 9 
#define distancia_max 200
#define volumeMP3 30
#define pinMatrizLED 7

SoftwareSerial BT (11,10);// RX, TX
SoftwareSerial MP3Serial(13, 12); //RX, TX
NewPing sonar (trigger, echo, distancia_max);
LiquidCrystal_I2C lcd (endereco, colunas, linhas);

PS2X CPS;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, pinMatrizLED, NEO_GBR + NEO_KHZ800);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
DFRobotDFPlayerMini playerMP3;

char texto;
float distancia;
int error = 0; 
byte type = 0;
byte vibrate = 0;
int mode = 0;   

void writeServos(int posicao, int tempo);
void beginServos();   

  int angle=90;
  int angle1=90;
  int angle2=90;
  int angle3=90;
  int angle4=90;
  int angle5=90;

  int angleStep=2;

  int MT1 = 40;
  int MT2 = 42;
  int MT3 = 41;
  int MT4 = 43;
  int ENA = 44;
  int ENB = 45;
  int VEL; 

void setup(){

  beginServos();
  MP3Serial.begin(9600);
  BT.begin(9600);
  delay(300);
 
  pinMode (MT1, OUTPUT);
  pinMode (MT2, OUTPUT);
  pinMode (MT3, OUTPUT);
  pinMode (MT4, OUTPUT);

 error = CPS.config_gamepad(24,23,25,22, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

  strip.begin();
  strip.show();        
  strip.setBrightness(50);

  playerMP3.begin(MP3Serial);
  playerMP3.volume(volumeMP3);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(3, 0);
  lcd.print("iniciando");
  delay(1500);
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print("Projeto");
  lcd.setCursor(1, 1);
  lcd.print("Greifen - 2021");
 
}  

void loop(){

      if(error == 1)
      return; 

      CPS.read_gamepad(false, vibrate); 


//============= controle sobre os motores ==============//

      Frente();  //PSS_LY

      Re();       //PSS_LY

      Direita();  //PSS_LX

      Esquerda(); //PSS_LX


//============= Controle sobre o braço ==============//

      Servo0(); //PSB_PAD_UP e PSB_PAD_DOWN
      
      Servo1(); //PSB_PAD_LEFT e PSB_PAD_RIGHT
      
      Servo2(); //PSB_L1 e PSB_R1
      
      Servo3(); //PSB_L2 e PSB_R2
      
      Servo4(); //PSB_PINK e PSB_BLUE
      
      Servo5(); //PSB_GREEN e PSB_RED

      delay(5);

//==================== Bluetooth ===================//     

if (BT.available()) {
  
    texto = BT.read();
    lcd.print(texto);

      if(texto=='@'){
        lcd.clear();
        playerMP3.playFolder(1, 1);}

      if(texto=='#'){
        lcd.backlight();  
        lcd.clear();
        playerMP3.playFolder(1, 2);}

      if(texto=='$'){
        lcd.noBacklight();
        lcd.clear();
        playerMP3.playFolder(1, 3);}

      if(texto=='.'){
        lcd.setCursor(0, 1);
        playerMP3.playFolder(1, 6);}

      if(texto=='a'){
      RGB();   }

}

 else if(texto=='*'){
  
       distancia = sonar.ping_cm(); 
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Approximation:");
       lcd.setCursor(5,1);
       lcd.print(distancia);

       delay(250); }
        
}

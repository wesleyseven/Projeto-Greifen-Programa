void Frente (){

if(CPS.Analog(PSS_LY) < 120) {
  
  //VEL = map(CPS.Analog(PSS_LY), 129, 255, 0, 255);
  
  digitalWrite(MT1, HIGH);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, HIGH);
  digitalWrite(MT4, LOW);

  analogWrite(ENA, 110);
  analogWrite(ENB, 110);

  } 
      else { Parar (); }
}

void Re (){

  if(CPS.Analog(PSS_LY) > 128) {
    
  //VEL = map(CPS.Analog(PSS_LY), 0, 127, 255, 0);

  digitalWrite(MT1, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, HIGH);

  analogWrite(ENA, 110);
  analogWrite(ENB, 110);

  }  

}

void Direita () {

   if(CPS.Analog(PSS_LX) > 128) {

  //VEL = map(CPS.Analog(PSS_LX), 129, 255, 0, 255);
  
  digitalWrite(MT1, HIGH);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, HIGH);

  analogWrite(ENA, 110);
  analogWrite(ENB, 110);

  }

}

void Esquerda () {

  if(CPS.Analog(PSS_LX) < 128) { 

  //VEL = map(CPS.Analog(PSS_LX), 0, 127, 255, 0);
  
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT3, HIGH);
  digitalWrite(MT4, LOW);

  analogWrite(ENA, 110);
  analogWrite(ENB, 110);

 }

}

void Parar () {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

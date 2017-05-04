#define TEMPABRESESAMO
#define POTABRESESAMO
#define TEMPABRESESAMO

#define IN1_6 29 
#define IN2_6 27
#define PWM_6 9

void vazaTodoMundo(){
  int timeVaza= millis();
  analogWrite(PWM_6, POTABRESESAMO);
  digitalWrite(IN1_6, LOW);
  digitalWrite(IN2_6, HIGH);
  if(millis() - timeVaza == TEMPABRESESAMO)
    paraPorta();
}

void paraPorta(){
  digitalWrite(IN1_6, HIGH);
  digitalWrite(IN2_6, HIGH);
}


void voltaPorta(){
  int timeVolta= millis();
  analogWrite(PWM_6, POTABRESESAMO);
  digitalWrite(IN1_6, HIGH);
  digitalWrite(IN2_6, LOW);
  if(millis() - timeVolta == TEMPABRESESAMO)
    paraPorta();
}

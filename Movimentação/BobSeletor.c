#define POTSELECIONA 100
#define ENTRA 1
#define SAI 0

#define IN1_3 37
#define IN2_3 35
#define PWM_3 6

#define encoder3PinA 3

// Variáveis encoder


volatile long encoder3Pos = 0;
double voltas = 0;
int entraSai = ENTRA;

void initSeletor(){
  pinMode(IN1_3, INPUT);
  pinMode(IN2_3, INPUT);
  pinMode(PWM_3, INPUT);
  pinMode(encoder3PinA, INPUT);
  digitalWrite(encoder3PinA, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder3, CHANGE);  // encoder pin on interrupt 0 - pin 2
  
}

void doEncoder3() {

  if(entraSai == ENTRA){
    encoder3Pos = encoder3Pos + 1;
  }else if(entraSai == SAI){
    encoder3Pos = encoder3Pos - 1;
  } 
}

void praDentro(){
  entraSai = ENTRA;
  if(encoder3Pos == 0){  
    digitalWrite(IN1_3, LOW);
    digitalWrite(IN2_3, HIGH);
    analogWrite(PWM_3, 100);
  }else if(encoder >= 90){
      paraSeletor();
  }

}

void paraSeletor(){
  digitalWrite(IN1_3, HIGH);
  digitalWrite(IN2_3, HIGH);
}

void praFora(){
  entraSai = SAI;
  if(encoder3Pos >= 90){  
    digitalWrite(IN1_3, HIGH);
    digitalWrite(IN2_3, LOW);
    analogWrite(PWM_3, 100);
  }else if(encoder == 0){
      paraSeletor();
  }

}
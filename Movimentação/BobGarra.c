#define POTCAPTURA 100
#define POTJOGADENTRO 100
#define POTDESCE  100//pra ficar mirando no chão
#define POTSOBE  100 //pra subir aos poucos antes de ficar perpendicular ao chão
#define ANGINICIAL_GARRA 0
#define ANG_DENTRO 120

#define DENTRO 1
#define FORA 0
#define CAPTURA 22

#define IN1_2 31
#define IN2_2 33
#define PWM_2 10


//VARIAVEIS

#define encoder3PinA 3

// Variáveis encoder


volatile long encoder2Pos = 0;
double voltas = 0;
int dentroSai = DENTRO;

void initGarra(){
  pinMode(IN1_2, INPUT);
  pinMode(IN2_2, INPUT);
  pinMode(PWM_2, INPUT);
  pinMode(encoder2PinA, INPUT);
  digitalWrite(encoder2PinA, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder2, CHANGE);  // encoder pin on interrupt 0 - pin 2
  
}

void captura(){//Levanta 45°  
  dentroSai = CAPTURA;
  if(encoder1Pos ==  ANGINICIAL_GARRA){
    analogWrite(PWM_1, POTDESCIDA);
    digitalWrite(IN1_1, HIGH); // testar
    digitalWrite(IN2_1, LOW); // TESTAR
  }
  else if(encoder1Pos => 45){
    paraCremal();
  }
}

void paraGarra(){
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN2_2, HIGH);
}

void jogaDentro(){
  dentroSai = CAPTURA;
  if(encoder1Pos >= 45){
    analogWrite(PWM_1, POTDESCIDA);
    digitalWrite(IN1_1, HIGH); // testar
    digitalWrite(IN2_1, LOW); // TESTAR
  }
  else if(encoder1Pos >= ANG_DENTRO){
    paraCremal();
  }
}

void voltaAoNormal(){
  dentroSai = FORA;
  if(encoder1Pos >= 45){
    analogWrite(PWM_1, POTDESCIDA);
    digitalWrite(IN1_1, HIGH); // testar
    digitalWrite(IN2_1, LOW); // TESTAR
  }
  else if(encoder1Pos == 0){
    paraCremal();
  } 
}

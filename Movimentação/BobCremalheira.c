//CONSTANTES
#define POTSUBIDA 100
#define POTDESCIDA 100
#define SOBE 1
#define DESCE 0
#define ANGGIROCOMPLETO

//VARIAVEIS

#define IN1_1 23
#define IN2_1 25

#define PWM_1 4

#define encoder1PinA 18

// Variáveis encoder

volatile long encoder1Pos = 0;
double voltas = 0;
int sobeDesce = SOBE;

void initCremal();
void doEncoder1();
void paraCremal();
void desceCremal();// talvez precise de delay
void sobeCremal(); // talvez precise de delay


void initCremal(){
  pinMode(IN1_1, INPUT);
  pinMode(IN2_1, INPUT);
  pinMode(PWM_1, INPUT);
  pinMode(encoder1PinA, INPUT);
  digitalWrite(encoder1PinA, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder1, CHANGE);  // encoder pin on interrupt 0 - pin 2
}

void doEncoder1() {
  if(sobeDesce == SOBE)
    encoder1Pos = encoder1Pos + 1;
  else
     encoder1Pos = encoder1Pos - 1;
}


void sobeCremal(){
  sobeDesce = SOBE;
  if(encoder1Pos == 0){
    analogWrite(PWM_1, POTSUBIDA);
    digitalWrite(IN1_1, LOW); // testar
    digitalWrite(IN2_1, HIGH); // TESTAR
  }
  else if(encoder1Pos >= ANGGIROCOMPLETO){
    paraCremal();
  } 
}

void paraCremal(){
  digitalWrite(IN1_1, HIGH);
  digitalWrite(IN2_1, HIGH);
}

void desceCremal(){
  sobeDesce = DESCE;
  if(encoder1Pos >= ANGGIROCOMPLETO){
    analogWrite(PWM_1, POTDESCIDA);
    digitalWrite(IN1_1, HIGH); // testar
    digitalWrite(IN2_1, LOW); // TESTAR
  }
  else if(encoder1Pos == 0){
    paraCremal();
  }

}

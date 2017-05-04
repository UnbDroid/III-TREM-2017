// Variáveis encoder

#define encoder0PinA 2
#define encoder0PinB 3

volatile long encoder0Pos = 0;
double voltas = 0;

//Variáveis driver

#define IN1_D5 43
#define IN2_D5 45
#define IN1_E4 39
#define IN2_E4 41

#define PWM_D5 8
#define PWM_E4 7


void doEncoderA(){

  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos = encoder0Pos + 1;         // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == HIGH) {
      encoder0Pos = encoder0Pos + 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
  //Serial.println (encoder0Pos, DEC);
  // use for debugging - remember to comment out
}

//Funções driver

void direita (int potEsquerda, int potDireita) {
  analogWrite(PWM_E4, potEsquerda);
  analogWrite(PWM_D5, potDireita);
  digitalWrite(IN1_E4, HIGH);
  digitalWrite(IN2_E4, LOW);
  digitalWrite(IN1_D5, HIGH);
  digitalWrite(IN2_D5, LOW);

}

void esquerda (int potEsquerda, int potDireita) {
  analogWrite(PWM_E4, potEsquerda);
  analogWrite(PWM_D5, potDireita);
  digitalWrite(IN1_E4, LOW);
  digitalWrite(IN2_E4, HIGH);
  digitalWrite(IN1_D5, LOW);
  digitalWrite(IN2_D5, HIGH);

}

void frente(int potEsquerda, int potDireita){
  analogWrite(PWM_E4, potEsquerda);
  analogWrite(PWM_D5, potDireita);
  digitalWrite(IN1_E4, HIGH);
  digitalWrite(IN2_E4, LOW);
  digitalWrite(IN1_D5, LOW);
  digitalWrite(IN2_D5, HIGH);

}

void tras(int potEsquerda, int potDireita){
  analogWrite(PWM_E4, potEsquerda);
  analogWrite(PWM_D5, potDireita);
  digitalWrite(IN1_E4, LOW);
  digitalWrite(IN2_E4, HIGH);
  digitalWrite(IN1_D5, HIGH);
  digitalWrite(IN2_D5, LOW);

}

void parar () {
  digitalWrite(IN1_E4, HIGH);
  digitalWrite(IN2_E4, HIGH);
  digitalWrite(IN1_D5, HIGH);
  digitalWrite(IN2_D5, HIGH);
}

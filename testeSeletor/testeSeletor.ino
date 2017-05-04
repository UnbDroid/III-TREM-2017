// Variáveis encoder

#define encoder0PinA 2


volatile long encoder0Pos = 0;
double voltas = 0;

//Variáveis driver

#define IN1_D 4
#define IN2_D 5

#define IN1_E 6
#define IN2_E 7

#define PWM_D 10
#define PWM_E 11

#define pot 50


void doEncoder() {
 encoder0Pos = encoder0Pos + 1; 
}


void setup() {

  pinMode(IN1_D, INPUT);
  pinMode(IN2_D, INPUT);
  pinMode(PWM_D, INPUT);
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  //pinMode(encoder0PinB, INPUT);
//  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk

}

void loop(){
  encoder0Pos = 0;
  char carac = Serial.read();  
    if(carac == '1'){
      Serial.println("PRA OUTRO LADO");
      digitalWrite(IN1_D, LOW);
      digitalWrite(IN2_D, HIGH);
      analogWrite(PWM_D, 120);
      while(encoder0Pos < 95){
        Serial.println(encoder0Pos);  
      }
      delay(200);
      digitalWrite(IN1_D, HIGH);
      digitalWrite(IN2_D, HIGH);
      analogWrite(PWM_D, 200);
      delay(1000);
    } 
    else if(carac == '2'){
      Serial.println("PRA UM LADO");
      digitalWrite(IN1_D, HIGH);
      digitalWrite(IN2_D, LOW);
      analogWrite(PWM_D, 120);
      while(encoder0Pos < 95){
        Serial.println(encoder0Pos);  
      }
      delay(200);
      digitalWrite(IN1_D, HIGH);
      digitalWrite(IN2_D, HIGH);
      analogWrite(PWM_D, 200);
      delay(1000);
    }
    
}



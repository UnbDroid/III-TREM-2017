//Variáveis driver

#define IN1_D 4 //laranjas
#define IN1_E 5 //amarelos
#define PWM_D 10 //azul

#define IN2_D 6 //laranjas
#define IN2_E 7 //amarelos
#define PWM_E 11 //azul


#define pot 120

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1_E, OUTPUT);
  pinMode(IN1_D, OUTPUT);
  pinMode(PWM_D, OUTPUT);
//  pinMode(IN2_E, OUTPUT);
//  pinMode(IN2_D, OUTPUT);
//  pinMode(PWM_E, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(PWM_D, pot);
  digitalWrite(IN1_E, HIGH);
  digitalWrite(IN1_D, LOW);
//  analogWrite(PWM_E, pot);
//  digitalWrite(IN2_E, HIGH);
//  digitalWrite(IN2_D, LOW);
  
  delay(2000);

  digitalWrite(IN1_E, HIGH);
  digitalWrite(IN1_D, HIGH);
//  digitalWrite(IN2_E, LOW);
//  digitalWrite(IN2_D, LOW);
  delay(1000);


  

//  
//  analogWrite(PWM_D, pot);
//  digitalWrite(IN1_E, LOW);
//  digitalWrite(IN1_D, HIGH);
//  delay(2000);
}

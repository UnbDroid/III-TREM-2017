// Todas as bagaças do giroscopio:

//
// Quick stab at a roll/pitch/yaw indicator using quaternions
//
// Jim Bourke 2/6/2013 (RCGroups.com)
//
#include <Wire.h>

#define  CTRL_REG1  0x20
#define  CTRL_REG2  0x21
#define  CTRL_REG3  0x22
#define  CTRL_REG4  0x23
#define  CTRL_REG5  0x24
#define  CTRL_REG6  0x25

int gyroI2CAddr=105;

int gyroRaw[3];                         // raw sensor data, each axis, pretty useless really but here it is.
double gyroDPS[3];                      // gyro degrees per second, each axis

float heading[3]={0.0f};                // heading[x], heading[y], heading [z]
float quaternion[4]={1.0f,0.0f,0.0f,0.0f};
float euler[3]={0.0f};

int gyroZeroRate[3];                    // Calibration data.  Needed because the sensor does center at zero, but rather always reports a small amount of rotation on each axis.
int gyroThreshold[3];                   // Raw rate change data less than the statistically derived threshold is discarded.

#define  NUM_GYRO_SAMPLES  50           // As recommended in STMicro doc
#define  GYRO_SIGMA_MULTIPLE  0         // As recommended 

float dpsPerDigit=.00875f;              // for conversion to degrees per second

//_______________________________________________________________________________________________________________________________________________________________________________

// Bagaças das rodas:

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
//______________________________________________________________________________________________________________________________________________________________________

/*O CODIGO VERDADEIRO PRA GIRAR COMEÇA AQUI*/


//valores de dir
#define FRENTE 0
#define DIREITA 1
#define TRAS 2
#define ESQUERDA 3

int giraCont=20, dir=FRENTE;      //"giraCont" começa em 20 por motivos a serem explicados abaixo; "dir" indica ao robô a direção em que está olhando, com seus valores listados acima

void defDir(){      //define o valor de "dir" dependendo da contagem. 
  dir = giraCont % 4;     // Como são 4 valores possíveis pra "dir" (frente, direita, tras, esquerda), pegando
}

void giraEsq(float ang){
  parar();
  heading[2]=0;
  calibrateGyro();
  updateGyroValues();
  updateHeadings();
  while(abs(heading[2])<ang){
    updateGyroValues();
    updateHeadings();
    direita(150, 150);
  }
  parar();
  giraCont--;
  defDir();
}

void giraDir(float ang){
  int tAnt=0, tNow=0;
  parar();
  heading[2]=0;
  calibrateGyro();
  updateGyroValues();
  updateHeadings();
  while(heading[2]<ang){
    //tAnt=millis();
    updateGyroValues();
    updateHeadings();
    direita(150, 150);
    Serial.println(heading[2]);
    //tNow=millis();
    //Serial.println(tNow-tAnt);
  }
  parar();
  giraCont++;
  defDir();
}

void printaDir(){
  if(dir==0){
    Serial.println("Frente");
  }
  else if(dir==1){
    Serial.println("Direita");
  }
  else if(dir==2){
    Serial.println("Tras");
  }
  else{
    Serial.println("Esquerda");
  }
}

void setup() {
  Serial.begin(9600);
  
  setupGyro();
  Serial.println("comecou");
}

void loop() {
  
  giraDir(90);
  printaDir();
  delay(3000);
  giraDir(90);
  printaDir();
  delay(3000);
  giraEsq(90);
  printaDir();
  delay(3000);
}

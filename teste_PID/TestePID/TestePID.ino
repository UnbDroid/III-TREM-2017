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
#define MOTOR_LEFT 2
#define MOTOR_RIGHT 3
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


#include <PID_v1.h>
double power = 100;
double powerLeft = 75, powerRight=75;
double ctrlPID;
double Klp = 2, Kli = 0.5, Kld = 0.2;
double Krp = 2, Kri = 0.5, Krd = 0.2;


PID PID_ESQ(&ctrlPID, &powerLeft, 0, Klp, Kli, Kld, DIRECT);
PID PID_DIR(&ctrlPID, &powerRight, 0, Krp, Kri, Krd, REVERSE);

void SetupPID()
{
  PID_ESQ.SetOutputLimits(50, 100);
  PID_DIR.SetOutputLimits(50, 100);
  PID_ESQ.SetSampleTime(100);
  PID_DIR.SetSampleTime(100);
  PID_ESQ.SetMode(AUTOMATIC);
  PID_DIR.SetMode(AUTOMATIC);
}

void OnFwd(int motor, int power){
  //ReadUS();
  //heading[2] *= 1.2;
 /* if(motor==MOTOR_LEFT){
    digitalWrite(MLA, HIGH);
    digitalWrite(MLB, LOW);
    analogWrite(ML_VEL, power);
  }
  else if(motor == MOTOR_RIGHT) {
    digitalWrite(MRA, LOW);
    digitalWrite(MRB, HIGH);
    analogWrite(MR_VEL, power);
  }
  else if(motor == MOTORS){
    digitalWrite(MLA, HIGH);
    digitalWrite(MLB, LOW);
    analogWrite(ML_VEL, power);
    digitalWrite(MRA, LOW);
    digitalWrite(MRB, HIGH);
    analogWrite(MR_VEL, power);
  } */
  
}


void FwdPID(){
  UpdatePID();
 // OnFwd(power);
  OnFwd(MOTOR_RIGHT, powerRight);
  OnFwd(MOTOR_LEFT, powerLeft);
}

void UpdatePID()
{
  ctrlPID = heading[2];
  PID_ESQ.Compute();
  PID_DIR.Compute();
}

void setup(){
  Serial.begin(9600);
  Serial.println("START!");
  Wire.begin();
  SetupPID();
  setupGyro();
  calibrateGyro();
  
}

void loop(){
  updateGyroValues();
  updateHeadings();
  FwdPID();
  Serial.print("giroscopio ");
  Serial.print(heading[2]);
  Serial.print("\tpowerLeft ");
  Serial.print(powerLeft);
  Serial.print("\t\tpowerRight ");
  Serial.println(powerRight);
}


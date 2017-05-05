#include <PID_v1.h>
double power = 100;
double powerLeft = 100, powerRight=100;
double ctrlPID;
double Klp = 0, Kli = 0, Kld = 0;
double Krp = 0, Kri = 0, Krd = 0;


PID PID_ESQ(&ctrlPID, &powerLeft, 0, Klp, Kli, Kld, REVERSE);
PID PID_DIR(&ctrlPID, &powerRight, 0, Krp, Kri, Krd, DIRECT);

void SetupPID()
{
  PID_ESQ.SetOutputLimits(110, 180);
  PID_DIR.SetOutputLimits(110, 180);
  PID_ESQ.SetSampleTime(100);
  PID_DIR.SetSampleTime(100);
  PID_ESQ.SetMode(AUTOMATIC);
  PID_DIR.SetMode(AUTOMATIC);
}

void OnFwd(int motor, int power){
  ReadUS();
  if(motor==MOTOR_LEFT){
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
  }
}


void FwdPID(){
  UpdatePID();
  OnFwd(power);
  OnFwd(MOTOR_RIGHT, powerRight);
  OnFwd(MOTOR_LEFT, powerLeft);
}

void UpdatePID()
{
  ctrlPID = heading[2];
  PID_ESQ.Compute();
  PID_DIR.Compute();
}

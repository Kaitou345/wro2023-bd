#include "lens.h"
#include "rotator.h"
#include "motor.h"
#include "sonar.h"
#include "angle.h"
#include "pid.h"

#define SONARL 7
#define SONARR 6
#define SONARF 8
#define MOTORPIN1 4
#define MOTORPIN2 5
#define MOTOREN 3
#define SERVO 2
#define SW 9
#define LED 13
#define LIMIT 30

Lens lens;
Rotator steering;
Motor motor;
Sonar sonarL(SONARL, 300);
Sonar sonarR(SONARR, 300);
Sonar sonarF(SONARF, 30);
Angle angle;
PID pid(sonarL, sonarR, sonarF);



void setup() {

  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  lens.Initialize();
  steering.Initialize(SERVO, 70, LIMIT);
  motor.Initialize(MOTORPIN1, MOTORPIN2, MOTOREN);
  sonarL.Initialize();
  sonarR.Initialize();
  sonarF.Initialize();
  pid.Initialize(28, 0.1, 3.5, 35);
  //angle.Initialize();
}

void loop() {
  int r = button_read();
  //delay(3000);
  if (r == 1) {
    first_round();
  }

  
  lens.ResultLog();
  //steering.SetRotation(0);
  // motor.SetSpeed(-255);
  
  //Serial.println(pid.GetOutput());
//   angle.MainLoop();
//   Serial.println(angle.GetAngle());
// motor.SetSpeed(200);
// steering.SetRotation(40);
// delay(1000);
// Serial.print(sonarL.GetDistance());
// Serial.print(".  ");
// Serial.print(sonarR.GetDistance());
// Serial.print(".  ");
// Serial.println(sonarF.GetDistance());


}
  

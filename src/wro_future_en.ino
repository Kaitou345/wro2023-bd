#include "lens.h"
#include "motor.h"
#include "sonar.h"
#include "rotator.h"
#include "pid.h"

#define SERVO 2 
#define SERVO_NEUTRAL 70
#define SERVO_CLAMP 25
#define LEFT 1
#define RIGHT -1

#define SONARR 8
#define SONARL 9
#define SONAR_DISTANCE 300
#define COMFORTABLE_DISTANCE 30


#define MOTOR_PIN1 4
#define MOTOR_PIN2 5 
#define MOTOR_EN 3

#define LED 13
#define SWITCH 12

Lens lens;
unsigned long timer;
unsigned long stop_timer;
bool should_stop = false;
byte turn_counter = 0;


Sonar sonarL(SONARL, SONAR_DISTANCE);
Sonar sonarR(SONARR, SONAR_DISTANCE);

Motor motor;
Rotator steering;

PID pid(sonarL, sonarR);

void setup() {
  // put your setup code here, to run once:
  timer = millis();

  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  lens.Initialize();
  sonarL.Initialize();
  sonarR.Initialize();
  motor.Initialize(MOTOR_PIN1, MOTOR_PIN2, MOTOR_EN);
  steering.Initialize(SERVO, SERVO_NEUTRAL, SERVO_CLAMP);
  // pid.Initialize(35, 0.1, 3, SERVO_CLAMP);
  pid.Initialize(28, 0.1, 3, SERVO_CLAMP-5);
  
}

void loop() {
  int r = button_read();
  Serial.print("SonarL: ");
  Serial.print(sonarL.GetDistance());
  Serial.print(" SonarR: ");
  Serial.println(sonarR.GetDistance());

  //motor.SetSpeed(255);
  if (r==1 ) {
    
    bool isRight = CheckOrientation();
    if(isRight)
    {
      digitalWrite(LED, HIGH);
    }
    else
    {
      digitalWrite(LED, LOW);
    }
    
   first_round(isRight);
  }
  

}

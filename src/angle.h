#ifndef ANGLE_H_
#define ANGLE_H_
#include "Wire.h"
#include <MPU6050_light.h>


class Angle {
public:
  Angle(): m_mpu(Wire) { }

  void Initialize()
  {
    m_timer = 0;
    Serial.begin(9600);
    Wire.begin();

    byte status = m_mpu.begin();
    Serial.print(F("MPU6050 status: "));
    Serial.println(status);
    
    Serial.println(F("Do not move MPU6050"));
    delay(1000);
    
    m_mpu.calcOffsets();
  }
  void MainLoop()
  {
    m_mpu.update();
  
    if((millis()-m_timer)>10){
	    m_timer = millis();  
    }
  }
  int GetAngle() {
    return m_mpu.getAngleZ();
  }
private:
  MPU6050 m_mpu;
  unsigned long m_timer;
};

#endif
#ifndef ROTATOR_H_
#define ROTATOR_H_
#include <Servo.h>
class Rotator {
  public:
  Rotator(){}
  void Initialize(byte _pin, byte _neutral, byte _clamp)
  {
      m_clamp = _clamp;
      m_pin = _pin;
      m_rot = _neutral;
      m_neutral = _neutral;
      m_servo.attach(_pin);
      SetRotation(0);
  }
  void MainLoop()
  {
    for (byte angle = 0; angle <= 30; angle += 1) { 
      SetRotation(angle);              
      delay(15); 
    }
    for (byte angle = 30; angle >= 0; angle -= 1) { 
      SetRotation(angle);              
      delay(15); 
    }
  }
  void SetRotation(int angle)
  {
    if(angle > 0 && angle > m_clamp)
    {
      angle = m_clamp;
    }
    else if (angle < 0 && angle < -m_clamp)
    {
      angle = m_clamp;
    }

    m_rot = m_neutral+angle;
    m_servo.write(m_rot);
  }
  void GetRotation() {
    return m_rot;
  }
  private:
  Servo m_servo; 
  byte m_pin;
  byte m_neutral;
  byte m_clamp;
  byte m_rot;
};

#endif
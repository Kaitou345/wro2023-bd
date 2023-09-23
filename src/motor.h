#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
  public:
  Motor(){}
  void Initialize(byte _pin1, byte _pin2, byte _enable)
  {
    m_pin1 = _pin1;
    m_pin2 = _pin2;
    m_enable = _enable;
    pinMode(m_pin1, OUTPUT);
    pinMode(m_pin2, OUTPUT);
    pinMode(m_enable, OUTPUT);


  }
  void SetSpeed(int _speed)
  {
    if (_speed >= 0) {
      digitalWrite(m_pin1, 1);
      digitalWrite(m_pin2, 0);
    }
    else {
      _speed *= -1;
      digitalWrite(m_pin1, 0);
      digitalWrite(m_pin2, 1);
    }
    analogWrite(m_enable, _speed);
  }
  private:
  byte m_pin1;
  byte m_pin2;
  byte m_enable;

};

#endif

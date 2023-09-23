#ifndef PID_H_
#define PID_H_
#include <PIDController.h>
#include "Arduino.h"
#include "sonar.h"

class PID {
public:
  PID(Sonar& l, Sonar& r): m_l(l), m_r(r) {}
  void Initialize(float kp, float ki, float kd, byte clamp)
  {
    m_pid.begin();          
    m_pid.setpoint(0);    
    m_pid.tune(kp, ki, kd);
    m_pid.limit(-clamp, clamp);
  }
  int GetOutput() 
  {
    int error = m_l.GetDistance() - m_r.GetDistance();
    return m_pid.compute(error);
  }
  int GetOutputL(int preferedDistance) {
    int error = m_l.GetDistance() - preferedDistance;
    return m_pid.compute(error);
  }
  int GetOutputR(int preferedDistance) {
    int error = m_r.GetDistance() - preferedDistance;
    return m_pid.compute(error);
  }
  
  void SetPoint(int point)
  {
    m_pid.setpoint(point);
  }
  void SetLimit(int limit)
  {
    m_pid.limit(-limit, limit);
  }
private:
  PIDController m_pid;
  Sonar& m_l;
  Sonar& m_r;
  
};


#endif

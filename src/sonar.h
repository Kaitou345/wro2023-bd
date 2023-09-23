#ifndef SONAR_H_
#define SONAR_H_
#include <Arduino.h>

#include <NewPing.h>

class Sonar {
public:
  Sonar(byte _pin, int _distance)
    : m_sonar(_pin, _pin, _distance) {}
  void Initialize() {
    Serial.begin(9600);
  }

  void MainLoop() {
    delay(50);
    Serial.print("Ping: ");
    Serial.print(GetDistance());
    Serial.println("cm");
  }
  int GetDistance() {
    int distance = m_sonar.ping_cm();
    if (!distance) {
      return 300;
    }
    return distance;
  }
private:
  NewPing m_sonar;
};
#endif
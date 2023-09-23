#ifndef LENS_H_
#define LENS_H_
#include "Arduino.h"
#include "HUSKYLENS.h"

class Lens {
public:
  Lens(){}
  void Initialize()
  {
    Serial.begin(9600);
    Wire.begin();
    while (!m_huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
    m_time = millis();
  }
  HUSKYLENSResult GetResult()
  {
    return m_result;
  }
  void MainLoop()
  {
    if (!m_huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!m_huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!m_huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
    else
    {
        while (m_huskylens.available())
        {
          
          if (millis() - m_time > m_delay)
          {
            m_result = m_huskylens.read();
            m_time = millis();
          }
        }
    }
  }

  bool IsVisible(){return m_huskylens.available();}
  byte GetId(){return m_result.ID;}
  int GetWidth(){m_result.width;}
  int GetX() {return m_result.xCenter;}
  int GetY() {return m_result.yCenter;}

  void ResultLog()
  {
    if (m_result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:x=")+m_result.xCenter+F(",y=")+m_result.yCenter+F(",width=")+m_result.width+F(",height=")+m_result.height+F(",ID=")+m_result.ID);
    }
    else if (m_result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:x=")+m_result.xOrigin+F(",y=")+m_result.yOrigin+F(",x=")+m_result.xTarget+F(",y=")+m_result.yTarget+F(",ID=")+m_result.ID);
    }
    else {
        Serial.println("Object unknown!");
    }
  }
private:
  HUSKYLENS m_huskylens;
  HUSKYLENSResult m_result;
  unsigned long m_time;
  byte m_delay = 200;
};
#endif
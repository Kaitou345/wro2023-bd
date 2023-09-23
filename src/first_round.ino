void first_round(bool isRight) {
  
  bool shouldStop = false;
  while (true) {
    
    pid.SetPoint(0);
    pid.SetLimit(SERVO_CLAMP);
    int output;
    if (isRight) {
      output = pid.GetOutputR(COMFORTABLE_DISTANCE);
    } else {
      output = pid.GetOutputL(COMFORTABLE_DISTANCE);
    }
    motor.SetSpeed(130 - (abs(output) * 2.6));
    if (!isRight) {
      output *= RIGHT;
    }
    steering.SetRotation(output);
  }
}

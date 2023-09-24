void first_round(bool isRight) {
  
  
  while (true) {
    turn_check();
    Serial.println(turn_counter);
    lens.MainLoop();

    if(should_stop && millis() - stop_timer > 950) {
      motor.SetSpeed(0);
      steering.SetRotation(0);
      break;
    }

    if(turn_counter >=12 && !should_stop) {
      should_stop = true;
      stop_timer = millis();

    }
    pid.SetPoint(0);
    pid.SetLimit(SERVO_CLAMP);
    int output;
    if (isRight) {
      output = pid.GetOutputR(COMFORTABLE_DISTANCE);
    } else {
      output = pid.GetOutputL(COMFORTABLE_DISTANCE);
    }
    motor.SetSpeed(100 - (abs(output) * 1));
    if (!isRight) {
      output *= RIGHT;
    }
    steering.SetRotation(output);
  }
}

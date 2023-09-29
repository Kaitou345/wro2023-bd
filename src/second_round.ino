void second_round() {
  bool should_stop = false;
  unsigned long stop_timer = millis();
  bool start_stack = false;

  int lastObj = 0;
  bool shouldturn = false;

  unsigned long uturn_timer = millis();
  bool start_turning = false;
  bool has_turned = false;
  motor.SetSpeed(60);
  bool orientationSet = false;
  bool isRight = false;
  while (true) {
    turn_check();

    if (!orientationSet) {
      if (sonarR.GetDistance() > 250) {
        isRight = true;
        orientationSet = true;
      } else if (sonarL.GetDistance() > 250) {
        isRight = false;
        orientationSet = true;
      }
    }
    if (sonarF.GetDistance() < 10 && lens.Get(2,0).height == -1 && lens.Get(3,0).height == -1 ) {
      if (isRight) {
        motor.SetSpeed(-60);
        steering.SetRotation(0);
        delay(100);
        motor.SetSpeed(-60);
        steering.SetRotation(20);
        delay(800);
        motor.SetSpeed(60);
        steering.SetRotation(-20);
        delay(600);
        steering.SetRotation(0);
        delay(200);
      } else {
        motor.SetSpeed(-60);
        steering.SetRotation(0);
        delay(100);
        motor.SetSpeed(-60);
        steering.SetRotation(-20);
        delay(800);
        motor.SetSpeed(60);
        steering.SetRotation(20);
        delay(600);
        steering.SetRotation(0);
        delay(200);
      }
    }
    Serial.println(turn_counter);
    // if (should_stop && millis() - stop_timer > 13000) {
    //   motor.SetSpeed(0);
    //   steering.SetRotation(0);
    //   break;
    // }

    if (turn_counter == 4) {
      start_stack = true;
    } else if (turn_counter == 5) {
      start_stack = false;
    }

    if (lens.Get(2, 0).height > 30) {
      if (start_stack) {
        lastObj = 2;
      }
    } else if (lens.Get(3, 0).height > 30) {
      if (start_stack) {
        lastObj = 3;
      }
    }


    if (lastObj == 2) {

      shouldturn = true;
    }

    if (turn_counter == 8 && shouldturn && !start_turning && !has_turned) {
      uturn_timer = millis();
      start_turning = true;
    }
    if (shouldturn) {
      digitalWrite(LED, HIGH);
    }
    if (start_turning && millis() - uturn_timer > 3000) {

      turn();
    //  turn_counter =+ 1;
      has_turned = true;
      start_turning = false;
      isRight = !isRight;
    }
    if (should_stop && millis() - stop_timer > 4500) {
      motor.SetSpeed(0);
      steering.SetRotation(0);
      break;
    }

    if (turn_counter >= 12 && !should_stop) {
      should_stop = true;
      stop_timer = millis();
    }

    lens.MainLoop();

    // if (!orientationSet) {
    //   if (sonarR.GetDistance() > 250) {
    //     isRight = true;
    //     orientationSet = true;
    //   } else if (sonarL.GetDistance() > 250) {
    //     isRight = false;
    //     orientationSet = true;
    //   }
    // }

    int extraSteer = 0;
    if (lens.IsVisible()) {


      if (lens.Get(2, 0).height > 0) {

        extraSteer = (lens.Get(2, 0).height / 22) * 30;

      } else if (lens.Get(3, 0).height > 0) {
        extraSteer = -(lens.Get(3, 0).height / 22) * 30;
      }
    }


    pid.SetPoint(0);
    pid.SetLimit(SERVO_CLAMP - 10);
    int output = pid.GetOutput();

    output = output + extraSteer;

    motor.SetSpeed(50);

    steering.SetRotation(-output);
  }
}

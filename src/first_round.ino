void first_round() {
  while (1) {
    lens.MainLoop();
    //angle.MainLoop();
    if(lens.IsVisible() && lens.GetWidth()>67 && lens.GetId() == 2){
      steering.SetRotation(20);
      motor.SetSpeed(130);
    }
    else{
      pid.SetPoint(0);
    pid.SetLimit(LIMIT);
    int output = pid.GetOutput();
   motor.SetSpeed(150 - (abs(output)*2));
    steering.SetRotation(-output);
    Serial.println(output);
    //if(abs(angle.GetAngle())>1070)break;
    }
  }
}
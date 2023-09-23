int button_read() {
  int cl = 0;
p:  int t = 0;
  if (digitalRead(SW) == 0) {
    digitalWrite(LED, HIGH);
    while (digitalRead(SW) == 0) {
      delay(1); t++;
    }
    digitalWrite(LED, LOW);
    if (t > 15) {
      t = 0; cl++;
      while (digitalRead(SW) == HIGH) {
        delay(1); t++;
        if (t > 1000) return cl;
      }
      goto p;
    }
  }
  return cl;
}
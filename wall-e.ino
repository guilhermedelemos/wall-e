unsigned int lastLoop = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Wall-E");
  Serial.println("Starting system...");
  setupStatusLed();
  Serial.println("System Started.");
}

void loop() {
  unsigned int now = millis();
  if(now - lastLoop >= 250) {
    lastLoop = now;
    Serial.println("loop()");
    unsigned int state = 0;
    if(digitalRead(LED_BUILTIN) == HIGH) {
      state = LOW;
    } else {
      state = HIGH;
    }
    digitalWrite(LED_BUILTIN, state);
  }
}

void setupStatusLed() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Started Status Led.");
}

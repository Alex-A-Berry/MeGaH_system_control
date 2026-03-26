const int pumpCount = 16;
const int pumpPins[pumpCount] = {16, 17, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const unsigned long timeoutDuration = 3600000; // Timeout duration in milliseconds (If no response from python in an hour, pumps turn on)

unsigned long lastCommandTime = 0;

void setup() {
  Serial.begin(9600);

  // Initialize pump pins
  for (int i = 0; i < pumpCount; i++) {
    pinMode(pumpPins[i], OUTPUT);
    digitalWrite(pumpPins[i], HIGH); // Turn on pumps by default
  }
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    lastCommandTime = millis(); // Update the last command time

    if (command == '0') {
      stopPumps();
    } else if (command == '1') {
      startPumps();
    }
  } else {
    // Check for timeout and turn on pumps if necessary
    unsigned long currentTime = millis();
    if (currentTime - lastCommandTime > timeoutDuration) {
      startPumps();
    }
  }
}

void startPumps() {
  for (int i = 0; i < pumpCount; i++) {
    digitalWrite(pumpPins[i], HIGH);
  }
}

void stopPumps() {
  for (int i = 0; i < pumpCount; i++) {
    digitalWrite(pumpPins[i], LOW);
  }
}

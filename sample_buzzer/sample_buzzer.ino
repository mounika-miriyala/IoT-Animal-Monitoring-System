#define BUZZER_PIN 23

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH);  // OFF initially
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();

    if (data == '1') {
      digitalWrite(BUZZER_PIN, LOW);   // ON
    } 
    else if (data == '0') {
      digitalWrite(BUZZER_PIN, HIGH);  // OFF
    }
  }
}
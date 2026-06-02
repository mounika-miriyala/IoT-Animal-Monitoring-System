#define BUZZER_PIN 23
#define TRIG_PIN 5
#define ECHO_PIN 18

long duration;
float distance;

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH); // OFF

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) return -1; // no signal

  return duration * 0.034 / 2;
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();

    if (data == 'D') {
      float d = getDistance();
      Serial.print("DIST:");
      Serial.println(d);
    }

    if (data == '1') {
      digitalWrite(BUZZER_PIN, LOW);   // ON
    }

    if (data == '0') {
      digitalWrite(BUZZER_PIN, HIGH);  // OFF
    }
  }
}
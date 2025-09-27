// Kitchen Smoke Detector using MQ135 and Arduino Nano

const int MQ135_PIN = A0;    // Analog input pin
const int LED_PIN = 2;       // LED pin for smoke alert
const int BUZZER_PIN = 3;    // Buzzer pin for smoke alert
int threshold = 200;         // Adjust based on your environment

void setup() {
  Serial.begin(9600);
  pinMode(MQ135_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Kitchen Smoke Detector Starting...");
  Serial.println("Warming up sensor, please wait...");
  delay(150000); // 150 sec warm-up for MQ135
  Serial.println("Ready to detect smoke.");
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN); // Read analog value
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Check if smoke is detected
  if(sensorValue > threshold) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Smoke Detected! 🔥");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Air is Clean");
  }

  delay(1000); // 1-second delay for next reading
}

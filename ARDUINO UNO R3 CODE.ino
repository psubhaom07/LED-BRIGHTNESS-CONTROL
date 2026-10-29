const int potPin = A0;   // Potentiometer wiper connected to Analog Pin A0
const int ledPin = 9;    // LED connected to Digital PWM Pin 9

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Initialize serial monitor
}

void loop() {
  int potValue = analogRead(potPin);                  // Read 10-bit ADC (0 - 1023)
  int brightness = map(potValue, 0, 1023, 0, 255);    // Map to 8-bit PWM (0 - 255)
  float dutyCycle = (brightness / 255.0) * 100.0;     // Calculate duty cycle percentage

  analogWrite(ledPin, brightness);                    // Output PWM signal to LED

  // Telemetry output to Serial Monitor
  Serial.print("ADC Input: ");
  Serial.print(potValue);
  Serial.print(" | Mapped PWM: ");
  Serial.print(brightness);
  Serial.print(" | Duty Cycle: ");
  Serial.print(dutyCycle, 1);
  Serial.println("%");

  delay(20); // Stability delay
}

// DFRobot_IIS - Version: Latest 
#include <DFRobot_IIS.h>

/// Pin configuration
const int PWM_PIN = 9; // Choose a digital pin that supports PWM

void setup() {
  // Initialize PWM pin as output
  pinMode(PWM_PIN, OUTPUT);

  // Set PWM frequency
  analogWriteFrequency(PWM_PIN, 1000); // Set PWM frequency to 1kHz
}

void loop() {
  // Read desired fan speed from user input or sensor
  int fanSpeed = 128; // Set initial fan speed (0-255)

  // Map the fan speed value to PWM voltage range (0-5V)
  float pwmVoltage = map(fanSpeed, 0, 255, 0, 5000); // Map duty cycle to voltage (0-5000mV)
  int pwmValue = map(pwmVoltage, 0, 5000, 0, 255); // Map voltage to PWM range (0-255)

  // Control fan speed using PWM
  analogWrite(PWM_PIN, pwmValue);

  // Add a delay or perform other tasks as needed
  delay(1000);
}

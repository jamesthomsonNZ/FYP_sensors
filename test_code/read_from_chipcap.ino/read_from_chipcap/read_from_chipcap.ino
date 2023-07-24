
// Demonstrates use of the Wire library
// Reads data from an I2C/TWI peripheral device
// Refer to the "Wire Peripheral Sender" example for use with this

// This code is modified from code in the public domain.


#include <Wire.h>

int ADDRESS = 0x28;    // address of the ChipCap sensor

void setup() {
  Wire.begin();        // join i2c bus 
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(ADDRESS, 3);    // request 3 bytes from sensor
  // 3 bytes are requseted, the first 2 bytes are humidify readings and 
  // the third byte is the temperature reading

  while (Wire.available()) { // peripheral may send less than requested
    int data = Wire.read(); // receive a byte as character
    
    // need to define the addresses of the register where the readings from the 
    // sensor are stored. Then need to send sensor data through UART to laptop.
    
    // need to convert the 3 bytes of data (first two are RH and third is Temp.)
    // using datasheet calcs.
    
    
    Serial.print(data);         // print the character
  }

  delay(500);
}

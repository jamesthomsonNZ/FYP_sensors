#include <Wire.h>

int ADDRESS_SLAVE = 0x28;

//int humidity = 0;
//int temp = 0;

void setup() {
  Wire.begin();             // Join I2C bus (address is optional for controller device)
  Serial.begin(9600);       // Start serial for output
}

void loop() {

    Wire.requestFrom(ADDRESS_SLAVE, 6);    // Request 6 bytes from slave device

    // Slave may send less than requested
    while(Wire.available()) {
        char t = Wire.read();    // Receive a byte as character
        char h = Wire.read();
        //Serial.print("Temp: %d, RH: %d", t, h);
        Serial.println(t, DEC);         // Print the character
        Serial.println(h, DEC);         // Print the character
    }

    delay(500);
}
#include <Wire.h>

void setup() {
  Wire.begin(); // join I2C bus (address optional for master)
}

char *str = "hello" ;
void loop() {

 
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("1235.68");
  Wire.endTransmission();    // stop transmitting

  delay(1000);
}

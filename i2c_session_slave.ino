#include <Wire.h>  // slave
void print_data(int) {
  while (Wire.available()) {
    byte input_data = Wire.read();
    Serial.println(input_data);
  }
}


void send_h(int) {
  long x = 72356;   
  Wire.write((x >> 16) & 0xFF);
  Wire.write((x >> 8) & 0xFF);   
  Wire.write(x & 0xFF);
  // char str[10]; // to send a string to the master it must be an array of charcters and not a string
  // itoa(x,str,10); // convert any number to an array if characters easily 4
  // Wire.write(str) ;
}
void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);
  Wire.onReceive(print_data); // when master sends data 
  Wire.onRequest(send_h); // when master request data 
}

void loop() {
  // put your main code here, to run repeatedly:
}

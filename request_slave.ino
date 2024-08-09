#include<Wire.h>
void send_hello(int){
  Wire.write("hello ") ;
}
void setup() {
  // put your setup code here, to run once:
  
  Wire.begin(8) ;
  Wire.onRequest(send_hello);
}

void loop() {
  // put your main code here, to run repeatedly:

delay(100);
}

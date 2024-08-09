#include<Wire.h>


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200); 

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8
  char recievedData[32] ;
  
  int i = 0 ;
  while (Wire.available()){
    recievedData[i++] = (char)Wire.read() ;
  }
  recievedData[i] = '\0' ;
  
 
  Serial.println(recievedData);
  delay(1000) ;

  

}

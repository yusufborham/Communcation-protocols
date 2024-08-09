#include<Wire.h>
float distance ;

void getData(int){
  char recievedData[32] ;
  int i = 0 ;
  while (Wire.available()){
    recievedData[i++] = (char)Wire.read() ;
  }
   
  recievedData[i] = '\0' ;
  data = atof(recievedData);
}

void setup() {
  // put your setup code here, to run once:
Wire.begin(8) ; // join the bus with address 8 (slave)
Serial.begin(115200);
Wire.onReceive(getData);
}

void loop() {
  // put your main code here, to run repeatedly:
 

}

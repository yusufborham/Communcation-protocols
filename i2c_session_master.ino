#include <Wire.h> // master
char recievedData[32] ;
int i  ;
long x,x_low,x_high,x_mid ;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

}
// "hello" --> 'h' 'e' 'l' 'l' 'o' '\0'
void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8,3) ; // request from slave with address 8 3 bytes (don't forget to change the number of the bytes )


///////////////////////////////////////////////////////////////////////
//////////recieving data from slave after requesting it //////////////

  while(Wire.available()) // wait until there is data in the buffer 
  {
    x_high = Wire.read();         // read the high byte from the number (3rd byte )
    x = x_high << 16 ;            // shifting it to its place as it is the third byte 
    x_mid = Wire.read();          // read next byte which is the mid byte (2nd byte)
    x = x | (x_mid << 8) ;        // oring it with the hogh byte but shifting it first to its place 
    x_low = Wire.read();          // reading the last byte which is byte number 1 
    x = x | x_low ;               // we dont need shifting it as it is in its place we OR it
    Serial.println(x) ;
  }
////////////////////////////////////////////////////////////////////////////////
/////////////requesting data from the slave and slave sends it as a string/////
 /*  i = 0 ;
  while(Wire.available()){
    recievedData[i]= Wire.read() ;
    i++ ;
  }
  recievedData[i] = '\0' ;
  float strToNum = atof(recievedData) ;
  Serial.println(strToNum + 5.0) ;
  delay(1000) ;
  /////////////////////////////////////////////////////////////////////////////
  */

}

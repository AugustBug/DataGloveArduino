// @author Ahmert
// @date 30.12.2018
// data glove v1

#include<Wire.h>

const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
const int fing0 = A0;
const int fing1 = A1;
const int fing2 = A2;
int fing0Val, fing1Val, fing2Val = 0;
int delaley = 300;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  
  Serial.begin(115200);
}
void loop(){
  fing0Val = analogRead(fing0);
  fing1Val = analogRead(fing1);
  fing2Val = analogRead(fing2);
    
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  
  Serial.print("$");
  Serial.print(AcX);
  Serial.print(".");
  Serial.print(AcY);
  Serial.print(".");
  Serial.print(AcZ);
  Serial.print(".");
  Serial.print(GyX);
  Serial.print(".");
  Serial.print(GyY);
  Serial.print(".");
  Serial.print(GyZ);
  
  Serial.print(".");
  Serial.print(fing0Val);
  Serial.print(".");
  Serial.print(fing1Val);
  Serial.print(".");
  Serial.print(fing2Val);
  Serial.println("#");

  if(Serial.available()) {
    int nv = Serial.parseInt();
    if(nv >= 50 && nv <= 1000) {
      delaley = nv;
    }
  }
  
  delay(delaley);
}

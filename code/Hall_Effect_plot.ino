/*
GaussPlot
27/12/2011  Arduining.com
Showing Gauss measured by the SS495B in the serial monitor.
(Miniature Radiometric Linear Hall Efect Sensor)
Sensor connected to Analog channel 0.
*/
#define XRANGE  50 
int x,gss;
void setup(){
  Serial.begin(9600);
}   
void loop(){
  int aValue =analogRead(0);
  x = map(aValue, 0, 1024, 0, XRANGE);
  gss = map(aValue, 102, 922, -640, 640);
  Serial.print("|"); 
  for (int i=0;i<x;i++){
    if(i==XRANGE/2-1)Serial.print("|");
    else Serial.print("-");
  }
  Serial.print("O");
  for (int i=x+1;i<XRANGE;i++){
    if(i==XRANGE/2-1)Serial.print("|");
    else Serial.print("-");
  }
  Serial.print("|");
  Serial.print(gss);
  Serial.println("Gauss");
  delay(100);
} 

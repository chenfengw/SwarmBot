/*
    Demonstration of Controlling Continous Servo (360 servo)
    this code allows you to control 360 degree servo by a command from Serial Monitor

   Modified by Ahmad Shamshiri for Robojax.com
   on Sunday July 01, 2018 at 11:09 in Ajax, Ontario, Canada
   Watch video instruction of this video:https://youtu.be/b_xvu6wWafA
   Get this code from Robojax.com

  Original code by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.
  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  /**
     Instruction: Type r into serial monitor, servo will turn clockwise
                  Type l into serial monitor, servo will turn counter-clockwise
                  Type < into serial monitor, servo will stop
                  Type any other stuff into serial monitor, servo will be turning what ever value in you in
  */

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("received: ");
    Serial.print (incomingByte);

    //180 in ASCII code is r
    if (incomingByte == 108) {
      Serial.println(" sent 0 Rotaing CW ");
      myservo.write(0); //0 makes servo turn clockwise
    }
    //115 in ASCII code is l
    else if (incomingByte == 114) {
      Serial.println(" sent 180 Rotaing CCW ");
      myservo.write(180); //180 makes servo turn counter-clockwise
    }
    //60 in ASCII code is <
    else if (incomingByte == 60) {
      Serial.println(" sent Stopped ");
      myservo.write(60);
    }
    else {
      Serial.println(" moving Random");
      myservo.write(incomingByte);
    }

  }

}

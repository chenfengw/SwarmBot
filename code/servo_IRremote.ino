#include <IRremote.h>
#include <Servo.h>

//initialize variable for IR receiver
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

//HEX code correspond to each button
#define Forward  0x10EFA05F
#define Left     0x10EF10EF
#define Right    0x10EF807F
#define Stop     0x10EF20DF
#define Backward 0x10EF00FF

//create servo object
Servo servo_1;
Servo servo_2;

void setup()
{
  Serial.begin(9600);
  servo_1.attach(4);
  servo_2.attach(7);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    //forward button is pressed
    if (results.value == Forward)
    {
      servo_1.write(180);
      servo_2.write(0);
      Serial.println("Moving forward");
    }

    //backward button is pressed
    if (results.value == Backward)
    {
      servo_1.write(0);
      servo_2.write(180);
      Serial.println("Moving backward");
    }

    //stop button is pressed
    if (results.value == Stop)
    {
      servo_1.write(90);
      servo_2.write(90);
      Serial.println("Stoping");
    }

    //right turn button is pressed
    if (results.value == Right)
    {
      //this only allows servo to run 250 milisecond
      uint32_t RunTime = 250;
      for (uint32_t tStart = millis();  (millis() - tStart) < RunTime;)
      {
        servo_1.write(100);
        servo_2.write(100);
        Serial.println("Turning Right");
      }
      //stop servos after turning
      servo_1.write(90);
      servo_2.write(90);
    }

    //left turn button is pressed
    if (results.value == Left)
    {
      //this only allows servo to run 250 milisecond
      uint32_t RunTime = 250;
      for (uint32_t tStart = millis();  (millis() - tStart) < RunTime;)
      {
        servo_1.write(80);
        servo_2.write(80);
        Serial.println("Turning Left");
      }
      //stop servos after turning
      servo_1.write(90);
      servo_2.write(90);
    }
    irrecv.resume(); //resume detecing incoming signal
  }
}

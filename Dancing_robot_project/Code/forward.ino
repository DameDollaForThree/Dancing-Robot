#include <Servo.h>
#include "SR04.h"
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

#define TRIG_PIN 2
#define ECHO_PIN 3
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int i;

void setup(){
  Serial.begin(9600);
  myservo1.attach(6);   // LL
  myservo2.attach(9);   // RL
  myservo3.attach(10);    // LU
  myservo4.attach(11);    // RU

} 
void loop(){
    a=sr04.Distance();
    Serial.print(a);
    Serial.println("cm");
    delay(1000);

    if (a < 5) {
        // move backward
      // uplift the left leg
      for (i = 90; i < 120; i++) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
      // rotate the right leg
      for (i = 90; i < 120; i++) {
        myservo3.write(i);
        delay(20);
      }
      // put down the left leg
      for (i = 120; i > 90; i--) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
      // rotate the right leg back
      for (i = 120; i > 90; i--) {
        myservo3.write(i);
        delay(20);
      }


      // move right leg
      for (i = 90; i > 50; i--) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
  
      for (i = 90; i > 60; i--) {
        myservo4.write(i);
        delay(20);
      }
  
      for (i = 50; i < 90; i++) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
  
       for (i = 60; i < 90; i++) {
        myservo4.write(i);
        delay(20);
      }
    }

    else {
       // move forward
      // move left leg
      for (i = 90; i < 130; i++) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
  
      for (i = 90; i > 60; i--) {
        myservo3.write(i);
        delay(20);
      }
  
      for (i = 130; i > 90; i--) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
      
      for (i = 60; i < 90; i++) {
        myservo3.write(i);
        delay(20);
      }
  
      // move right leg
      for (i = 90; i > 50; i--) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
  
      for (i = 90; i < 120; i++) {
        myservo4.write(i);
        delay(20);
      }
  
      for (i = 50; i < 90; i++) {
        myservo2.write(i);
        myservo1.write(i);
        delay(20);
      }
  
       for (i = 120; i > 90; i--) {
        myservo4.write(i);
        delay(20);
      }
    }



}

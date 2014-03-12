/* Michael Lynch - 2014 V1.0
 * Light Switch bot v/ Motion Sensor
 * CSH Major Project
 */
#include <Servo.h>
#include <Wire.h>
 
Servo myservo;  //servo object

int pos = 0; // variable to store servo position
int inputPin = 2;  // input pin for motion sensor
int pirState = LOW; // default state is no motion
int val = 0; // variable for reading the motion sensor status
int tDelay = 1000; // timer value, delays loop for 1s
long countDown = 10; // timer

void setup() 
{
  // put your setup code here, to run once:
  myservo.attach(9);
  myservo.write(0);
  pinMode(inputPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  val = digitalRead(inputPin);
  if (val == HIGH)   // Checks to see if input is HIGH
  {
    if (pirState == LOW) // detected movement
    {
      Serial.println("Motion!");
      countDown = 10;
      pirState = HIGH;
    }
    else
    {
     countDown--;
     Serial.println(countDown);
   }
  }
  else
  {
    if (pirState = LOW)
    {
     pirState = LOW; 
     Serial.println(countDown);
    }
    else
    {
     countDown--; 
     Serial.println(countDown);     
    }
  }
  if (countDown == 0)
  {  
     Serial.println("Turning servo!");
     delay(15);    
     myservo.write(180);              // tell servo to go to position in variable 'pos' 
     delay(15);                       // waits 15ms for the servo to reach the position   
  }
  delay(tDelay);
}

// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

void setup()
{
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(8,OUTPUT);
 
}

void loop()
{
// Send ping, get distance in cm
distance = sonar.ping_cm();

// Send results to Serial Monitor
Serial.print("Distance = ");

if (distance >= 400 || distance <= 2)
{
Serial.println("Out of range");
}
else
{
Serial.print(distance);
Serial.println(" cm");
}
delay(500);
if((distance< 10) && (distance=2)) digitalWrite(13,HIGH); else digitalWrite(13,LOW);//red

if((distance>=10) && (distance<30)) digitalWrite(12,HIGH); else digitalWrite(12,LOW);//yellow
if(distance>30) digitalWrite(11,HIGH); else digitalWrite(11,LOW);//green
}

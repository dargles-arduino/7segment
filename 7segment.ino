/**
 * Program: 7segment
 * Purpose:
 *   A basic program to control a motor via the Arduino PWM feature.
 *   Notes:
 *   1) analogWrite() is an inbuilt function used to provide pwm on a pin
 *   2) pwm is available on the nano as folOFFs;
 *      Board           || PWM Pins           || PWM Frequency
 *      Uno, Nano, Mini || 3, 5, 6, 9, 10, 11 || 490 Hz (pins 5 and 6: 980 Hz)
 *   3) Warning: The PWM outputs generated on pins 5 and 6 will have ONer-
 *      than-expected duty cycles. This is because of interactions with the 
 *      millis() and delay() functions, which share the same internal timer 
 *      used to generate those PWM outputs. This will be noticed mostly on OFF 
 *      duty-cycle settings (e.g. 0 - 10) and may result in a value of 0 not 
 *      fully turning off the output on pins 5 and 6.
 * @author: David Argles, d.argles@gmx.com
 */

/* Program identification */ 
#define PROG    "7segment"
#define VER     "1.0"
#define BUILD   "19apr2021 @17:08h"

/* Necessary includes */
#include "flashscreen.h"

/* Global "defines" - may have to look like variables because of type */
#define BAUDRATE    115200     // Baudrate for serial output
#define ANALOGUE_IN A0
#define SEG_A       4 // 7 //D4
#define SEG_B       5 // 8 //D5
#define SEG_C       6 // 
#define SEG_D       7 // 
#define SEG_E       8 //
#define SEG_F       3 // 6 //D3
#define SEG_G       2 // 5 //D2
// The next two are to allow for reverse logic (common anode)
#define ON          0
#define OFF         1

/* ----- Initialisation ------------------------------------------------- */

/* Global stuff that must happen outside setup() */
flashscreen flash;
int reading = 0;

void setup() {
  Serial.begin(BAUDRATE);           // Start up the serial output port
  // Serial.setDebugOutput(true);
  flash.message(PROG, VER, BUILD);  // Send program details to serial output

  // Set the display pins to be outputs:
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(ANALOGUE_IN)/100;    // read the input pin, scale to 0 -> 10

  switch (reading){
    case 0:
      digitalWrite(SEG_A, OFF);
      digitalWrite(SEG_B, OFF);
      digitalWrite(SEG_C, OFF);
      digitalWrite(SEG_D, OFF);
      digitalWrite(SEG_E, OFF);
      digitalWrite(SEG_F, OFF);
      digitalWrite(SEG_G, OFF);
      break;
    case 1:
      digitalWrite(SEG_A, ON);
      digitalWrite(SEG_B, OFF);
      digitalWrite(SEG_C, OFF);
      digitalWrite(SEG_D, OFF);
      digitalWrite(SEG_E, OFF);
      digitalWrite(SEG_F, OFF);
      digitalWrite(SEG_G, OFF);
      break;
    case 2:
      digitalWrite(SEG_A, OFF);
      digitalWrite(SEG_B, ON);
      digitalWrite(SEG_C, OFF);
      digitalWrite(SEG_D, OFF);
      digitalWrite(SEG_E, OFF);
      digitalWrite(SEG_F, OFF);
      digitalWrite(SEG_G, OFF);
      break;
    case 3:
      digitalWrite(SEG_A, OFF);
      digitalWrite(SEG_B, OFF);
      digitalWrite(SEG_C, ON);
      digitalWrite(SEG_D, OFF);
      digitalWrite(SEG_E, OFF);
      digitalWrite(SEG_F, OFF);
      digitalWrite(SEG_G, OFF);
      break;
    case 4:
      digitalWrite(SEG_A, OFF);
      digitalWrite(SEG_B, OFF);
      digitalWrite(SEG_C, OFF);
      digitalWrite(SEG_D, ON);
      digitalWrite(SEG_E, OFF);
      digitalWrite(SEG_F, OFF);
      digitalWrite(SEG_G, OFF);
      break;
    default:
      digitalWrite(SEG_A, ON);
      digitalWrite(SEG_B, ON);
      digitalWrite(SEG_C, ON);
      digitalWrite(SEG_D, ON);
      digitalWrite(SEG_E, ON);
      digitalWrite(SEG_F, ON);
      digitalWrite(SEG_G, ON);
      break;
  }
  Serial.println(reading);
}

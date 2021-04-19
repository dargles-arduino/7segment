/**
 * Program: 7segment
 * Purpose:
 *   A basic program to output a digit to a 7 segment display. The one I am using
 *   is a common anode, so this means I have to use reverse logic - on is off, etc.
 *   I'm using the 3V3 supply on the Arduino, hence 180R resistors to power the 
 *   individual segments at about 10mA.
 * @author: David Argles, d.argles@gmx.com
 */

/* Program identification */ 
#define PROG    "7segment"
#define VER     "1.0"
#define BUILD   "19apr2021 @23:02h"

/* Necessary includes */
#include "flashscreen.h"
#include "segments.h"

/* Global "defines" - may have to look like variables because of type */
#define BAUDRATE    115200     // Baudrate for serial output
#define ANALOGUE_IN A0

/* ----- Initialisation ------------------------------------------------- */

/* Global stuff that must happen outside setup() */
flashscreen flash;
int reading = 0;
/* seg defines the pin #s for segments a,b,c,d,e,f,g */
int seg[] = {4,5,6,7,8,3,2};

void setup() {
  Serial.begin(BAUDRATE);           // Start up the serial output port
  // Serial.setDebugOutput(true);
  flash.message(PROG, VER, BUILD);  // Send program details to serial output

  // Set the display pins to be outputs:
  for (int i=0;i<7;i++){
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
  // read the input pin, scale to 0 -> 10
  reading = analogRead(ANALOGUE_IN)/100;

  // display the relevant digit on the 7 segment display
  for (int j=0;j<7;j++){
    digitalWrite(seg[j],seg_display[reading][j]);
  }

  /*
  // This bit is for testing
  for (int i=0;i<7;i++){
    Serial.print(seg_display[reading][i]);
  }
  Serial.println();
  delay(1000);
  Serial.println(reading); */
}

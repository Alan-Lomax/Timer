/*
  Timer example code
*/
#include "Timer.h"
const byte myLed = LED_BUILTIN;       // We will use on board LED to idicate what is going on

// Notice in the line below the OnTime or OffTime is not defined (they could have been). Instead I set them separately on lines below.
Timer myTimer1(5000);                // define myTimer1 as a member of the Timer class and set to 10 seconds.
Timer myTimer2(1000);                 // define myTimer2 and set to 1 second


void setup() {
  Serial.begin(9600);                 // for serial / debug console
  Serial.println(__FILE__);           // by default I like to output the file name as a minimum.
  pinMode(LED_BUILTIN, OUTPUT);       // define our builtin LED as an output pin
  myTimer1.start();                   // start the 10 second timer right away
}

// In the loop the update function runs over and over again - it does all the work.

void loop() {
  myTimer1.update();                     // update timing values
  myTimer2.update();                     // update timing values

  if (myTimer1.alarm() == true) {        // If 10 seconds are up
    Serial.println("Timer1 in alarm.");
    digitalWrite (LED_BUILTIN, true);    // Turn on the LED
    myTimer1.stop();                     // stop the 10 second timer
    myTimer2.start();                    // and start the 1 second timer
  }
  if (myTimer2.alarm() == true) {      // If the extra 1 second is up
    Serial.println("  >> Timer2 in alarm.");
    digitalWrite (LED_BUILTIN, false); // Turn off the LED

    myTimer2.stop();                   // stop the 1 second timer (which is just in alarm now)
    myTimer1.start();                  // And restart the 10 second timer
  }
}

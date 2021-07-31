/*
  Timer example code
*/
#include "Timer.h"
const byte myLed = LED_BUILTIN;       // We will use on board LED to idicate what is going on

// Define two members of the Timer class
Timer myTimer1(5000);                 // myTimer1 is set to 5 seconds.
Timer myTimer2(1000);                 // myTimer2 is set to 1 second


void setup() {
  Serial.begin(115200);               // for serial / debug console
  Serial.println(__FILE__);           // by default I like to output the file name as a minimum.
  pinMode(LED_BUILTIN, OUTPUT);       // define our builtin LED as an output pin
  myTimer1.start();                   // start the 10 second timer right away
}

void loop() {
  // The update function does all the hard work - but we dont need to see it happening.
  myTimer1.update();                     // update timing values
  myTimer2.update();                     // update timing values

  // The rest of this sample program is inspecting properties of our timers and starting or stopping them.
  if (myTimer1.alarm() == true) {        // If time is up
    Serial.println("Timer1 in alarm.");
    digitalWrite (LED_BUILTIN, true);    // Turn on the LED
    myTimer1.stop();                     // stop the timer
    myTimer2.start();                    // and start the second timer
  }
  if (myTimer2.alarm() == true) {        // If the extra time is up
    Serial.println("  >> Timer2 in alarm.");
    digitalWrite (LED_BUILTIN, false); // Turn off the LED

    myTimer1.start();                  // Restart the first timer
    myTimer2.stop();                   // and stop the second timer
  }
}

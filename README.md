# Timer

This class defines a timer where the alarm will be set to true after an interval you define has expired.
Once defined the Timer can be started, paused or stopped. All code is written in a non blocking manner. (No delays).

Notes:

The time values can be inspected or changed, the timer can be started, paused or stopped.
Normally in your loop code you will be looking for myTimer.alarm() == true

Timing values are not particularly accurate - but they are very repeatable.
For example in the code below the Timer set to 5000 ms goes into alarm after 8 seconds. (And does it consistantly)
I have not found a good explanation for this but the code seems correct. (I welcome comments if you can spot an issue)
This does ot cause problems for me because absolute accuracy is not a requirement and the values are ajusted until the desired effect is achieved.

### Files: Timer.h, Timer.CPP

### Example: 

    /*
      Timer example code
    */
    #include "Timer.h"
    const byte myLed = LED_BUILTIN;       // We will use on board LED to indicate what is going on

    // Define two members of the Timer class
    Timer myTimer1(5000);                 // myTimer1 is set to 5 seconds.
    Timer myTimer2(1000);                 // myTimer2 is set to 1 second


    void setup() {
      Serial.begin(9600);                 // for serial / debug console
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
        digitalWrite (LED_BUILTIN, false);   // Turn off the LED

        myTimer1.start();                    // Restart the first timer
        myTimer2.stop();                     // and stop the second timer
      }
    }




### Methods
    void update();                      // update things based on elapsed time (call this as often as possible)
    void start();                       // Start the Timer by setting _running to true. (Does not reset _pausetime to zero)
    void stop();                        // Stop the Timer by setting _running to false (And reset _runTime and _pauseTime to zero)
    void pause();                       // Toggle the Timer from _paused = true to _paused=false 
                                        // (When _paused = true accumulate time in _pausetime which is to be deducted from running time.)
    void setalarmTime(unsigned long MyalarmTime);     // Resets the Alarm Timer to a new value(in millis)
    
### Properties:
    bool running();                      // return true / false according to if timer is runnning.
    bool alarm();                        // Returns true if elapsed time - _pausetime has exceeded the alarmTime, false otherwise.
    unsigned long currentValue();        // Returns the current value of the timer (in millis)
    unsigned long pauseTime();           // Returns the current value of the Pause timer (in millis)
    unsigned long alarmTime();           // Returns the current setting of the Alarm Timer (in millis)

 

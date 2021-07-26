# Timer

This class defines a timer where they alarm will be set to true after an interval you define.
Once defined the Timer can be started, paused or stopped. All code is written in a non blocking manner. (No delays).
Key properties can be read to determine their current value enabling other actions to occur only at specific times. 

### Files: Timer.h, Timer.CPP

### Usage:
Include the header file near the top of your code. (After this is done the compiler will know how to handle you using it.)

    #include "Timer.h";

### Instantiation:
    Timer(long MyAlarmTime);            // Default definition specifying the alarm time in milliseconds.
                                        // Timer will be in stopped state, running time will not be accumulate until started.

### Example: 

    Timer myTimer(30000);               // Define a new Timer with a 30 second alarm.

The time values can be inspected or changed, the timer can be started, paused or stopped.
Normally in your loop code you will be looking for myTimer.alarm() == true


### Methods
    void Update();                      // Update things based on elapsed time (call this as often as possible)
    void start();                       // Start the Timer by setting _running to true. (Does not reset _pausetime to zero)
    void stop();                        // Stop the Timer by setting _running to false (And reset _runTime and _pauseTime to zero)
    void pause();                       // Toggle the Timer from _paused = true to _paused=false 
	                                    // (When _paused = true accumulate time in _pausetime which is to be deducted from running time.)
    void SetAlarmTime(long MyAlarmTime);// Resets the Alarm Timer to a new value(in millis)
	
### Properties:
    bool alarm();                       // Returns true if elapsed time - _pausetime has exceeded the AlarmTime, false otherwise.
    long CurrentValue();                // Returns the current value of the timer (in millis)
    long PauseTime();                   // Returns the current value of the Pause timer (in millis)
    long AlarmTime();                   // Returns the current setting of the Alarm Timer (in millis)
    bool running();                     // return true / false according to if timer is runnning.
 
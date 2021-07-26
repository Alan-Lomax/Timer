#ifndef MY_TIMER_H
#define MY_TIMER_H
#include <Arduino.h>
/*
 *****************************************************
 ** MY_TIMER_H Example Usage                        **
 **                                                 **
 ** This class implements timer Functionality       **
 ** whereby you can start, pause, or reset it       **
 ** plus set an alarm value which will upon expiry  **
 ** sets the alarm on.                              **
 ** There is no blocking code so frequent           **
 ** calls to the update method arerequired.         **
 *****************************************************

 Alarm is 'true' if    (elapsed time - pause time) >= alarmTime

*/
class Timer {
  private:
    long _alarmTime;                    // milliseconds before sounding alarm
    long _pauseTime;                    // milliseconds spent in pause
    long _runTime;                      // running time in milliseconds (time that timer has been running after deducting _pauseTime)
    bool _pause;                        // true if we are in pause false if not
    bool _running;                      // true if timer is running, false if not
    bool _alarm;                        // true if timer has expired (In alarm condition), false if not
    unsigned long _previousMillis;      // will store the start time of the timer
    void init();                        // (re) Initialize the timer

  public:
    Timer(long MyAlarmTime);            // Default definition specifyng the alarm time in milliseconds. Timer will be in stopped state, running time will not be accumulate until started.
    void Update();                      // Update things based on elapsed time (call this as often as possible)
    void start();                       // Start the Timer by setting _running to true. (Does not reset _pausetime to zero)
    void stop();                        // Stop the Timer by setting _running to false (And reset _runTime and _pauseTime to zero)
    void pause();                       // Toggle the Timer from _paused = true to _paused=false (When _paused = true accumulate time in _pausetime which is to be deducted from running time.)
    bool alarm();                       // Returns true if elapsed time - _pausetime has exceeded the AlarmTime, false otherwise.
    long CurrentValue();                // Returns the current value of the timer (in millis)
    long PauseTime();                   // Returns the current value of the Pause timer (in millis)
    long AlarmTime();                   // Returns the current setting of the Alarm Timer (in millis)
    void SetAlarmTime(long MyAlarmTime);// Resets the Alarm Timer to a new value(in millis)
    bool running();                     // return true / false according to if timer is runnning.
};
#endif

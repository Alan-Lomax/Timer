ifndef MY_TIMER_H
#define MY_TIMER_H
#include <Arduino.h>
/*
 *****************************************************
 ** MY_TIMER_H Example Usage                        **
 **                                                 **
 ** This class implements timer functionality       **
 ** whereby you can start, pause, or reset the Timer**
 ** When alarm time has elapsed alarm returns true  **
 ** There is no blocking code so frequent           **
 ** calls to the update method arerequired.         **
 *****************************************************

 Alarm is 'true' if    (elapsed time - pause time) >= alarmTime

*/
class Timer {
  private:
    unsigned long _alarmTime;           // milliseconds before sounding alarm
    unsigned long _pauseTime;           // milliseconds spent in pause
    unsigned long _runTime;             // running time in milliseconds (time that timer has been running after deducting _pauseTime)
    unsigned long _previousMillis;      // will store the start time of the timer
    bool _pause;                        // only true if we are paused
    bool _running;                      // only true if timer is running
    bool _alarm;                        // only true if timer has expired (We are in an alarm condition)
    void init();                        // Initialize or reset the timer the timer

  public:
    Timer(unsigned long MyalarmTime);   // Default definition specifyng the alarm time in milliseconds. Timer will be in stopped state, running time will not be accumulate until started.
    void update();                      // update things based on elapsed time (call this as often as possible)
    void start();                       // Start the Timer by setting _running to true and zeroing timing values. If we were paused - unpause us but do not change timing values.
    void stop();                        // Stop the Timer by setting _running to false (And reset _runTime and _pauseTime to zero)
    void pause();                       // Toggle the Timer from _paused = true to _paused=false (When _paused = true accumulate time in _pausetime which is to be deducted from running time.)
    bool alarm();                       // Returns true if elapsed time - _pausetime has exceeded the alarmTime, false otherwise.
    unsigned long currentValue();                // Returns the current value of the timer (in millis)
    unsigned long pauseTime();                   // Returns the current value of the Pause timer (in millis)
    unsigned long alarmTime();                   // Returns the current setting of the Alarm Timer (in millis)
    void setAlarmTime(unsigned long MyalarmTime);// Resets the Alarm Timer to a new value(in millis)
    bool running();                              // return true / false according to if timer is runnning.
};
#endif

#include "Timer.h"

Timer::Timer(unsigned long MyalarmTime) {
  // Save the passed timing value into the equivelent local variables (with underscore)
  _alarmTime = MyalarmTime;
  init();
}

void Timer::init() {
  // Initialize local variables for the new class member
  _runTime = 0;
  _pauseTime = 0;
  _previousMillis = millis();
  _running = false;
  _alarm = false;
  _pause = false;
}

void Timer::update() {
  if (_running) {                        // we only care if timer is running
    // check to see if it's time to change the state of the Alarm

    if (_pause) {                                          // paused
      _pauseTime += (millis() - _previousMillis);          // accumulate time
      _previousMillis = millis();
    }
    else {                                                 // not paused
      _runTime += (millis() - _previousMillis);            // accumulate time
      _previousMillis = millis();
    }

    if (_runTime >= _alarmTime) {                          // update alarm flag (Consider that _alarmTime or _runTime might have changed)
      _alarm = true;
    }
    else {
      _alarm = false;
    }
  }
}

bool Timer::alarm() {
  // return the current Alarm state True or False)
  return _alarm;
}

bool Timer::running() {
  // return true if the current timer is running.
  return _running;
}

void Timer::setAlarmTime( unsigned long MyalarmTime) {
  // update the desired alarm time (without resetting the timer). If we were in alarm next call to update will clear it.
  _alarmTime = MyalarmTime;
}

void Timer::pause() {
  // When the alarm is in pause - time accumulates in the pause timer only and will be deducted from elapsed time.
  _pause = true;                        // true if we are in pause false if not
}

void Timer::start() {
  // Start Timer
  if (!_pause) {                    // If we were not paused then calling start will reset all timing values
    _runTime = 0;
    _pauseTime = 0;
    _previousMillis = millis();     // and capture the current time
  }
  else {                            // If we were paused then don't reset timing values just unpause us
    _pause = false;
  }
  _running = true;                  // set the flag to say Timer is running
}

void Timer::stop() {
  // Reinitialize the time
  init();
}

unsigned long Timer::currentValue() {
  // Returns the current value of the timer (in millis)
  return _runTime ;
}

unsigned long Timer::pauseTime() {
  // Returns the current accumulated pause time (in millis)
  return _pauseTime ;
}

unsigned long Timer::alarmTime() {
  /// Returns the current setting of the Alarm Timer (in millis)
  return _alarmTime ;
}

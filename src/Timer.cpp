#include "Timer.h"

Timer::Timer(long MyAlarmTime) {
  // Save the passed timing value into the equivelent local variables (with underscore)
  _alarmTime = MyAlarmTime;
  init();
  }

void Timer::init() {
	// Initialize local variables for the new class member
  _runTime = 0;
  _pauseTime = 0;
  _previousMillis = 0;
  _running = false;
  _alarm = false;
}

void Timer::Update() {
  if (_running) {                        // we only care if timer is running
    // check to see if it's time to change the state of the Alarm
    unsigned long delta = millis() - _previousMillis;
	
    if (_pause) {
      _pauseTime = _pauseTime + delta;   // an accumulating time
	  _previousMillis = millis();
    }
    else {
      _runTime = _runTime + delta;       // an accumulating time
	  _previousMillis = millis();
    }

    if (_runTime >= _alarmTime) {
      _alarm = true;
      // nothing more to do until something changes.
    }
    else {
      _alarm = false;                                                      // Update alarm flag (maybe _alartmTime has been changed)
    }
  }
  else {
    // Timer is not running so clear any alarm condition that may exist.
	// (keep timer values for inspection up until time is started again)
	_alarm = false; 
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

void Timer::SetAlarmTime(long MyAlarmTime) {
  // update the desired alarm time (without resetting the timer). If we were in alarm next call to update will clear it.
  _alarmTime = MyAlarmTime;
}

void Timer::pause() {
  // When the alarm is in pause - time accumulates in the pause timer to be deducted from elapsed time.
  _pause = true;                        // true if we are in pause false if not
}

void Timer::start() {
  // Start Timer
  _running = true;
  _runTime = 0;
  _pauseTime = 0;
  _previousMillis = millis();
}

void Timer::stop() {
  // Reinitialize the time 
  init();
}

long Timer::CurrentValue() {
  // Returns the current value of the timer (in millis)
  return _runTime ;
}

long Timer::PauseTime() {
  // Returns the current accumulated pause time (in millis)
  return _pauseTime ;
}

long Timer::AlarmTime() {
  /// Returns the current setting of the Alarm Timer (in millis)
  return _alarmTime ;
}

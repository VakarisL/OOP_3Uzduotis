#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

class Timer {
  private:
	using hrClock = std::chrono::high_resolution_clock;
	std::chrono::time_point<hrClock> start; 
  public:
  	Timer() : start{hrClock::now()} {}
  	void reset() {start=hrClock::now();}
  	double elapsed() const {return std::chrono::duration<double> (hrClock::now()-start).count();}
};

#endif
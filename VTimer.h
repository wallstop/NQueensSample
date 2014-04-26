
#pragma once 

#if defined(WIN32) || defined(_WIN32)

    #ifndef VTIMER_LIB
        #define VTIMER_LIB_EXPORT __declspec(dllimport)
    #else
        #define VTIMER_LIB_EXPORT __declspec(dllexport)
    #endif

#else

    #define VTIMER_LIB_EXPORT

#endif

#include <stdint.h>

class VTIMER_LIB_EXPORT VTimer
{
public:

	VTimer();

	~VTimer(){};

	// Resets the timer's reference point to "now"
	void setStartTick();

	// Returns time since baseTime
	double tick();

    double time_ns();

	// Time in microseconds 
	double time_us();

	// Time in milliseconds
	double time_ms();

	// Time in seconds
	double time_s();

	// Time in minutes
	double time_m();

	// Time in hours
	double time_h();

private:
	uint_fast64_t m_baseTime;
	uint_fast64_t m_currentTime;
	uint_fast64_t m_clockFrequency;

};
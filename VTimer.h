
#pragma once 
//#define VTIMER_LIB  // Proper dll

#define VTIMER_LIB

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
	const double tick();

	// Time in microseconds 
	const double time_u();

	// Time in milliseconds
	const double time_ms();

	// Time in seconds
	const double time_s();

	// Time in minutes
	const double time_m();

	// Time in hours
	const double time_h();

private:
	uint_fast64_t m_baseTime;
	uint_fast64_t m_currentTime;
	uint_fast64_t m_clockFrequency;

};
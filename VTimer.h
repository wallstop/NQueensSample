#ifndef VMETRICS_API

#if defined _WIN32 || defined WIN32
#define VMETRICS_API __declspec(dllexport)
#else
#define VMETRICS_API __declspec(dllimport)
#endif
#else
#define VMETRICS_API_EXPORT 
#endif

#include <stdint.h>

class VMETRICS_API VTimer
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
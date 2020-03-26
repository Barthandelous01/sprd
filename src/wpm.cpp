#ifndef WPM_CPP_
#define WPM_CPP_

#define MINUTE 60
#define MILISECOND_CONVERT 1000

#include <chrono>
#include <iostream>

std::chrono::milliseconds time_per_word(int wpm, int chunks)
{
     return std::chrono::milliseconds(60000/(wpm/chunks));
}

#endif /* WPM_CPP_ */

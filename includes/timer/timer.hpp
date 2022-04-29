//
// Created by pro10 on 19.04.2022.
//

#ifndef PROJECTSORTS_TIMER_HPP
#define PROJECTSORTS_TIMER_HPP

#include <chrono>

class Timer
{
private:

	static std::chrono::steady_clock::time_point	start;
	static std::chrono::steady_clock::time_point	end;
public:
	Timer() = delete;

	static void	Start();
	static void	Stop();
	static void Reset();
	static uint64_t GetTimeUs();
	static uint64_t GetTimeMs();
	static double GetTimeSec();
};

#endif //PROJECTSORTS_TIMER_HPP

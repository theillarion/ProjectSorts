//
// Created by pro10 on 19.04.2022.
//
#include "timer/timer.hpp"

std::chrono::steady_clock::time_point	Timer::start;
std::chrono::steady_clock::time_point	Timer::end;

void Timer::Start()
{
	Timer::start = std::chrono::steady_clock::now();
}

void Timer::Stop()
{
	Timer::end = std::chrono::steady_clock::now();
}

uint64_t Timer::GetTimeUs()
{

	return (static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(Timer::end - Timer::start).count()));
}

uint64_t Timer::GetTimeMs()
{
	return (static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(Timer::end - Timer::start).count()));
}

double Timer::GetTimeSec()
{
	return (std::chrono::duration<double>(Timer::end - Timer::start).count());
}

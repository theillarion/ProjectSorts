//
// Created by pro10 on 19.04.2022.
//

#include <ctime>

#include "timer.hpp"

unsigned long long Timer::start_milliseconds = 0;
unsigned long long Timer::end_milliseconds = 0;

void Timer::Start()
{
	Timer::start_milliseconds = clock();
}

void Timer::Stop()
{
	Timer::end_milliseconds = clock();
}

unsigned long long Timer::GetTime()
{
	return (Timer::end_milliseconds - Timer::start_milliseconds);
}

long double Timer::GetTimeSeconds()
{
	return (static_cast<long double>(Timer::end_milliseconds - Timer::start_milliseconds) / 1000);
}

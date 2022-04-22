//
// Created by pro10 on 19.04.2022.
//

#ifndef PROJECTSORTS_TIMER_HPP
#define PROJECTSORTS_TIMER_HPP

class Timer
{
private:
	static unsigned long long	start_milliseconds;
	static unsigned long long	end_milliseconds;

public:
	Timer() = delete;

	static void	Start();
	static void	Stop();
	static unsigned long long GetTime();
	static long double GetTimeSeconds();
};

#endif //PROJECTSORTS_TIMER_HPP

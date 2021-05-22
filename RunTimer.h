#ifndef RUN_TIMER_H
#define RUN_TIMER_H
#include <chrono>

class RunTimer
{
public:
	RunTimer();
	std::chrono::steady_clock::time_point start();
	std::chrono::steady_clock::time_point stop();
	std::chrono::duration<long long, std::ratio<1,1000000000>> runTime();
	void displayRunTime();
private:
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;
	std::chrono::duration<long long, std::ratio<1,1000000000>> elapsed;
};

#endif


inline RunTimer::RunTimer()
{

	begin =  std::chrono::high_resolution_clock::now();
	end =  std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}


inline std::chrono::steady_clock::time_point RunTimer::start()
{
	begin = std::chrono::high_resolution_clock::now();
	return begin;
}


inline std::chrono::steady_clock::time_point RunTimer::stop()
{
	end = std::chrono::high_resolution_clock::now();
	return end;
}


inline std::chrono::duration<long long, std::ratio<1,1000000000>> RunTimer::runTime()
{
	elapsed =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	return elapsed;
}


inline void RunTimer::displayRunTime()
{
	runTime();
	printf("\n\nTime measured: %.9f seconds.\n", elapsed.count() *1e-9);
}

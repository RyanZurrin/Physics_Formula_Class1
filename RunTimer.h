#ifndef RUN_TIMER_H
#define RUN_TIMER_H
#include <chrono>

class RunTimer
{
public:
	RunTimer();
	std::chrono::steady_clock::time_point start();
	std::chrono::steady_clock::time_point stop();
	std::chrono::duration<long long, std::ratio<1,1000000000>> runTimeNS();
	std::chrono::duration<long long, std::ratio<1, 1000000000>> runTimeMS();
	std::chrono::duration<long long, std::ratio<1, 1000000000>> runTimeS();
	std::chrono::duration<long long, std::ratio<1, 1000000000>> runTimeM();
	void displayRunTime(const std::string& timeFormat);
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


inline std::chrono::duration<long long, std::ratio<1,1000000000>> RunTimer::runTimeNS()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

inline std::chrono::duration<long long, std::ratio<1, 1000000000>> RunTimer::runTimeMS()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

}
inline std::chrono::duration<long long, std::ratio<1, 1000000000>> RunTimer::runTimeS()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
}

inline std::chrono::duration<long long, std::ratio<1, 1000000000>> RunTimer::runTimeM()
{
	return std::chrono::duration_cast<std::chrono::minutes>(end - begin);
}


inline void RunTimer::displayRunTime(const std::string& timeFormat = "m")
{

	if (timeFormat == "ns" || timeFormat == "NS")
	{
		elapsed = runTimeNS();
		printf("\n\nTime measured: %.9f ns.\n", static_cast<double>(elapsed.count()));
	}
	else if (timeFormat == "ms" || timeFormat == "MS")
	{
		elapsed = runTimeMS();
		printf("\n\nTime measured: %.9f ms.\n", elapsed.count() * 1e-6);
	}
	else if (timeFormat == "s" || timeFormat == "S")
	{
		elapsed = runTimeS();
		printf("\n\nTime measured: %.9f sec.\n", elapsed.count() * 1e-9);
	}
	else
	{
		elapsed = runTimeS();
		printf("\n\nTime measured: %.12f min.\n", static_cast<double>(elapsed.count()) * 1e-9/60);
	}
}
/* Timer class provides timing and stopwatch features to the engine */
#pragma once
#include <time.h>
#include <windows.h>
namespace Advanced2D {
	class Timer
	{
	private:
		DWORD timer_start;
		DWORD stopwatch_start;
	public:
		Timer(void);
		~Timer(void);
		DWORD getTimer();
		DWORD getStartTimeMillis();
		void sleep(int ms);
		void reset();
		bool stopwatch(int ms);
	};
};
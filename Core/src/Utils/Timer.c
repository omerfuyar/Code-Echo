#include "Utils/Timer.h"

void TimePoint_Update(TimePoint *timePoint)
{
}

time_t TimePoint_ToMilliseconds(TimePoint *timePoint)
{
}

Timer TimerStack_Create(const char *label)
{
}

Timer *TimerHeap_Create(const char *label)
{
}

void TimerHeap_Destroy(Timer *timer)
{
}

void Timer_Start(Timer *timer)
{
}

void Timer_Stop(Timer *timer)
{
}

void Timer_Reset(Timer *timer)
{
}

TimePoint Timer_GetElapsedTime(Timer *timer)
{
}

void Timer_PrintElapsedTime(Timer *timer)
{
}

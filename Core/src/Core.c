#include "Core.h"

#include "Utils.h"
#include "Modules.h"

//  20 Milliseconds, 50 loops per second by default
time_t TARGET_SLEEP_MICROSECONDS = 20000L;

void Core_Run(Core_Start start, Core_StartLate lateStart, Core_Update update, Core_UpdateLate lateUpdate)
{
    Monitor_Initialize();

    start();

    lateStart();

    time_t sleepMicroseconds;

    Timer loopTimer = TimerStack_Create("Core Loop Timer");

    while (true)
    {
        Timer_Start(&loopTimer);

        update();

        lateUpdate();

        Timer_Stop(&loopTimer);

        sleepMicroseconds = TARGET_SLEEP_MICROSECONDS - ((loopTimer.endTime.seconds - loopTimer.startTime.seconds) * 1000000L + (loopTimer.endTime.nanoseconds - loopTimer.startTime.nanoseconds) / 1000);

        if (sleepMicroseconds > 0)
        {
            Core_SleepMicroseconds(sleepMicroseconds);
        }
    }
}

void Core_Stop(int exitCode)
{
    DebugInfo("Core is stopping with exit code %d", exitCode);

    while (true)
    {
    }
}

void Core_SetTargetLoopPerSecond(time_t tlps)
{
    TARGET_SLEEP_MICROSECONDS = (1.0 / (tlps == 0 ? 1 : tlps)) * 1000000.0;
}

void Core_SleepMicroseconds(time_t microseconds)
{
    delayMicroseconds(microseconds);
}

void Core_DebugLog(const char *header, const char *format, ...)
{
    TimePoint timer;
    char buffer[256];
    TimePoint_Update(&timer);
    va_list args;
    va_start(args, format);
    snprintf(buffer, sizeof(buffer), "[%02d:%02d:%02d.%03d] : [%s] : ",
             (int)((timer.seconds / 60) % 60), (int)(timer.seconds % 60), (int)(timer.nanoseconds / 1000000),
             header);
    vsnprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), format, args);
    strcat(buffer, "\n");
    va_end(args);
}
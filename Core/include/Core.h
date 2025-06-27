#pragma once

#if defined(ESP32)
#define PLATFORM_ESP32 1
#elif defined(ARDUINO)
#define PLATFORM_ARDUINO 1
#else
#error "Unsupported microcontroller platform."
#endif

#include <Arduino.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#pragma region Constants and typedefs

typedef uint32_t time_t;

// The value of Pi
#define PI 3.14159265

// The value of Euler's number
#define E 2.71828183

// The square root of 2_
#define SQRT2 1.41421356

// The square root of 3
#define SQRT3 1.73205081

// The square root of 5
#define SQRT5 2.23606798

// The Earth's gravity in m/s^2
#define GRAVITY 9.80665

// The Universal gravitational constant in m^3 kg^-1 s^-2
#define G 6.67430e-11

// The speed of light in m/s
#define C 299792458.0

#pragma endregion

#pragma region Core

typedef void (*Core_Start)();
typedef void (*Core_StartLate)();
typedef void (*Core_Update)();
typedef void (*Core_UpdateLate)();

/// @brief The function for initializing and running the core utility. Like a game engine, Core takes function pointers and calls them in it's loop.
/// @param start Called for once before every other function.
/// @param lateStart Called for once after start and before the loop.
/// @param update Called periodically in the loop first.
/// @param lateUpdate Called periodically in the loop after update.
void Core_Run(Core_Start start, Core_StartLate lateStart, Core_Update update, Core_UpdateLate lateUpdate);

/// @brief Stops the loop inside the 'Core_Run' function, closes necessary utilities and exits the program.
/// @param exitCode The code to pass to _exit() function.
void Core_Stop(int exitCode);

/// @brief Sets the target loop per second value for application. Application sleeps for the remaining time after logic. Default is 50.
/// @param tlps Target loop per second to set to.
void Core_SetTargetLoopPerSecond(time_t tlps);

/// @brief Sleeps for a specified number of microseconds.
/// @param microseconds The number of microseconds to sleep for.
void Core_SleepMicroseconds(time_t microseconds);

/// @brief Prints formatted output to the console.
/// @param format The format string.
/// @param ... The values to format.
void Core_DebugLog(const char *header, const char *format, ...);

#pragma endregion

#pragma region Debug

#define DEBUG_INFO_ENABLED true
#define DEBUG_WARNING_ENABLED true
#define DEBUG_ERROR_ENABLED true
#define DEBUG_ASSERT_ENABLED true

#define DEBUG_TERMINATE_ON_ERROR false
#define DEBUG_TERMINATE_ON_ASSERT true

#if DEBUG_INFO_ENABLED == false
#define DebugInfo(format, ...)
#else
#define DebugInfo(format, ...)                        \
    do                                                \
    {                                                 \
        Core_DebugLog("INFO", format, ##__VA_ARGS__); \
    } while (false)
#endif

#if DEBUG_WARNING_ENABLED == false
#define DebugWarning(format, ...)
#else
#define DebugWarning(format, ...)                        \
    do                                                   \
    {                                                    \
        Core_DebugLog("WARNING", format, ##__VA_ARGS__); \
    } while (false)
#endif

#if DEBUG_ERROR_ENABLED == false
#define DebugError(format, ...)
#else
#define DebugError(format, ...)                        \
    do                                                 \
    {                                                  \
        Core_DebugLog("ERROR", format, ##__VA_ARGS__); \
        if (DEBUG_TERMINATE_ON_ERROR != false)         \
            Core_Stop(EXIT_FAILURE);                   \
    } while (false)
#endif

#if DEBUG_ASSERT_ENABLED == false
#define DebugAssert(condition, format, ...)
#else
#define DebugAssert(condition, format, ...)                            \
    do                                                                 \
    {                                                                  \
        if (!(condition))                                              \
        {                                                              \
            Core_DebugLog("ASSERTION FAILURE", format, ##__VA_ARGS__); \
            if (DEBUG_TERMINATE_ON_ASSERT != false)                    \
                Core_Stop(EXIT_FAILURE);                               \
        }                                                              \
    } while (false)
#endif

#pragma endregion

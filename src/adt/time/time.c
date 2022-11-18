#include <stdio.h>
#include "time.h"
#include "../boolean/boolean.h"
// Constructor
void createTime(Time *time, int day, int hour, int minute)
{
    (*time).day = day;
    (*time).hour = hour;
    (*time).minute = minute;
}

// Display in digital
void displayTime(Time time)
{
    // Display hour
    if (time.day < 10)
    {
        printf("0%d", time.day);
    }
    else
    {
        printf("%d", time.day);
    }
    printf(":");
    if (time.hour < 10)
    {
        printf("0%d", time.hour);
    }
    else
    {
        printf("%d", time.hour);
    }
    printf(":");
    if (time.minute < 10)
    {
        printf("0%d", time.minute);
    }
    else
    {
        printf("%d", time.minute);
    }
}

// Display in x hari y jam z menit
void printTime(Time time)
{
    if (time.day > 0)
    {
        printf("%d hari", time.day);
        if (time.hour > 0 || time.minute > 0)
        {
            printf(" ");
        }
    }
    if (time.hour > 0)
    {
        printf("%d jam", time.hour);
        if (time.minute > 0)
        {
            printf(" ");
        }
    }
    if (time.minute > 0)
    {
        printf("%d menit", time.minute);
    }
}

// Convert Time to minute
int timeToMinute(Time time)
{
    int minute = 0;
    minute += (1440 * time.day);
    minute += (60 * time.hour);
    minute += time.minute;
    return minute;
}

// Convert seconds to time
Time minuteToTime(int minutes)
{
    Time newTime;
    int day = (minutes / 60) / 24;
    int hour = (minutes / 60) % 24;
    int minute = minutes % 60;

    createTime(&newTime, day, hour, minute);
    return newTime;
}
#include <stdio.h>

#include "time.h"

// Constructor
void createTime(Time *time,int day, int hour, int minute)
{
    (*time).day = day;
    (*time).hour = hour;
    (*time).minute = minute;
}

// Display
void displayTime(Time time)
{
    // Display hour
    
    if (time.hour < 10){
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

// Convert Time to minute
int timeToMinute(Time time)
{
    int minute = 0;
    minute += (24*60* time.day);
    minute += (60 * time.hour);
    minute += time.minute;
    return minute;
}

// Convert seconds to time
Time minuteToTime(int minutes)
{
    Time newTime;
    int day = (minutes /60)/24;
    int hour = (minutes / 60) % 24;
    int minute = minutes % 60;

    createTime(&newTime, day, hour, minute);
    return newTime;
}
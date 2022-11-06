#ifndef TIME_H
#define TIME_H

// Declaration
typedef struct
{
   int hour;
   int minute;
} Time;

// Constructor
void createTime(Time *time, int hour, int minute);

// Display
void displayTime(Time time);

// Convert Time to minute
int timeToMinute(Time time);

// Convert seconds to Time
Time secondToTime(int seconds);

#endif
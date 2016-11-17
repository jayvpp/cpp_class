//File Name: Time.cpp
//Practicing with classes.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

void Time::SetTime(int h, int m)
{
	hour = h;
	minute = m;
}

void Time::SetHour(int h)
{
	hour = h;
}

void Time::SetMinute(int m)
{
	minute = m;
}

int Time::GetHour()
{
	return hour;
}

int Time::GetMinute()
{
	return minute;
}

void Time::PrintTime()
{

	cout << setfill('0');
	if (hour == 0)
		cout << setw(2) << "12:" << setw(2) << minute;
	else if (hour <= 12)
		cout << setw(2) << hour << ":" << setw(2) << minute;
	else if (hour<24)
		cout << setw(2) << hour - 12 << ":" << setw(2) << minute;
}

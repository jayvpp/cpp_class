//File Name: Time.cpp
//Practicing with classes.
#include "stdafx.h"
#include "Time.h"
#include <iostream>
#include <iomanip>

#include <sstream> 

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

int Time::GetHour() const
{
	return hour;
}

int Time::GetMinute() const
{
	return minute;
}

string Time::to_standard_time() 
{
	stringstream s;
	int hr = (hour > 12) ? hour - 12 : hour;
	s << std::setw(2) << std::setfill('0') << ::to_string(hr) << ":" << std::setw(2) << std::setfill('0') << std::to_string(minute);
	return s.str();
}
string Time::to_night_or_day() 
{
	return (hour >= 12) ? "PM" : "AM";
}

void Time::PrintTime()
{
	cout << to_standard_time() + to_night_or_day() << endl;
}

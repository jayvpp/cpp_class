//File Name: Time.h
//Practicing with classes.
#pragma once
#include <iomanip>
#include <string>
#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hour, minute;

public:
	Time()
	{
		hour = 0;
		minute = 01;
	}

	Time(int h, int m)
	{
		hour = h;
		minute = m;
	}

	void SetTime(int, int);
	void SetHour(int);
	void SetMinute(int);

	int GetHour() const;
	int GetMinute() const;
	std::string to_standard_time() ;
	std::string to_night_or_day() ;
	virtual void PrintTime();
 
	

};
#endif

//File Name: Time.h
//Practicing with classes.
#pragma once

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

	int GetHour();
	int GetMinute();
	void PrintTime();
};
#endif

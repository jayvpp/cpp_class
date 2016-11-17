#include "stdafx.h"
#include <iostream>
#include "DetailedTime.h"

using namespace std;

	DetailedTime::DetailedTime()
	{
		seconds = 0;
	}

	DetailedTime::DetailedTime(int hr, int min, int secs) :Time(hr, min)
	{
		seconds = secs;
	}

	void DetailedTime::SetSecond(int sec)
	{
		seconds = sec;
	}

	int DetailedTime::GetSecond()
	{
		return seconds;
	}

	void DetailedTime::PrintTime()
	{
		Time::PrintTime();

		cout << ":" << seconds;

		if (Time::GetHour() < 12)
			cout << "AM" << endl;

		else
			cout << "PM" << endl;
	}

	int SetTime(int hr, int min);

	void PrintTime();

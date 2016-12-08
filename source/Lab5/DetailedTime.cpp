#include "stdafx.h"
#include <iostream>
#include "DetailedTime.h"

using namespace std;

	DetailedTime::DetailedTime()
	{
		seconds = 0;
	}

	DetailedTime::DetailedTime(int hr, int min, int secs) : Time(hr, min)
	{
		seconds = secs;
	}

	void DetailedTime::SetSecond(int sec)
	{
		seconds = sec;
	}

	void DetailedTime::SetTime(int hr, int min, int secs)
	{
		Time::SetTime(hr, min);
		seconds = secs;
	}

	int DetailedTime::GetSecond() const
	{
		return seconds;
	}

	void DetailedTime::PrintTime()
	{
		std::cout << to_standard_time() << ":" << seconds << to_night_or_day() << endl;
	}


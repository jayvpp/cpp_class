#pragma once

#ifndef DETAILEDTIME_H
#define DETAILEDTIME_H

#include "Time.h"


class DetailedTime : public Time
{
private:
	int seconds;

public:
	DetailedTime();
	DetailedTime(int hr, int min, int secs);
  
	void SetSecond(int seconds);
	int SetTime(int hr, int min);
  
	int GetSecond()const;
	void PrintTime();
};
#endif

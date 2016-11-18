#include "stdafx.h"
#include "DetailedTime.h"
#include <iostream>

using namespace std;

int main()
{
	Time time;
	time.SetHour(17);
	time.SetMinute(45);

    DetailedTime time2;
	time2.SetHour(16);
	time2.SetMinute(45);
	time2.SetSecond(30);

	cout << "The time here is: ";
	time.PrintTime();
	cout << "Hour: " << time.GetHour() - 12 << " Minutes: " << time.GetMinute() << endl;
	cout << endl;

	cout << "The time in Peru is: ";
	time2.PrintTime();
	cout << "Hour: " << time2.GetHour() - 12 << " Minutes: " << time2.GetMinute() << " Seconds: " << time2.GetSecond() << endl;

	system("pause");
}
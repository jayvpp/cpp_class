#include "stdafx.h"
#include "DetailedTime.h"
#include <iostream>

using namespace std;

int main()
{
	Time time;
	time.SetHour(17);
	time.SetMinute(45);


    DetailedTime time2(22, 45, 30);

	cout << "The time here is: ";



	time.PrintTime();

	cout << endl;
	cout << "The time in london is: ";

	time2.PrintTime();


	return 0;
}
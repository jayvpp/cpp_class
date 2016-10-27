// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "Time.h"
#include <iostream>
#include <string> 
#include <numeric>
using namespace std;
string time::to_standard_time() const
{
	std::stringstream s;
	int hr = (h > 12) ? h - 12 : h;
	string period = (h >= 12) ? "PM" : "AM";

	s << std::setw(2) << std::setfill('0') << ::to_string(hr) << ":" << std::setw(2) << std::setfill('0') << std::to_string(m) << period;
	return s.str();
}
void time::set_hours(int hours)
{
	string error = "Invalid parameter, hours should be greater than 0 and smaller than 23.";
	if (hours < 0 || hours > 23) { cout << error << endl; throw runtime_error(error); }
	h = hours;
}

void time::set_minutes(int minutes)
{
	string error = "Invalid parameter, minutes should be greater than 0 and smaller than 60.";
	if (minutes < 0 || minutes > 60) { cout << error << endl; throw runtime_error(error); }
	m = minutes;
}

string time::print_time() const
{
	string tt = to_standard_time();
	cout << tt << endl;
	return tt;
}

 




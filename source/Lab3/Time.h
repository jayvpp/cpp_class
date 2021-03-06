#pragma once
#include <iostream>
class time
{
private:
	int h, m;
	std::string to_standard_time()const;
public:
	time() { h = 12; m = 1; }
	time(int h, int m) 
	{
		set_hours(h);
		set_minutes(m);
	}
	~time() {}

	int get_hours() const { return h; }
	int get_minuts() const { return m; }
	void set_hours(int hour);
	void set_minutes(int minutes);
	void set_time(int hour, int minutes) { set_hours(hour); set_minutes(minutes); }

	std::string print_time()const ;
};


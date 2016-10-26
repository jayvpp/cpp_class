#include "Time.h"
#include <iostream>
#include <cassert>
int main()
{
	time t0(11, 59);
	time t1(12, 00);
	time t2(22, 51);
	time t3(12, 05);
	time t4(1, 13);
	time t5(13, 20);
	time t6(17, 20);
	time t7(4, 5);

	assert(t0.print_time() == "11:59AM");
	assert(t1.print_time() == "12:0PM");
	assert(t2.print_time() == "10:51PM");
	assert(t3.print_time() == "12:5PM");
	assert(t4.print_time() == "1:13AM");
	assert(t5.print_time() == "1:20PM");
	assert(t6.print_time() == "5:20PM");
	assert(t7.print_time() == "4:5AM");

	return 1;
}
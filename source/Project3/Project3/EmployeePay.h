// EmployeePay Class which is derived from Employee.h

#include "Employee.h"
#include <iostream>

using namespace std;

#ifndef EMPLOYEEPAY_H
#define EMPLOYEEPAY_H

class EmployeePay : public Employee
{
protected:
	int annualPay;
	float weeklyPay;

public:
	EmployeePay(string nm, string eId, string hD, string ssn, int ap, float wp) : Employee(nm, eId, hD, ssn)
	{
		annualPay = ap;
		weeklyPay = wp;
	}

	//Mutators
	bool SetAnnualPay(int);
	void SetWeeklyPay();

	//Accessors
	int GetAnnualPay();
	float GetWeeklyPay();

	//other
	void PrintEmployee();
};
#endif

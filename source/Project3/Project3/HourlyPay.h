// derived from employeePay.h
#pragma once

#include "EmployeePay.h"
#include<iostream>

using namespace std;

#ifndef HOURLYPAY_H
#define HOURLYPAY_H

class HourlyPay : public EmployeePay
{
private:
	float hourlyRate;
	float overtimeRate;
	float worked;

public:
	HourlyPay(string nm, string eId, string hD, string ssn, int ap, float wp, float hR, float otR, float wrkd) : EmployeePay(nm, eId, hD, ssn, ap, wp)
	{
		hourlyRate = hR;
		overtimeRate = otR;
		worked = wrkd;
	}
	HourlyPay(){}
	~HourlyPay() {}
	//Mutators
	void SetHourlyRate();
	void SetOvertimeRate();
	bool SetWorked(float);


	//Accessors
	float GetHourlyRate()const;
	float GetOvertimeRate()const;
	float GetWorked()const;

	// Display Function
	void PrintEmployee();
};
#endif

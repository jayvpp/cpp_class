#include "stdafx.h"
#include "HourlyPay.h"
#include<iostream>

using namespace std;

// Mutators
// Set Hours Worked for the week
bool HourlyPay::SetWorked(float workd)
{
	bool valid = true;

	if (workd > 60 || workd < 0)
	{
		valid = false;
		cout << "Invalid input." << endl << endl;
	}

	worked = workd;
	return valid;
}

// Set hourly rate
void HourlyPay::SetHourlyRate()
{
	float hR = 0.0;

	hR = GetWeeklyPay() / 40;

	hourlyRate = hR;
}

// Set Overtime Rate
void HourlyPay::SetOvertimeRate()
{
	float otR = 0.0;

	otR = hourlyRate * 1.5;

	overtimeRate = otR;
}

// Accessors
float HourlyPay::GetHourlyRate()const
{
	return hourlyRate;
}

float HourlyPay::GetOvertimeRate()const
{
	return overtimeRate;
}

float HourlyPay::GetWorked()const
{
	return worked;
}

// Display Function
void HourlyPay::PrintEmployee()
{
	cout << "\t\t EMPLOYEE INFORMATION\n\n";
	cout << "Name:  "<< name << endl;
	cout << "Social:  "<< social << endl;
	cout << "Employee ID:  "<< employeeId << endl;
	cout << "Hire Date:  " << hireDate << endl;
	cout << "Annual Pay: $" << annualPay << endl;
	cout << "Weekly Rate: $" << weeklyPay << endl;
	cout << "Hourly Rate: $" << hourlyRate << endl;
	cout << "Overtime Rate: $" << overtimeRate << endl;
	cout << "Hours Worked: " << worked << endl;

	if (worked < 40)
	{
		cout << "Weekly Pay: $" << worked*hourlyRate << endl;
		cout << "Total Pay: $" << worked*hourlyRate << endl;
	}
	else if(worked > 40)
	{
		cout << "Overtime Hours: " << (worked-40) << endl;
		cout << "Weekly Pay: $" << hourlyRate*40 << endl;
		cout << "Overtime Pay: $" << (worked-40)*overtimeRate << endl;
		cout << "Total Pay: $" << (hourlyRate*40)+((worked-40)*overtimeRate) << endl;
	}
}

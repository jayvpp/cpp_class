#include "stdafx.h"
#include"EmployeePay.h"
#include<iomanip>
#include<cctype>

using namespace std;

//Mutators
bool EmployeePay::SetAnnualPay(int ap)
{
	bool valid = true;

	if (ap<0)
	{
		valid = false;
		cout << "Invalid input." << endl << endl;
	}

	annualPay = ap;
	return valid;
}
void EmployeePay::SetWeeklyPay()
{
	int wp = 0;

	wp = annualPay / 52;

	weeklyPay = wp;
}

//Accessors
int EmployeePay::GetAnnualPay()const
{
	return annualPay;
}
float EmployeePay::GetWeeklyPay()const
{
	return weeklyPay;
}

void EmployeePay::PrintEmployee()
{
	cout<<"\t\t EMPLOYEE INFORMATION\n\n";
	cout<<"Name:  "<< name << endl;
	cout<<"Social:  "<< social << endl;
	cout<<"Employee ID:  "<< employeeId << endl;
	cout<<"Hire Date:  "<< hireDate << endl;
	cout<<"Annual Pay: $"<< annualPay << endl;
	cout<<"Weekly Pay: $"<< weeklyPay << endl;
}

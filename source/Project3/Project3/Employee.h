// Employee Base Class Header File
#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
protected:
	string name;
	string employeeId;
	string hireDate;
	string social;

public:
	Employee(string nm, string eId , string hD, string ssn)
	{
		name = nm;
		employeeId = eId;
		hireDate = hD;
		social = ssn;
	}
	Employee(){}
	~Employee(){}

	// Mutators
	bool SetName(string);
	bool SetEmployeeId(string);
	bool SetHireDate(string);
	bool SetSocial(string);

	// Accessors
	string GetName() const;
	string GetEmployeeId() const;
	string GetHireDate() const;
	string GetSocial() const;

	// other
	//void PrintEmployee();

	virtual void PrintEmployee() =0;
};
#endif

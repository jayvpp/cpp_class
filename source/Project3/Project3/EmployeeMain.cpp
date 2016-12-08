// Employeemain.cpp
// Program to output data stored in Employee.h Base class and its derived classes EmployeePay and HourlyPay
//
// Created by
// Yep, Eben 	      : yepea4@bconline.broward.edu
// Vega, Jason	      : vegaj32@mail.broward.edu
// Dominguez, Michael : domim35@bconline.broward.edu
//
// COP2335C
// Professor Lollett
// Project 3 

#include "stdafx.h"
#include"HourlyPay.h"
#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

//prototypes

//type: void
//parameters: Hourlypay(employees) int(SIZE)
//purpose: to fill employee array with data
void GetData(HourlyPay[],int);

//type: void
//parameters: Hourlypay(employees) int(SIZE)
//purpose: to print a paycheck for selected employee
void PrintCheck(HourlyPay[], int);

int main()
{
	//variables
	//array size
	int SIZE = 100;
	HourlyPay employees[100];
	
	cout << "\t\t\tEMPLOYEE PAYMENT SYSTEM." << endl << endl;
	cout << "Start." << endl << endl;

	// Get number of employees
	do
	{
		cout << "How many employees: ";
		cin >> SIZE;
		if (SIZE <= 0)
		{
			cout << "Invalid choice.\n" << endl << endl;
		}
		cout << endl;
		cin.ignore();
	} while (SIZE <= 0);

	// instance array of derived class HourlyPay
	

	// used to populate array of employees
	GetData(employees, SIZE);

	cout << "All employees entered.\n" << endl;

	// used to output checks for employees
	PrintCheck(employees, SIZE);

	cout << "End Program." << endl << endl;;

	system("pause");
}

void PrintCheck(HourlyPay employees[], int SIZE)
{
	// variables
	//employee select
	int n = 0;
	// Menu Select
	char choice = 'Z';
	// store total pay
	float pay = 0.0;

	do {
		// prompt for employee to pull check for
		do
		{
			cout << "Pull information on employee # : ";
			cin >> n;
			cout << endl;

			if (n <= 0 || n>SIZE)
			{
				cout << "Invalid choice.\n" << endl << endl;
			}

		} while (n <= 0 || n>SIZE);

		// call to calculate pay rates
		employees[n - 1].SetWeeklyPay();
		employees[n - 1].SetHourlyRate();
		employees[n - 1].SetOvertimeRate();

		// calculate pay
		if (employees[n - 1].GetWorked() <= 40)// regular hours
		{
			pay = employees[n - 1].GetHourlyRate()*employees[n - 1].GetWorked();

		}
		else if (employees[n - 1].GetWorked()>40)// w/ overtime
		{
			pay = (employees[n - 1].GetHourlyRate() * 40) + ((employees[n - 1].GetWorked() - 40)*employees[n - 1].GetOvertimeRate());
		}

		//check output to screen
		cout << endl;
		cout << "╔═══════════════════════════════════════════════════════════════╗" << endl;
		cout << "║                                                               ║" << endl;
		cout << "║ EmployeeID-" << left << setw(34) << employees[n - 1].GetEmployeeId() << " SSN-" << employees[n - 1].GetSocial() << " ║" << endl;
		cout << "║                                                               ║" << endl;
		cout << "║                                                               ║" << endl;
		cout << "║                                           Amount: " << setw(11) << fixed << setprecision(2) << pay << setw(17) << " ║" << endl;
		cout << "║                                                               ║" << endl;
		cout << "║   Pay to the                                                  ║" << endl;
		cout << "║    order of: " << left << setw(48) << employees[n - 1].GetName() << " ║" << endl;
		cout << "║                                                               ║" << endl;
		cout << "║                                                               ║" << endl;
		cout << "║ Loyal employee since:" << left << setw(40) << employees[n - 1].GetHireDate() << " ║" << endl;
		cout << "╚═══════════════════════════════════════════════════════════════╝" << endl;

		//old call to get all info stored on employee
		//employees.PrintEmployee();
		cout << endl;

		//check to see if other paycheck need to be printed
		do
		{
			cout << "Output another employee? (Y or N):";
			cin >> choice;
			cout << endl;
			choice = (toupper(choice));
			cin.ignore();

			if (choice != 'N' && choice != 'Y')
			{
				cout << "Invalid choice.\n" << endl << endl;
			}

		} while (choice != 'N' && choice != 'Y');

	} while (choice != 'N');
}

void GetData(HourlyPay employees[], int SIZE)
{
	//variables
	// holds employee identification information
	string nm = "John Smith";
	string ssn = "NNN-NN-NNNN";
	string eId = "NNN-A";
	string hD = "mm/dd/yyyy";
	// holds pay and hours worked
	int ap = 0;
	float wrkd = 0.0;
	//counter used to make sure all spots in employee array are filled
	int i = 0;

	// get all info needed for current number of employees declared 
	while (i<SIZE)
	{
		cout << "Now entering information for employee #" << i + 1 << endl << endl;

		// get name
		do
		{
			cout << "Enter Employees Name: ";

			if (cin.fail())
			{
				cin.ignore();
			}
			getline(cin, nm);
		} while (!employees[i].SetName(nm));

		// get social security number
		do
		{
			cout << "Enter Social Security Number for " << employees[i].GetName() << " (ex. 000-00-0000): ";
			cin >> ssn;
		} while (!employees[i].SetSocial(ssn));

		// get employee id
		do
		{
			cout << "Enter Employee ID for " << employees[i].GetName() << " (ex. 000-A): ";
			cin >> eId;
		} while (!employees[i].SetEmployeeId(eId));

		//get hire date
		do
		{
			cout << "Enter Hire Date for " << employees[i].GetName() << " (ex. mm/dd/yyyy) : ";
			cin >> hD;
		} while (!employees[i].SetHireDate(hD));

		// get annual pay
		do
		{
			cout << "Enter Annual Pay for " << employees[i].GetName() << ": ";
			cin >> ap;
		} while (!employees[i].SetAnnualPay(ap));

		// get total hours worked
		do
		{
			cout << "Enter Hours Worked for " << employees[i].GetName() << ": ";
			cin >> wrkd;
			cout << endl;
			cin.ignore();
		} while (!employees[i].SetWorked(wrkd));

		// increment i
		i++;
	}
}

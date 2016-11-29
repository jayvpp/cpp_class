#include "stdafx.h"
#include "Employee.h"
#include <iomanip>
#include <cctype>

using namespace std;

// Mutator
bool Employee::SetName(string nm)
{
	bool valid = true;
	int i = 0;


	// Check input is valid
	while (i < nm.length())
	{
		// invalidate characters but letters and spaces
		if (!isalpha(nm[i]) && nm[i] != ' ')
		{
			valid = false;
			break;
		}

		// Capitalize first letter of last and middle names
		if (nm[i] == ' ')
		{
			nm[i + 1] = (toupper(nm[i + 1]));
		}

		i++;
	}

	//if input is not valid
	if (!valid)
	{
		cout << "Invalid input try again." << endl << endl;
	}

	//turns lowercase letters to upper automatically
	if (valid)
	{
		//capitalize first letter of first name 
		nm[0] = (toupper(nm[0]));
		//cout<<"Input accepted."<<endl<<endl;
	}

	name = nm;
	return valid;
}


bool Employee::SetEmployeeId(string eId)
{
	bool valid = true;

	//checks Employee id for format
	for (int i = 0; i<5; i++)
	{
		//convert lowercase entries to upper 
		eId[4] = (toupper(eId[4]));

		//checks length
		if (eId.length()<5 || eId.length()>5)
		{
			valid = false;
			break;
		}

		// make sure characters 0-2 are digits
		if (i<3)
		{
			if (!isdigit(eId[i]))
			{
				valid = false;
			}
		}
		//checks for '-'
		if (eId[3] != '-')
		{
			valid = false;
		}

		if (eId[4]<65 || eId[4]>77)
		{
			valid = false;
		}

	}

	//if input is not valid
	if (!valid)
	{
		cout << "Invalid input try again." << endl << endl;
	}

	// confirmation of valid input 
	// Converts lowercase letters to upper automatically
	if (valid)
	{
		//cout << "Input accepted." << endl << endl;
		
	}

	employeeId = eId;
	return valid;
}

bool Employee::SetHireDate(string hD)
{
	// valid input in the form of mm/dd/yyyy	
	bool valid = true;

	for (int i = 0; i < 10; i++)
	{
		if (hD.length()<10 || hD.length()>10)
		{
			valid = false;
			break;
		}

		if (i<2)
		{
			if (!isdigit(hD[i]))
			{
				valid = false;
			}

			//Cannot go over 12 months
			if (hD[0]>'1')
			{
				valid = false;
			}

			if (hD[0] == '1' && hD[1]>'2')
			{
				valid = false;
			}

		}

		if (hD[2] != '/' || hD[5] != '/')
		{
			valid = false;
		}

		if (i>2 && i<5)
		{
			if (!isdigit(hD[i]))
			{
				valid = false;
			}

			if (hD[3]>'3')
			{
				valid = false;
			}

			// Cannot go over 31 days
			if (hD[3] == '3' && hD[4]>'1')
			{
				//if(hD[4]>'1')
				valid = false;
			}

		}

		if (i>5 && i<10)
		{
			if (!isdigit(hD[i]))
			{
				valid = false;
			}

			// Ensure year is either 1900's or 2000's
			if (hD[6] != '1' && hD[6] != '2')
			{
				valid = false;
			}

			// Ensure year is either 1900's or 2000's
			if (hD[7] != '0' && hD[7] != '9')
			{
				valid = false;
			}
		}
	}

	//Invalid input
	if (!valid)
	{
		cout << "Invalid input try again." << endl << endl;
	}

	//confirmation of valid input turns lowercase letters to upper automatically
	//if(valid)
	//{cout<<"Input accepted."<<endl<<endl;}

	hireDate = hD;
	return valid;
}

bool Employee::SetSocial(string ssn)
{
	bool valid = true;

	for (int i = 0; i<11; i++)
	{
		if (ssn.length()<11 || ssn.length()>11)
		{
			valid = false;
			break;
		}

		if (i<3)
		{
			if (!isdigit(ssn[i]))
			{
				valid = false;
			}
		}

		if (i == 3 || i == 6)
		{
			if (ssn[i] != '-')
			{
				valid = false;
			}
		}

		if (i>3 && i<6)
		{
			if (!isdigit(ssn[i]))
			{
				valid = false;
			}
		}

		if (i>6 && i<11)
		{
			if (!isdigit(ssn[i]))
			{
				valid = false;
			}
		}
	}
	//Invalid input
	if (!valid)
	{
		cout << "Invalid entry try again." << endl << endl;
	}

	//confirmation of valid input
	//if(valid)
	//{cout<<"Input Accepted."<<endl<<endl;}

	social = ssn;
	return valid;
}

// Accessor
string Employee::GetName()
{
	return name;
}

string Employee::GetEmployeeId()
{
	return employeeId;
}

string Employee::GetHireDate()
{
	return hireDate;
}

string Employee::GetSocial()
{
	return social;
}

// Display
void Employee::PrintEmployee()
{
	cout << "\t\t EMPLOYEE INFORMATION\n\n";
	cout << "Name:  " << name << endl;
	cout << "Social:  " << social << endl;
	cout << "Employee ID:  " << employeeId << endl;
	cout << "Hire Date:  " << hireDate << endl;
}

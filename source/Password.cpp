//
//  main.cpp
//  example
//
//  Created by Jason Vega on 8/21/16.
//  Copyright © 2016 Jason Vega. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
class UserInputValidator
{
public:        
	static const int MIN_PASSWORD_SIZE = 6;
    static bool IsValidaPassword(const string& password)
    {
		return 
		password.length() >= MIN_PASSWORD_SIZE &&
        any_of(password.begin(), password.end(),::islower) &&
        any_of(password.begin(), password.end(),::isupper) &&
        any_of(password.begin(), password.end(),::isdigit);
	}
};
 

int main(int argc, const char * argv[])
{
	assert(UserInputValidator::IsValidaPassword("jason") == false);
	assert(UserInputValidator::IsValidaPassword("aqwert") == false);
	assert(UserInputValidator::IsValidaPassword("123ddd") == false);
	assert(UserInputValidator::IsValidaPassword("groupcL") == false);
	assert(UserInputValidator::IsValidaPassword("c++Class1") == true);
	assert(UserInputValidator::IsValidaPassword("MyValidPassword1") == true);
}



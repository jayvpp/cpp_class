//
//  main.cpp
//  example
//
//  Created by Jason Vega on 8/21/16.
//  Copyright © 2016 Jason Vega. All rights reserved.
//




#include <iostream>
#include <fstream>
#include <string>
#include "Students.h"
#include "DrawN.h"
#include "PassingData.h"
using namespace std;

namespace Lab1
{
    //Part1
    //No need to use an array of elements, we can just print the N on the stdout so we do not waste memory
}

namespace Lab2
{
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
}

int main(int argc, const char * argv[])
{
    //main_student();
    //main_drawn();
    main_passingdata();
}





// Student.h
// Created by
// Vega, Jason	      : vegaj32@mail.broward.edu
// Yep, Eben 	        : yepea4@bconline.broward.edu
// Dominguez, Michael : domim35@bconline.broward.edu
#pragma once
#include <iostream>
using namespace std;

struct FullName
{
    string lastname;
    string firstname;
    string midInitial;
};

struct Student
{
    FullName name;
    float tests[3];
    float average;
    char lettergrade;
};

float DetermineAverage(float v[3])
{
    return (v[0] + v[1] + v[2]) / 3 ;
}

char DetermineLetterGrade(float grade)
{
    if(grade > 100 || grade < 0) throw runtime_error("grade cannot be grater than 100");
    if(grade >= 90) return 'A';
    if(grade >= 80) return 'B';
    if(grade >= 70) return 'C';
    if(grade >= 60) return 'F';
    else return 'F';
}

Student GetData()
{
    Student student;

    cout << "Entering student data" << endl;

    cout << "Enter student name" << endl;
    cin  >> student.name.firstname;

    cout << "Enter student last name" << endl;
    cin  >> student.name.lastname;

    cout << "Enter student mid initial" << endl;
    cin  >> student.name.midInitial;

    cout << "Enter 3 test scores, space between grades" << endl;
    cin  >> student.tests[0] >> student.tests[1] >> student.tests[2];

    student.average = DetermineAverage(student.tests);
    //cout << "Student average " << student.average << endl;

    student.lettergrade = DetermineLetterGrade(student.average);
    //cout << "Student average letter grade" << student.lettergrade << endl;

    return student;
}

void PrintStudent(Student student)
{
    cout << "Student Name:\t" << student.name.firstname << " " << student.name.midInitial << " "          << student.name.lastname << endl;

    cout << "Test 1: \t\t"     << student.tests[0]    << endl;
    cout << "Test 2: \t\t"     << student.tests[1]    << endl;
    cout << "Test 3: \t\t"     << student.tests[2]    << endl;

    cout << "Average: \t\t"    << student.average     << endl;
    cout << "Final Grade: \t" << student.lettergrade << endl;
}

void main_student()
{
    Student roster[24];

    // This will promp user for information and will place the student object at the last position of the array.

    roster[23] = GetData();
    PrintStudent(roster[23]);

}

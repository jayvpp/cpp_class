//
//  PassingData.cpp
//  example
//
//  Created by Jason Vega on 10/20/16.
//  Copyright © 2016 Jason Vega. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

void GetData(ifstream& infile, int scores[], int& length)
{
    while (infile >> scores[length])
        length++;
}

void ProcessData(bool passing [],int scores[], int length)
{
    for(int i = 0; i < length; ++i)
    {
        if(scores[i] >= 60)
            passing[i] = 1;
        else passing[i] = 0;
    }
}

void main_passingdata()
{
    ifstream infile;
    int scores[100];
    int length = 0;
    
    //This will store the default location of the file.
    //We will ask for file_path, in case nothing is provided we will use the default one.
    string file_path;
    cout << "Enter full file path of the .txt file you want to process." << endl;
    getline(cin, file_path);
    
    if(file_path == "") file_path = "/Users/Jason/Downloads/lab1data.txt";
    
    infile.open(file_path);
    if(!infile.is_open())
    {
        cout << "Can't open file, check that correct file path was provided" << endl;
        exit(1);
    }
    
    GetData(infile, scores, length);
    
    bool passing_grades[100];
    ProcessData(passing_grades, scores, length);
    
    //Print to stdout
    cout << "Total Number of Grandes in the file: " << length << endl;
    for(int i = 0 ; i < length; ++i)
        (true == passing_grades[i]) ? cout << scores[i] << " : passed\n" : cout << scores[i] << ": failed" <<endl ;

}


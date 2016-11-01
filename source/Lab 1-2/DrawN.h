// DrawN.cpp
// Created by
// Vega, Jason	      : vegaj32@mail.broward.edu
// Yep, Eben 	        : yepea4@bconline.broward.edu
// Dominguez, Michael : domim35@bconline.broward.edu
#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

//This is better, no memory allocation at all, just printing data to stdout.
void printN(size_t n)
{
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if(r == c || c == 0 || c == n-1) cout << " N" ;
            else cout << "  ";
        }
        cout << "" << endl;
    }
}

void assignN(char N [10][10])
{
    memset(N, ' ', 100);
    for (int r = 0; r < 10; r++)
        N[r][0] = N[r][r] = N[r][9] = 'N';
}

void drawN(char N[10][10])
{
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if(r == c || c == 0 || c == 9) cout << " " << N[r][c] ;
            else cout << " " << N[r][c];
        }
        cout << "" << endl;
    }
}

void main_drawn()
{
    char n[10][10];
    assignN(n);
    drawN(n);

    //better way, no memory allocation
    //printN(10);
}

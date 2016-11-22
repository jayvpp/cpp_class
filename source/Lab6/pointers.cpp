//pointer example


#include<iostream>
using namespace std;

int main()
{
  int num1 = 10;
  int num2 = 25;
  float num3 = 20.5;
  double num4 = 3.5;
  

  //declare some pointers
  int *intptr1, *intptr2;
  float *floatptr;
  double *doubptr;

  //assign the address of num1 to intptr1
  intptr1 = &num1;

  cout<<"intptr1 = "<<intptr1<<endl;
  cout<<"num1 = "<<num1<<endl;
  cout<<"The address of num1 = "<<intptr1<<endl; 

  //dereference intptr1
  cout<<"intptr1 points to the value "<<*intptr1<<endl;
  //assign the address of num2 to intptr2
  intptr2 = &num2;
  cout<<"intptr2 = "<<intptr2<<endl;
  cout<<"num2 = "<<num2<<endl; 
  cout<<"The address of num2 = "<<intptr2<<endl; 

  //dereference intptr2
  cout<<"intptr2 points to the value "<<*intptr2<<endl;

  floatptr = &num3;
  cout<<"floatptr = "<<floatptr<<endl;
  cout<<"floatptr points to the value "<<*floatptr<<endl;
  cout<<"The address of num3 = "<<floatptr<<endl; 

  //assign the address of num4 to doubptr
  doubptr = &num4;
  cout<<"doubptr = "<<doubptr<<endl;
  cout<<"num4 = "<<num4<<endl; 
  cout<<"The address of num4 = "<<doubptr<<endl; 
    
  cout<<"intptr1 = "<<intptr1<<endl;
  cout<<"intptr2 = "<<intptr2<<endl;
  cout<<"floatptr = "<<floatptr<<endl;
  cout<<"doubptr = "<<doubptr<<endl;
  cout<<"&intptr1 = "<<&intptr1<<endl;
  cout<<"&intptr2 = "<<&intptr2<<endl;
  cout<<"&floatptr = "<<&floatptr<<endl;
  cout<<"&doubptr = "<<&doubptr<<endl;
  
  
  return 0;
}

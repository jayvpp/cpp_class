#include "NumberList.h"
#include<iostream>
using namespace std;

int main()
{
	//declare an instance of NumberList using the default constructor
	NumberList list1;
	
	//declare an instance of NumberList using the copy constructor
	NumberList list2 = list1;
	
	//append list1
	cout<<"Appending list1 with 10.0 and 15.0...\n";
	list1.appendNode(10.0);
	list2.appendNode(15.0);
	
	cout<<"Inserting 12.5 and 22.3 into list1...\n";
	list1.insertNode(12.5);
	list1.insertNode(22.3);
	
	cout<<"Displaying list1...\n";
	list1.displayList();
	
	//search for 12.5
	cout<<"12.5 is in position..."<<list1.searchNode(12.5)<<endl;
	cout<<"25 is in position..."<<list1.searchNode(25)<<endl;
	
	//use the overloaded = operator to assign list1 to list2
	list2 = list1;
	cout<<"Displaying list2...\n";
	list2.displayList();
	
 return 0;
}

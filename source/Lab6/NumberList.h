// NumberList.h
// Specification and implementation file for the NumberList class
/*THIS IS THE CORRECT FILE!!!!!*/

#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include<iostream>
using namespace std;

class NumberList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      double value;           // The value in this node
      ListNode *next;  	      // To point to the next node
   }; 

   ListNode *head;            // List head pointer

public:
   // Constructor
   NumberList()
      { head = 0; }
	
	//copy constructor
   NumberList(const NumberList &);
      
   // Destructor
   ~NumberList();
      
   // Linked list operations
   void appendNode(double);
   void insertNode(double);
   void deleteNode(double);
   void displayList() const;
   int searchNode(double);
   
   //overload the = operator
   void operator =(const NumberList &);

};
//copy constructor
NumberList::NumberList(const NumberList &obj)
   { cout<<"In the copy constructor...\n";
	ListNode *objPtr;
	
  //check if null
	if (obj.head == 0)
	{	
		head = 0;
		return;
	}
	
	//set objPtr to the head of the list being copied
	objPtr = obj.head;
	
    //allocate memory for a new ListNode for head
	head = new ListNode;
	
	//set the value of my head to the object's head's value
	head ->value = obj.head->value;
	head ->next = 0;
	objPtr = objPtr->next;
        
	while(objPtr!=0)
	  {     
		appendNode(objPtr->value);
		
		//move ptr along
		objPtr=objPtr->next;
	}
   }


void NumberList::appendNode(double num)
{	
   ListNode *newNode;  // To point to a new node
   ListNode *nodePtr;  // To move through the list

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = 0;

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
     
     nodePtr = head;
      // Find the last node in the list.
      while (nodePtr->next!=0)
	  	nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void NumberList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr!=0)
   {
      // Display the value in this node.
     cout<<nodePtr->value<<endl;

      // Move to the next node.
     nodePtr = nodePtr->next;
    
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void NumberList::insertNode(double num)
{	
   ListNode *newNode;             // A new node
   ListNode *nodePtr;             // To traverse the list
   ListNode *previousNode = 0; // The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = 0;
   
   // If there are no nodes in the list
   // make newNode the first node
   if(head==0)
     head = newNode;

   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
     nodePtr = head;

      // Initialize previousNode to NULL.
     previousNode = 0;

      // Skip all nodes whose value is less than num.
      while (nodePtr != 0 && nodePtr->value < num)
      {  
	previousNode = nodePtr;
	nodePtr = nodePtr->next; //move it along!
	
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == 0)
      {
	head = newNode;
	newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
        previousNode->next = newNode;
	newNode->next = nodePtr;
      }
   }
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void NumberList::deleteNode(double num)
{	
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == num)
   {
     nodePtr = head->next;
     delete head;
     head = nodePtr;
   }

   else
   {
     // Initialize nodePtr to head of list
     nodePtr = head;

     // Skip all nodes whose value member is 
     // not equal to num.
     while (nodePtr != 0 && nodePtr->value != num)
     {  
	previousNode = nodePtr;
	nodePtr = nodePtr->next;
     }

     // If nodePtr is not at the end of the list, 
     // link the previous node to the node after
     // nodePtr, then delete nodePtr.
     if (nodePtr)
     {
	previousNode->next = nodePtr->next;
	delete nodePtr;
     }

     else
     {
	cout<<"Value does not exist.\n";
     }
   }
}


//**************************************************
// Search list                                     *
// This function searches the list for a double.   *
//**************************************************
int NumberList::searchNode(double x)
{
  int position = 0;
  ListNode *nodePtr;

  nodePtr = head;

  while (nodePtr != 0 && nodePtr->value != x)
  {  
    nodePtr = nodePtr->next;
    position++;
  }

  if (nodePtr == 0)
    position = -1;

  return position;

}



    

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

 NumberList::~NumberList()
  {   cout<<"In the destructor...\n\n";
   ListNode *nodePtr;   // To traverse the list
     ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
  nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr)
  {
  
      // Save a pointer to the next node.
   nextNode = nodePtr->next;
cout<<"deleting a node...\n";
      // Delete the current node.
   delete nodePtr;

      // Position nodePtr at the next node.
   nodePtr = nextNode;
   }

  }
//overloaded = operator

void NumberList::operator =(const NumberList &obj)
   {
		
	ListNode *objPtr;
	
  //check of null
	if (obj.head == 0)
	{
		head = 0;
		return;
	}
	
	//set objPtr to the head of the list being copied
	objPtr = obj.head;
    //allocate memory for a new ListNode for head
	head = new ListNode;
	
	//set the value of my head to the object's head's value
	head->value = objPtr->value;
	head->next = 0;
	objPtr = objPtr->next;
        //cout<<mePtr->value<<endl;
	while(objPtr!=0)
	  {     
		appendNode(objPtr->value);
		//move ptr along
		objPtr=objPtr->next;
	}


   }

#endif

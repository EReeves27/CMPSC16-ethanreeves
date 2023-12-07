#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

//FOR FUTURE ETHAN JUST IN CASE YOU FORGET:
//Linked Lists are set up to have a "head" and a "tail"
//Each "head" and "tail" IS A NODE
//Each Node has two values: data and *next
//Data is literally the data stored within each node, but *next AUTOMATICALLY TAKES YOU TO THE NEXT NODE

void addIntToEndOfList(LinkedList *list, int value)
{
  assert(list != NULL); // if list is NULL, we can do nothing.

  Node *ptr = new Node(); //declaring a new node

  ptr -> data = value; //declaring the node's data
  ptr -> next = NULL; //saying the node points to nothing
  
  if (list -> head == NULL) //if the list is empty
  {
    list -> head = ptr; //set up data value as the head
    list -> tail = ptr; //set up data value as tail
  }
  else if (list -> tail == NULL) //if the tail is NULL
  { 
    list -> tail = list -> head; //set the tail equal to the head
    
    while (list -> tail -> next == NULL) //iterate through the linked list until the last node is reached
    {
      list -> tail = list -> tail -> next;
    }
    
    list -> tail -> next = ptr; //add the node to the linked list
    list -> tail = ptr; //tail now points to the new node
  }
  else //if we just have a normal linked list
  { 
    list -> tail -> next = ptr; //the tail now points to the new node
    list -> tail = ptr; //the tail is now the new node
  }
}

void addIntToStartOfList(LinkedList *list, int value)
{
  assert(list != NULL); // if list is NULL, we can do nothing.

  // Add code for this.
  // HINT:
  // consider all edge cases such as when list->head is or is not null AND
  // consider all edge cases such as when list->tail is or is not null.
  // Visualizing the problem with a box and pointer diagram can help.

  Node *ptr = new Node();
  ptr -> data = value; //assign value passed in to "data" of node

  if (list -> head == NULL) //if the head is NULL, so tail is also NULL
  {
    ptr -> next = NULL; //next node is NULL after ptr
    list -> head = ptr; //set head to ptr
    list -> tail = ptr; //set tail to ptr
  }
  else //if normal linked list
  {
    ptr -> next = list -> head; //pointer next Node is now pointing to head
    list -> head = ptr; //head is now the pointer, re-orders the list
  }
  
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element
// If more than one element has largest value,
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node *pointerToMax(LinkedList *list)
{

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   value of pointer to max element (first one if ties.)

  Node *max = new Node();
  Node *traverse = new Node();
  
  traverse = list -> head; //Traverse starts at beginning
  max = list -> head; //Assign head of Linked List to max
  
  int maxVal = max -> data; //Assign first value of Linked List to maxVal
  int checkVal; //this is how we will compare (just cleaner for me personally)
  while (traverse != NULL) //While traverse is not NULL, so while there is still a next node in line
  {
    checkVal = traverse -> data; //Store the new node's data to checkVal
    if (checkVal > maxVal) { //Compare and assign if it is greater
      max = traverse;
      maxVal = max -> data;
    }
    traverse = traverse -> next; //Move onto the next node in the Linked List
  }

  return max;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.
// You may assume list has at least one element
// If more than one element has smallest value,
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node *pointerToMin(LinkedList *list) //Everything that we did for pointerToMax is the same, just with the min
{

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   value of pointer to min element
  //   (first one such value that occurs if there are ties.)
  Node *min = new Node();
  Node *traverse = new Node();
  
  traverse = list -> head;
  min = list -> head;
  
  int minVal = min -> data;
  int checkVal;
  while (traverse != NULL)
  {
    checkVal = traverse -> data;
    if (checkVal < minVal) {
      min = traverse;
      minVal = min -> data;
    }
    traverse = traverse -> next;
  }

  return min;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list)
{

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   largest value in list (which may not be unique).
  Node *max = new Node();
  max = pointerToMax(list); //Since we know pointerToMax() returns the node with the max val, we can just used that same code!
  int maxVal = max -> data;
  
  return maxVal;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list)
{
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);
  assert(list->head != NULL);

  // TODO: Insert code here to calculate and return
  //   smallest value in list (which may not be unique).
  Node *min = new Node();
  min = pointerToMin(list); //Since we know pointerToMin returns the node with the min val, we can just use the same code!
  int minVal = min -> data;

  return minVal;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList *list)
{
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list != NULL);

  // TODO: Insert code here to calculate and return
  //   sum of all values in list (0 if there are none).
  Node *traverse = new Node();
  traverse = list -> head;
  
  int sum = 0;
  while (traverse != NULL) //Same process for what we did with pointerToMax (and Min), just summing
  {
    sum += traverse -> data;
    traverse = traverse -> next;
  }

  return sum;
}

#include "linkedListFuncs.h"
#include <stddef.h>
#include <bitset>/stdc++.h>

using namespace std;

/*All functions MUST be implemented recursively
* No credit will be given for non-recursive solutions
*/


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
  if (head -> next != NULL) //if there's still another Node after this one
    return (head -> data) + recursiveSum(head -> next); //add the current data to sum, recursive
  else
    return (head -> data); //return the last data to the sum
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
  Node* temp = new Node(); //declare temp node
  int currVal = head -> data; //set currVal to the data from the head node

  if (head -> next != NULL) //check if you're on the last Node
  {
    int nextVal = head -> next -> data; //setting to next node after head's data
    if (nextVal > currVal) //if the next Node is greater than the current Node
    {
      return recursiveLargestValue(head -> next); //run recursively with next Node
    }
    else
    {
      if (head -> next -> next == NULL) //check if this is the second to last Node
        return currVal; //since we already checked, we know this is the greatest Node
      else
      {
        temp = head -> next; 
        head -> next = head -> next -> next;
        free(temp); //all three lines (including this one) deletes the next Node
        return recursiveLargestValue(head); //recursively run with next Node being deleted
      }
    }
  }
  else //else return the last Node
    return currVal;
}


/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* recursiveFindKthNode(Node *head, int k){
  Node* temp = new Node();
  
  if (head != NULL) //checking to see if current node is NULL
  {
    if (k == 1) //set up so that every time recursively runs, k is 1 smaller
      return head; //if this returns, that means it has reached the Kth Node
    else
    {
      --k; //subtracting one from k
      temp = recursiveFindKthNode(head -> next, k); //recursively calling function
      return temp; //return the Kth Node
    }
  }
  else
    return NULL; //if k > size of list, return NULL
}


/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
Node* recursiveDeleteKthNode(Node *head, int k) {
  Node* temp = new Node(); //placeholder Node

  if (head != NULL) //checking to make sure we don't go over Linked List size
  {
    if (k == 2) //removing any Node besides the first
    {
      temp = head -> next;
      head -> next = head -> next -> next;
      free(temp);
      return head;
    }
    else if (k == 1) //removing first Node
    {
      temp = head;
      head = head -> next;
      free(temp);
      return head;
    }
    else
    {
      --k;
      temp = recursiveDeleteKthNode(head -> next, k); //recursive call to function
      return head;
    }
  }
  else //if we go past the linked list size without returning a node
    return NULL; //return NULL
}


/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* recursiveRemoveKFromFront(Node *head, int k) {
  Node* temp = new Node();

  if (k == 0)
  {
    return head;
  }
  else
  {
    --k;
    
    temp = head;
    head = head -> next;
    free(temp);
    
    temp = recursiveRemoveKFromFront(head, k);
    return temp;
  }
  
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) {
  Node* sumList = new Node(); //create a sum linked list
  
  if (head1 == NULL && head2 == NULL) //if it is the end of head1 & head2
  {
    sumList = NULL; //end the sum linked list
    return sumList; //return the last node of the linked list
  }
  else if (head1 != NULL && head2 != NULL) //if both head1 & head2 have a value
  {
    sumList -> data = (head1 -> data) + (head2 -> data); //add them together and place in sum linked list
    sumList -> next = recursiveElementwiseSum(head1 -> next, head2 -> next); //call function recursively
    return sumList; //return node to linked list
  }
  else if (head1 == NULL && head2 != NULL)
  {
    sumList -> data = head2 -> data; //if one of the lists has ended, only add the other
    sumList -> next = recursiveElementwiseSum(head1, head2 -> next); //call function recursively
    return sumList; //return node to linked list
  }
  else if (head2 == NULL && head1 != NULL)
  {
    sumList -> data = head1 -> data; //if one of the lists has ended, only add the other
    sumList -> next = recursiveElementwiseSum(head1 -> next, head2); //call function recursively
    return sumList; //return node to linked list
  }
}


/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) {
  Node* temp = new Node(); //set up temporary node

  if (head1 == NULL)
    return head2;
  else if (head2 == NULL)
    return head1;
  else
  {
    temp = head2 -> next; //set temp to the next values in the second list
    head2 -> next = head1 -> next; //set the next values in the second list to the next values in the first list
    head1 -> next = head2; //head of first list now points to start of second list
  }

  if (temp != NULL) //if temp still has values
  {
    recursiveSplice(head2 -> next, temp); //call recursively
    return head1; //done!
  }
  else
    return head1; //if temp is out of values, you're done!
}

/* 
old largestVal test
  if (head -> next != NULL) { //just making sure that we don't go out of bounds
    if (currVal > nextVal && head -> next -> next == NULL)
    //if the current value is greater than the next value and there's no node after the next node
    {
      return currVal; //return the maxVal
    }
    else
    {
      if (nextVal > currVal) //if the nextVal is greater than the currentVal
        currVal = recursiveLargestValue(head -> next); //run recursion again with next Node
      else
      {
        temp = head -> next; 
        head -> next = head -> next -> next;
        free(temp); //all three lines (including this one) deletes the next Node
        currVal = recursiveLargestValue(head); //run again
      }
    }
  }
  return currVal; //no matter what, return currVal if no Nodes left
*/

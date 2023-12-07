#include "linkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
    startTestGroup("ELEMENTWISE_SUM");
    
    //Initializes linked list n1 -> n2 -> n3
    Node n3 = {3, NULL};
    Node n2 = {2, &n3};
    Node n1 = {1, &n2};

    Node n6 = {6, NULL};
    Node n5 = {5, &n6};
    Node n4 = {4, &n5}; 

    //Expected result as a linked list after calling your function
    Node n9 = {9, NULL};
    Node n8 = {7, &n9};
    Node n7 = {5, &n8};

    //Calls your function
    Node *h1 = recursiveElementwiseSum(&n1, &n4);
    //Converts lists to strings and checks that the strings are equal
    assertEquals( listToString(&n7), listToString(h1), "1->2->3, 4->5->6");

    n3.next = &n4;
    Node n15 = {6, NULL};
    Node n14 = {5, &n15};
    Node n13 = {4, &n14};
    Node n12 = {12, &n13};
    Node n11 = {9, &n12};
    Node n10 = {6, &n11};
    h1 = recursiveElementwiseSum(&n1, &n7);
    assertEquals(listToString(&n10), listToString(h1), "1->2->3->4->5->6, 5->7->9");
}

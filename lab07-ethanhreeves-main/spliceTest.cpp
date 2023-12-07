#include "linkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
    startTestGroup("RETURNS_SPLICED_LINKED_LIST");
    
    //Initializes linked list e1 -> e2
    Node e2 = {2, NULL};
    Node e1 = {1, &e2};

    //Initializes linked list e3 -> e4
    Node e4 = {4, NULL};
    Node e3 = {3, &e4};

    //Creates array with the expected result - we test that the addresses of the nodes match and NOT the values
    //Therefore, this verifies that the nodes were redirected rather than just creating a new linked list
    Node *n1[] = {&e1, &e3, &e2, &e4}; 

    //Calls your function
    Node *h = recursiveSplice(&e1, &e3);

    /*Tests the outputs are what they should be; we iterate through the spliced linked list and verify
    * that each address corresponds to what it should in n1
    */
    cout << listToString(h) << endl;
    assertEquals(n1, 4, h, "Equal length");
}

#include "linkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
    startTestGroup("FIND_KTH_NODE");
    
    //Creates linked list e4 -> e5 -> e6
    Node e6 = {1, NULL};
    Node e5 = {2, &e6};
    Node e4 = {3, &e5};

    //Checks that the addresses of returned nodes are the same
    assertEquals(&e4, recursiveFindKthNode(&e4,1), "1st node of 1->2->3");
    assertEquals(&e6, recursiveFindKthNode(&e4, 3),"3rd node of 1->2->3");
}

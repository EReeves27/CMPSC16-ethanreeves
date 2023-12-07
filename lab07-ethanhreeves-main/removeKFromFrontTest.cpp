#include "linkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;


int main() {
    startTestGroup("REMOVE_K_NODES_FROM_THE_FRONT_OF_THE_LIST");
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();
        Node* a5 = new Node();

        a1->data = 1;
        a2->data = 2;
        a3->data = 3;
        a4->data = 4;
        a5->data = 5;

        a1->next = a2;
        a2->next = a3;
        a3->next = a4;
        a4->next = a5;
        a5->next = NULL;

        Node* p = recursiveRemoveKFromFront(a1, 3);
        assertEquals("4 5 ", listToString(p), "Remove 3 from front of 1->2->3->4->5");

        p = recursiveRemoveKFromFront(p, 1);
        assertEquals("5 ", listToString(p), "Remove 1 from front of 4->5");

        p = recursiveRemoveKFromFront(p, 1);
        assertEquals("", listToString(p), "Remove 1 from front of 5");
}
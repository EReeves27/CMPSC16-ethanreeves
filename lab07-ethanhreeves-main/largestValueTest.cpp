#include "linkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;


int main() {
    startTestGroup("LARGEST_VALUE");
        Node* a1 = new Node();
        Node* a2 = new Node();
        Node* a3 = new Node();
        Node* a4 = new Node();
        Node* a5 = new Node();

        a1->data = 5;
        a2->data = -12;
        a3->data = 0;
        a4->data = 100;
        a5->data = -3;

        a1->next = a2;
        a2->next = a3;
        a3->next = a4;
        a4->next = a5;
        a5->next = NULL;

        assertEquals(100, recursiveLargestValue(a1), "Largest of 5->-12->0->100->-3");
}

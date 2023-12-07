#ifndef linkedListFuncs_H
#define linkedListFuncs_H

struct Node {
    int data;
    Node *next;
};

int recursiveSum(Node* head);


int recursiveLargestValue(Node* head);


Node* recursiveFindKthNode(Node *head, int k);


Node* recursiveDeleteKthNode(Node *head, int k);


Node* recursiveRemoveKFromFront(Node *head, int k);


Node* recursiveElementwiseSum(Node *head1, Node *head2);


Node* recursiveSplice(Node *head1, Node *head2);


#endif
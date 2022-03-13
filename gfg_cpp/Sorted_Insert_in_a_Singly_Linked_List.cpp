
/*

    Sorted Insert in a Singly Linked List :-
         insertion in a sorted linked list. The linked list should remain sorted after insertion.

*/ 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;   // data
    Node *next; //  Pointer
    Node(int x){    // constructor
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    // Node *cur = head;        (or) Using direct head instead cur..
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node *sortInsert(Node *head, int d){    //  TC -> 0(N)..
    Node *temp = new Node(d);

    if (head == NULL){      // if head is NULL.. then return temp..
        return temp;
    }
    if (head -> data > d){  //  if head is greater than "d" then return temp as head after temp -> next is head..
        temp -> next = head;
        return temp;
    }
    Node *cur = head;       // check from head, if cur -> next != NULL and cur -> next -> data is smaller than "d"..
    while (cur -> next != NULL && (cur -> next -> data) < d){   // if true, then move forward.. till condition false..
        cur = cur -> next;
    } 
    temp -> next = cur -> next;     // if false, then temp -> next = cur -> next means assign the value to temp..
    cur -> next = temp;             //  and updating cur next as temp.. 
    return head;
}

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);

    head = sortInsert(head, 55);
    printList(head);
    return 0;
}
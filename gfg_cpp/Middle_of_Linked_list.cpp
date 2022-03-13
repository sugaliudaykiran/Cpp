/*
    Middle of linked list
        ** important interview problem where one needs to find the middle of a linked list of a given linked list.

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
    }cout << endl;
}

//      Navie - Solution :-      // It takes "2" traversal..
void Middle_node(Node *head){   //  In this we need to move curr from head to count/2;
    int count = 0;
    if (head == NULL){
        return;
    }

    Node *cur;
    for (cur = head; cur != NULL; cur = cur -> next){
        count++;
    }
    cur = head;
    for (int i=0; i<count/2; i++){  // move curr from head to count/2;
        cur = cur -> next;
    }
    cout << cur -> data << endl;
}
/*       Efficient - Solution :-
     By using two pointer as slow and fast, slow moves one node to other..
        were fast moves two nodes at a time..
*/

void mid(Node *head){   //  Takes one traversal..
    if (head == NULL){
        return;
    }
    Node *slow = head, *fast = head; 

    while (fast != NULL && fast -> next != NULL){   //  we check the fast node and fast next node should not be NULL..
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout << (slow -> data) << endl;     //  if NULL then print slow data..
}

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);
    printList(head);

    Middle_node(head);
    mid(head);

    return 0;
}
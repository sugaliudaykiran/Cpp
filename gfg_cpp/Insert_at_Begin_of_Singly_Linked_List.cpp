/*

    insert at the beginning of Singly Linked List :-

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

Node *insertBegin(Node *head, int x){   // Here insertBegin is an Pointer.. 
    Node *temp = new Node(x);           //  we create temp as new node of data "x" and pointing next to head..
    temp -> next = head;            
    return temp;                        // return temp..
}

void printList(Node *head){
    // Node *cur = head;        (or) Using direct head instead cur..
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int32_t main(){

    Node *head = NULL;                  //  first we assign the head to NULL..
    head = insertBegin(head, 30);       // it later turn to head and finally, the insertBegin acts as which we insert data, are stored in reverse order..
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);

    printList(head);
    return 0;
}
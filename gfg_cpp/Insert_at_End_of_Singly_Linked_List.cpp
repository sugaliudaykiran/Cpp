/*

    insert at the ending of Singly Linked List :-

    1) allocated the memory..
    2) if next node is NUll then make next node as new node..

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

Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);       // created new node for data..

    if (head == NULL){          // IF inserting is first/NUll in head then return temp in that place..
        return temp;    
    }                       // SIGTERM fault if it is not define..
    Node *cur = head;                  
    while(cur -> next != NULL){     // created "cur" pointing to head and check if it next is null and move forwards..
        cur = cur -> next;          
    }
    cur -> next = temp;         //  if next is null then insert the data to it.. and return head with out changing the pos of head..
    return head;
}


void printList(Node *head){
    // Node *cur = head;        (or) Using direct head instead cur..
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int32_t main(){

    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printList(head);
    return 0;
}
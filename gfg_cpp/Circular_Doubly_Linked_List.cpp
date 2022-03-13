/*
    In Circular doubly linked list :-
        1) Previous of head is Last node.
        2) Last node next is head.
    
    An Empty Circular Doubly linked list :-
        ** head is NULL..
    
    A single Node Circular Doubly linked list :-
        ** next of head is itself.
        ** previous of head is itself..

    It talks about its advantages and insertion :-
        ** We get all advantages of circular and doubly linked list..
        ** We can access last node in constant time without maintaining extra tail (or) pointer/references..

*/ 

/*

    Deleting kth node of a circular linked list where k is less than or equal to the number of nodes in the list.

*/ 
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int d){
        data = d;
        next = prev = NULL;
    }
};

//  Print Nodes :-      **{Using do while}
void printList2(Node *head){
    if (head == NULL) return;
    Node *p = head;
    do{             //  print ones in case of single node..
        cout << p -> data << " ";
        p = p -> next;
    }while(p != head);
    cout << endl;
}


//      Insert node at head :=
Node *insertHead(Node *head, int x){
    Node *temp = new Node(x);
    if (head == NULL){      //  In case of single node created node and it's prev and next will be temp itself..
        temp -> next = temp;
        temp -> prev = temp;
        return temp;
    }
    
    Node *t = head;
    temp -> prev = head -> prev;
    temp -> next = head;            // here we used head node and accessed to last node and link to temp node..

    head -> prev -> next = temp;    // and remove the link of head to last node.. and return head with change..
    head -> prev = temp;
    return temp;
}

//      Insert node at Last :=      {Just we need to return head with out changing the insertHead..}
Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if (head == NULL){          //  In case of single node created node and it's prev and next will be temp itself..
        temp -> next = temp;
        temp -> prev = temp;
        return temp;
    }
    
    Node *t = head;             // here we used head node and accessed to last node and link to temp node.. 
    temp -> prev = head -> prev;    // and remove the link of head to last node.. and return head with out change..
    temp -> next = head;

    head -> prev -> next = temp;
    head -> prev = temp;
    return head;
}


int32_t main(){
//    Creating a Doubly Circular Linked List :-    
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);

    head -> prev = t2;
    head -> next = t1;
    t1 -> prev = head;
    t1 -> next = t2;
    t2 -> prev = t1;
    t2 -> next = head;

    head = insertHead(head, 5);
    head = insertEnd(head, 40);

    printList2(head);
    return 0;
}

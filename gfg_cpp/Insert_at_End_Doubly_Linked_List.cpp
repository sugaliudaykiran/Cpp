/*
    implementations to insert a node at the ending of doubly linked list. 

*/
#include<bits/stdc++.h>
using namespace std;

struct Node{            
    int data;
    Node *prev;
    Node *next;
    Node (int d){
        data = d;
        prev = NULL;    //  prev = next = NULL;
        next = NULL;
    }
};

//      Printing them :-
void printList(Node *head){
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }   
}

//     Insert at Ending of Doubly Linked List :=
Node *insertEnd(Node *head, int x){
    Node *t1 = new Node(x);
    if (head == NULL){
        return t1;
    }
    
    Node *cur = head;
    while (cur -> next != NULL){
        cur = cur -> next;
    }
    cur -> next = t1;
    t1 -> prev = cur;
    return head;
}

int32_t main(){
    Node *head = NULL;
    
    head = insertEnd(head, 5);
    head = insertEnd(head, 15);

    printList(head);
    return 0;
}
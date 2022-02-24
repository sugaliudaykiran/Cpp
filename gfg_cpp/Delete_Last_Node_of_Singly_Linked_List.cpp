/*
    function to delete first node of linked list :-
    
*/ 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

//      print nodes :-
void printList(Node *head){
    while (head != NULL){                //  stops when node is NULL..
        cout << head -> data << " ";    
        head = head -> next;
    }cout << endl;
}

//      Delete last node :-    TC -> 0(N)..
Node *delLast(Node *head){
    if (head == NULL){
        return NULL;
    }
    if (head -> next == NULL){
        delete head;
        return NULL;
    }
    Node *cur = head;
    while (cur -> next -> next != NULL){
        cur = cur -> next;
    }
    delete (cur -> next);   //  Here it should be de - allocated node..
    cur -> next = NULL;
    return head;
}

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    
    printList(head);    

    head = delLast(head);

    printList(head);

    return 0;
}
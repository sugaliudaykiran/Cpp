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

//      Delete first node :-    TC -> O(1)..
Node *delNode(Node *head){
    if (head == NULL){      //  Check if node is null if, null then return..
        return NULL;
    }
    Node *temp = head -> next;  //  assign next node to temp node and delete the current/head node..
    delete head;
    return temp;            //  return the temp which has next node values..
}

//      print nodes :-
void printList(Node *head){
    while (head != NULL){                //  stops when node is NULL..
        cout << head -> data << " ";    
        head = head -> next;
    }cout << endl;
}

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    
    printList(head);    

    head = delNode(head);

    printList(head);

    return 0;
}
/*

    Remove duplicates from a sorted Singly Linked List :-
        Approach and implementation of a function to remove duplicates from a sorted singly linked list..

*/ 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void printNode(Node *head){
    if (head == NULL){
        return;
    }
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

//      Remove duplicates :-
void removeDup(Node *head){
    Node *cur = head;
    while (cur != NULL && cur -> next != NULL){     //  checks for NULL cases and last node..
        if (cur -> data == cur -> next -> data){    //  if cur node is same as cur next node, then duplicate is pointing and removed..
            Node *temp = cur -> next;
            cur -> next = cur -> next -> next;
            delete temp;
        }
        else {                                  //  In case of distinct elements, check next node..
            cur = cur -> next;                  //  Here in this case Head will never be changed so, we used Void..type..
        }
    }
}


int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(30);
    head -> next -> next -> next -> next = new Node(30);
    
    removeDup(head);
    printNode(head); 

    return 0;
}
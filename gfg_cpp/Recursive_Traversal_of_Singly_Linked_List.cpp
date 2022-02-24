/*
    Implementation of recursive function to print a singly linked list :-
    
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

//      Recursion :-        TC -> O(N)..    AS -> O(N).. {because in recursion takes N+1 space in function call stack..}
void printList(Node *head){  
    if (head == NULL){
        return;
    }
    cout << (head -> data) << " ";
    printList(head -> next);
}

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);

    printList(head);
    return 0;
}
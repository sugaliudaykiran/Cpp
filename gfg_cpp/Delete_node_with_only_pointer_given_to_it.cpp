/*

    Delete node with only pointer given to it :-
        This is one of the tricky problem asked in an interview where a random address to a node of the linked list 
            is given and the user needs to delete the node of the given address. 
            The address can point to any random node in-between a linked list.

    ** Idea :-  This Apporch works for the n-1 node.. for last node is will fail..because n node next is NULL..
        1) First create the temp_p pointing to given_p next..
        2) Copy the temp_p data into given_p data..
        3) make the given_p next to temp_p next..
        4) delete the temp_p node.. 
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

Node *printNode(Node *head){
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }cout << endl;
}

//      Delete Node only pointer which is given :-
void delNode(Node *ptr){
    Node *temp = ptr -> next;
    ptr -> data = temp -> data;
    ptr -> next = temp -> next;
    delete temp;
}

int32_t main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    Node *ptr = new Node(30);
    head -> next -> next = ptr;
    ptr -> next = new Node(40);
    ptr -> next -> next = new Node(50);
    printNode(head);
    
    delNode(ptr);
    printNode(head);

    return 0;
}
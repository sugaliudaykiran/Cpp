/*

        Circular Linked List :-
    ** Advantages :- 
        1) we can traverse the whole list from any node..
        2) Implementation of algorithms like round robin..
        3)  we can insert at the beginning and end, by just maintaing one "Tail" reference/Pointer..
    ** Dis - Advantages :-
        1) Implementations of operations becomes more complex.. like inserting new node and deletion and search a node..
        2) Takes more traverse..

    Circular Linked List Traversal :-
        Two methods for traversal of a circular linked list..
        1) for loop..
        2) do while()..
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

//  Print Nodes :-
void printList(Node *head){    
    if (head == NULL)
        return;
    
    cout << head -> data << " ";
    for (Node *cur=head->next; cur!=head; cur=cur->next){
        cout << cur -> data << " ";
    }cout << endl;
}

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

int32_t main(){
//      Creating a singler Circular Linked List :-    
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = head;

    printList(head);
    printList2(head);
    return 0;
}
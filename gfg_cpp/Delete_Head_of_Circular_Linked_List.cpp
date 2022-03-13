/*
    Delete Head of Circular Linked List :-
        deleting first node of a circular linked list..


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

    //  Delete Head of Circular Linked List :-  //  TC -> 0(N).. where n is nodes of linked list..
Node *delHead(Node *head){  
    if (head == NULL){
        return NULL;
    }
    if (head -> next == head){
        delete head;
        return NULL;
    }
    Node *cur = head;
    while (cur -> next != head){
        cur = cur -> next;
    }
    cur -> next = head -> next;
    delete head;
    return (cur -> next);
}

//      Efficient - Solution :-         TC -> 0(1)..
Node *delHead2(Node *head){
    if (head == NULL){
        return NULL;
    }
    if (head -> next == head){
        delete head;
        return NULL;
    }
    head -> data = head -> next -> data;    //  Here, head node is copied from head next node data and delete head next node..
    Node *temp = head -> next;
    head -> next = temp -> next;    // head -> next = head -> next -> next;
    delete temp;
    return head;
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
//    Creating a singler Circular Linked List :-    
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = head;

    // head = delHead(head);
    head = delHead2(head);
    printList2(head);
    return 0;
}
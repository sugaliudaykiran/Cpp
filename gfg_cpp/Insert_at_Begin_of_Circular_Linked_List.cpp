/*
    Insert at Begin of Circular Linked List is about two methods :-
        1) Naive : O(n)
        2) Efficient : O(1)
    
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

//      Insert at Begin :-     {Navie - Solution}     TC -> O(N).. (or) Using tail TC becomes O(1)..
Node *insertBegin(Node *head, int d){
    Node *t1 = new Node(d);

    if (head == NULL) t1 -> next = t1;
    else {
        Node *cur = head;
        while (cur -> next != head){
            cur = cur -> next;
        }
        cur -> next = t1;
        t1 -> next = head;
    }return t1; 
}

//      Efficient - Solution :-     TC -> O(1)..
Node *insertBegin2(Node *head, int d){
    Node *temp = new Node(d);   //  create an temp node..

    if (head == NULL){
        temp -> next = temp;    //  if node is NULL then temp -> next to temp and return temp..
        return temp;
    }
    else {                          // adding the secound node to the head node..
        temp -> next = head -> next;    // create a temp -> next is head -> next and head -> next is temp..
        head -> next = temp;

        int p = head -> data;       //  swapping the data by "p" between the head node and new added secound node..
        head -> data = temp -> data;
        temp -> data = p;           //  returning the same head..
    }return head;
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
    Node *head = NULL;
    Node *tail = NULL;      //  TC -> O(1)..
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);

    head = insertBegin2(head, 5);

    printList2(head);

    return 0;
}
/*

    Doubly - Linked_List :-

    Advantages :-
        >> Can be traversed in both directions.
        >> A given delete a node in O(1) time with given refernce/pointer to it.
        >> Insert/Delete "before a given node".
        >> Insert/Delete from both ends in O(1) time by "maintaining Tail".
    Dis - Advantages :-
        >> Extra space for prev.
        >> Code becomes more complex.
    ** {More complex with more fuctionality }
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

//     Insert at Begin of Doubly Linked List :=
Node *insertBegin(Node *head, int x){
    Node *t1 = new Node(x);         // Create a new node..
    t1 -> next = head;              //  node next is head and check the condition if node is not null then head prev is new node..
    if (head != NULL){  
        head -> prev = t1;
    }   
    return t1;                      // if head is null then return new node..
}

int32_t main(){
    Node *head = new Node(10);  // for head's prev and tail's next is NULL here..
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    
    head -> next = t1;
    t1 -> prev = head;
    t1 -> next = t2;
    t2 -> prev = t1;
    // printList(head);
    
    head = insertBegin(head, 5);

    printList(head);
    return 0;
}
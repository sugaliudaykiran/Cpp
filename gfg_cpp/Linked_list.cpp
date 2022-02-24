/*
    1. Ref :=   https://www.geeksforgeeks.org/arraylist-vs-linkedlist-java/
    2. Ref :=   https://www.geeksforgeeks.org/data-structures/linked-list/

    List :-
        int ar[n];
        int arr[100];
        int *ar = new int [n];
        vector <int> v;

    Problems with List :-
        1) Either size is fixed and pre - allocated (in both fixed and variable sized arrays), or
                 the worst case insertion at the end of list takes 0(N)..
        2) Insertion/Delection in middle (or beginning) is costly..
        3) Implementation of data structure like Queue and Deque is complex with arrays..

    (1)  How to implement Round Robin Scheduling ?
    (2)  Given a sequence of items. whenever we see an item 'x' in the sequence, we need to replace it with 5 instances of another item 'y'.

    Linked List    :-
        ** In Linked list items are in sequenical order but stored in various contiguous memory location..
        ** It define in form of node and reference {python/java} or pointer {c/c++} which is linked to next node..
        ** The idea is to drop the contiguous memory requirments so that insertions, deletions can efficiently happens at the middle also..
        ** And no need to pre - allocate the space (no extra node) 

    |--------|         |--------|     |---------|
    | 10| p1 |-------> | 20| p2 |---> | 30| Null|
    |--------|         |--------|     |---------|
    ^                                         ^
    |                                         |
    HEAD                                     NULL
    
    p1 is pointing to next node and similiar p2 is pointing p3..

    Memory (Array of bits) {8 bits -> 4 bits for data, remaining for pointer/reference..}

                        HEAD
                            |
    | 20 | 8000| ...      | 10 | 2000|    ..  | 30 | NULL |
  2000                   5000               8000

  
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{        //  Public valiable..
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

//      Traversing a single linked list :-
void printList(Node *head){
    Node *ref = head;

    while(ref != NULL){
        cout << ref -> data << " ";
        ref = ref -> next;
    }
}
//      Using same item as reference :-
void printList2(Node *head){        //  Here this Node *head is differ from in main function.. but address is refering is same..
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int32_t main(){
/* 
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);

    head -> next = t1;
    t1 -> next = t2;
*/  
    //  Simple Implementation :-

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    printList(head);
    printList2(head);
    return 0;
}


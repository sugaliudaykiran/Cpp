/*
    Merge two sorted linked lists :-
        It is an O(m+n) time and O(1) auxiliary space solution is discussed

        1) Take two pointer as 'a' and 'b' for list1, list2, it is pointing to both heads of lists..
        2) compare the head nodes of both lists and which is smaller head will the cur_head.. and using tail which easy to define..
        3) tail is pointing to cur_head.. and assuming list2 is smaller.. than list1..
        4) now increment the position of 'b' to next node and check the cur_'b' with cur_'a' node, if cur_'a' is smaller than tail is 
                pointing to cur_'a'.. and 'a' jumps to next node to it.. and compare with cur_'b'..
*/ 
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;   // data
    Node *next; //  Pointer
    Node(int x){    // constructor
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    // Node *cur = head;        (or) Using direct head instead cur..
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }cout << endl;
}

//      
Node *sortMerge(Node *a, Node *b){   //  TC -> O(M+N).. AS -> O(1).. where M is length of a, N is length of b.
    if (a == NULL)return b;
    if (b == NULL)return a;
    
    Node *tail = NULL, *head = NULL;
    if (a -> data <= b -> data){
        head = tail = a;
        a = a -> next;
    }
    else {
        head = tail = b;
        b = b -> next;
    }

    while (a != NULL && b != NULL){
        if (a -> data <= b -> data){
            tail -> next = a;
            tail = a;
            a = a -> next;
        }
        else {
            tail -> next = b;
            tail = b;
            b = b -> next;
        }
    }
    if (a == NULL){
        tail -> next = b;
    }
    else {
        tail -> next = a;
    }
    return head;
}


int32_t main(){     //  Both Linked list2 should be in sorted order..

    Node *a = new Node(10);
    a -> next = new Node(20);
    a -> next -> next = new Node(30);
    Node *b = new Node(5);
    b -> next = new Node(35);
    
    printList(sortMerge(a, b));
    return 0;
}
/*
    Pairwise swap nodes of linked list :-
        Method 1(Swapping Data) :-
            ** In this method we swap cur two nodes..
            ** Afer the swap, cur moves the two nodes..

        Method 2(Changing Pointers/References)
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
    }cout << endl;
}

//      Pairwise swap :-    //  In this swap, works for smaller data, in case of objects and large data.. swap takes costly..
void pairSwap(Node *head){  //  TC -> O(N).. AS -> O(1)..
    Node *cur = head;
    if (cur == NULL){
        return;
    }
    while (cur != NULL && cur -> next != NULL){
        swap(cur -> data, cur -> next -> data);
        cur = cur -> next -> next;  // we move two nodes forwards..
    }
}

//  Method - 2) Changing Pointer/Reference :-       TC -> O(N).. AS -> O(1)..
Node *pairSwap2(Node *head){
    if (head == NULL || head -> next == NULL){      //  Check the head and its next is NULL;
        return NULL;
    }
    Node *cur = head -> next -> next;   //  cur pointing to head -> next -> next means after the pair swap pointing Index..
    Node *prev = head;          //  prev pointing to head, to swap..
    head = head -> next;    
    head -> next = prev;        //  Here we swapped the first pair..

    while (cur != NULL && cur -> next != NULL){ //  check's the cur and its next..
        prev -> next = cur -> next;         //  prev's next is assing to cur's next.. and change prev to cur..
        prev = cur;             
        Node *next = cur -> next -> next;   //  next pointer to store cur's -> next -> next and after storing..
        cur -> next -> next = cur;      //  reverse the cur -> next -> next to cur.. and change cur to next..
        cur = next;
    }                                   //  finally change prev -> next to cur.. 
    prev -> next = cur;
    return head;
}

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);
    printNode(head); 

    pairSwap(head);
    printNode(head);
    
    head = pairSwap2(head);
    printNode(head); 
    return 0;
}
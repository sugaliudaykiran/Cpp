/*

Search in a Linked List (Iterative and Recursive)
finding position of an element in a linked list. let's talks about both iteratative and recursive solutions.

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

//      print nodes :-
void printList(Node *head){
    while (head != NULL){                //  stops when node is NULL..
        cout << head -> data << " ";    
        head = head -> next;
    }cout << endl;
}

//      search in linked list :-    //  TC -> O(N).. AS -> O(1)..
int searchLL(Node* head, int x){
    int pos = 1;
    Node *cur = head;
    
    while (cur != NULL){
        if (cur -> data == x){
            return pos;
        }
        else {
            pos++;
            cur = cur -> next;
        }
    }
    return -1;
}

//      Recursive - Solution :-         //  TC -> O(N).. AS -> O(N)..
int searchLL_rec(Node* head, int x){
    if (head == NULL){      //  if head is NULL return "-1"
        return -1;
    }
    if (head -> data == x){     //  if head -> data is equal to x then return "1".. 
        return 1;
    }
    else {
        int res = searchLL(head -> next, x);      //  recursive call..
        if (res == -1){     //  if res is "-1" not found in entire Nodes..
            return -1;
        }
        else{
            return (res +1);     //  recursion at some position is head -> data is equal to x then res is "1" then it position is increments here..
        }
    }
}

/*
    Similiar in array, we sort it and check the "x" in worst case it takes O(N_logN)..
    so, in linked list we can't sort so,, we use advances linked list so check out Skip list..

  Skip Linked List -> ref :-   https://www.geeksforgeeks.org/skip-list/     TC -> O(sqrt(N))

*/

int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);

    printList(head);   
    
    cout << searchLL(head, 30) << endl;
    cout << searchLL_rec(head, 30) << endl;
    
    // printList(head);

    return 0;
}
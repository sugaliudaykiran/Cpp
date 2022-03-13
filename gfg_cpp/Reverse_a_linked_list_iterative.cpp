/*

      Reverse a linked list iterative :-
            The problem of reversing a linked list in an iterative manner.
*/

#include<bits/stdc++.h>
#include<vector>
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

//           Navie - Solution :-    Takes 2 traversal.. AS -> O(N)..
Node *rev(Node *head){
    if (head == NULL){
        return NULL;
    }

    vector <int> v;     //  Here we use Vector to store and retiver the data in reverse order..
    Node *cur;
    for (cur = head; cur != NULL; cur = cur -> next){
        v.push_back(cur -> data);
    }
    for (cur = head; cur != NULL; cur = cur -> next){
        cur -> data = v.back(); //  which gives the last node..
        v.pop_back();
    }
    return head;
}


//          Efficient - Solution :-     TC -> O(N).. AS -> O(1)..
Node *rev2(Node *head){
    if (head == NULL)   return NULL;

    Node *cur = head;  
    Node *prev = NULL;      //  using prev as NULL;

    while (cur != NULL){        //  cur != NULL.. until, use "next" to pointing cur -> next nodes..
        Node *next = cur -> next;   
        cur -> next = prev;     //  cur -> next be previous..
        prev = cur;             //  prev as the present current..
        cur = next;             //  cur will be next node..
    }return prev;       //  prev is present last node.. and becomes first node as head..
}

int32_t main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);
    printList(head);

    head = rev(head);
    printList(head);


    head = rev2(head);
    printList(head);
    return 0;
}

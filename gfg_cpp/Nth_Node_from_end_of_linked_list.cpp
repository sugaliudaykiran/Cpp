/*

    Nth Node from end of linked list :-
        The problem on finding the n-th node from the end of a given linked list.
        ** Both Solution is Linear..
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

//          Navie - Solution :-     Takes 2 traversal for len and n_th last value..
void n_th(Node *head, int n){ 
    int len = 0;
    if (head == NULL){
        return;
    }
    Node *cur;
    for (cur = head; cur != NULL; cur = cur -> next){
        len++;
    }

    if (len < n){
        return;
    }
    cur = head;
    for (int i=0; i<(len-n); i++){      //  (or) for (int i=1; i<len-n+1; i++){ cur=cur->next}
        cur = cur -> next;
    }
    cout << cur -> data << endl;
}

/*      Efficient - Solution :- 

        {Using "2" Pointers/Ref_ Apporach.. as first, secound..}
            1) Move 'first' n positions ahead..
            2) Start 'secound' pointer from head..
            3) Move both 'first' and 'secound' at same speed. when 'first' reaches NULL, then
                    secound reaches the required node..
*/

void N_th(Node *head, int n){   //  Takes one traversal..
    Node *first = head, *secound = head;

    if (head == NULL)   return;

    for (int i=0; i<n; i++){            //  first traverse from n_th node of linked list..
        if (first == NULL)  return;     // if n is greater than length of nodes.. and first reaches NULL then return..
        first = first -> next;
    }
    while (first != NULL){      //  check upto first reaches NULL, then secound reaches N_th node..
        first = first -> next;
        secound = secound -> next;
    }
    cout << secound -> data << endl;
}


int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);
    printList(head);

    n_th(head, 5);
    N_th(head, 5);

    return 0;
}
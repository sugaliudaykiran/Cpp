/*
    Segregate even odd nodeS of linked list
        Given a singly linked list, the task is to segregate (or) separate the even and odd nodeS 
            of the linked list.. and relative order of all odd/even nodeS should same 
    
    Navie - Apporach :-
        1) first traverse the whole list and make a ptr at the end of the list..
        2) do another traverse from head to End node and check if any node is Odd then insert the node of last..
        3) Problem is it takeS two traversal..

    Efficient - Solution :-
        1) Here we takeS 4 pointers as OS, OE, eS, EE  -> (Odd/Even Start/End).. assing to NULL.
        2) Traverse the List and if Node is Odd/Even.. and Increment the End..
        3) If Only one type exits then return head..
        4) After forming the Certain nodeS of Odd/Even and connect as "Even End to Odd start and Odd End to NULL".. 
        5) Return eS as head..

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

Node *printNode(Node *head){
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }cout << endl;
}

//  Segregate Even/Odd :-   //  Takes One Traversal of Linked list..
Node *seg(Node *head){
    Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
    Node *cur;

    for (cur = head; cur != NULL; cur = cur->next){
        int x = cur -> data;
        if (x % 2 == 0){
            if (eS == NULL){
                eS = cur;
                eE = eS;
            }
            else {
                eE -> next = cur;
                eE = eE -> next;
            }
        }
        if (x % 2 != 0){
            if (oS == NULL){
                oS = cur;
                oE = oS;
            }
            else {
                oE -> next = cur;
                oE = oE -> next;
            }
        }
    }
    if (oS == NULL || eS == NULL){
        return head;
    }
    eE -> next = oS;
    oE -> next = NULL;
    return eS;
}

int32_t main(){
    Node *head = new Node(2);
    head -> next = new Node(5);
    Node *ptr = new Node(3);
    head -> next -> next = ptr;
    ptr -> next = new Node(4);
    ptr -> next -> next = new Node(8);      //  2 -> 5 -> 3 -> 4 -> 8    
    printNode(head);                    // ans:-  2 -> 4 -> 8 -> 5 -> 3
    head = seg(head);

    printNode(head);
    return 0;   
}
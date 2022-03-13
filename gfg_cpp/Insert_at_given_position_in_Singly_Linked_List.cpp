/*
    Approach and implementation of insertion at given position in a singly linked list :-

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

//      Insert at given position :-
Node *insertPos(Node *head, int pos, int data){
    Node *temp = new Node(data);
    if (pos == 1){              // on pos "1" we need to change the head node so, updated head..
        temp -> next = head;
        return head;
    }
    
    Node *cur = head;
    for (int i=1; i <= pos-2 && cur != NULL; i++){      // start from pos "1" and check upto pos-2..and cur val..
        cur = cur -> next;
    }
    if (cur == NULL){   //  pos is not available..
        return head;
    }
    temp -> next = cur -> next;     //  temp -> next will be cur -> next and cur -> next will be temp..
    cur -> next = temp;
    return head;
}


int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);

    printList(head);   

    int pos = 4, data = 35;  

    head = insertPos(head, pos, data);

    printList(head);

    return 0;
}
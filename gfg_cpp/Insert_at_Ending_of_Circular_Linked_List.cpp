/*
    Insert at Ending of Circular Linked List is about two methods :-
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

//      Insert at Ending :-     //  Navie - Solution :-     TC -> 0(N)..
Node *insertEnd(Node *head, int d){
    Node *temp = new Node(d);
    if (head == NULL){   
        temp -> next = temp;
        return temp;
    }
    else {
        Node *cur = head;
        while (cur -> next != head){
            cur = cur -> next;
        }
        cur -> next = temp;
        temp -> next = head;
    }return head;   
}

//      Efficient - Solution :- (or) using tail pointer..   TC -> O(1)..
Node *insertEnd2(Node *head, int d){
    Node *temp = new Node(d);

    if (head == NULL){      //  if node is null then temp -> next is temp and return temp..
        temp -> next = temp;
        return temp;
    }
    else {
        temp -> next = head -> next;    // Insert temp after head..
        head -> next = temp;

        int t = temp -> data;       //  swapping head and temp..
        temp -> data = head -> data;
        head -> data = t;
    }return temp;       //  temp is new head..
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
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    head = insertEnd2(head, 40);
    printList2(head);

    return 0;
}
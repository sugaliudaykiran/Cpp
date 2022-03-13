/*

        Reverse a Doubly Linked List :=
    
    ref :- https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/


    Delete Head of a Doubly Linked List :-
         deleting first node of a given doubly linked list.


*/ 

#include<bits/stdc++.h>
using namespace std;

struct Node{            
    int data;
    Node *prev;
    Node *next;
    Node (int d){
        data = d;
        prev = next = NULL;
    }
};

//      Printing them :-
void printList(Node *head){
    while (head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }cout << endl;
}
        
// Reverse a Doubly Linked List :=      TC -> O(N), where N denotes the number of nodes in the doubly linked list.                                
Node *reverseDll(Node *head){           // Auxiliary Space: O(1)
    if (head == NULL || head -> next == NULL) return head;  
                    // if head is NULL (or) in case head is only single node in those case it will works..
    Node *temp = NULL; 
    Node *cur = head;
    while (cur != NULL){           //  Swapping the prev and next, using temp..
        temp = cur -> prev;
        cur -> prev = cur -> next;
        cur -> next = temp;
        cur = cur -> prev;
    }
    return temp -> prev;
}

//  Delete Head of a Doubly Linked List :-  deleting first node of a given doubly linked list.
Node *delHead(Node *head){  //      TC -> O(1)..    AS -> O(1)..
    if (head == NULL){
        return NULL;
    }
    else if (head -> next == NULL){
        delete head;    //  Deallocation is required in cpp..
        return NULL;
    }
    else {
        Node *t1 = head;        //  first create pointer to head..
        head = head -> next;    //  change head to next node..
        head -> prev = NULL;    //  change curr head previous to NULL..
        delete t1;              //  delete pointer/Deallocation of node..
        return head;            // return updated head..
    }
}

//      Delete Last of a Doubly Linked List :-  deleting last node of a doubly linked list..
Node *delLast(Node *head){      //      TC -> 0(N) in improving the TC, use TAIL become 0(1) but disadvantage in Insert_Begin and Insert_End should assign clearly..
    if (head == NULL){      
        return NULL;            // in case of null then return null..
    }
    else if (head -> next == NULL){     // in case of single node first delete node and return null..
        delete head;
        return NULL;
    }
    else {
        Node *cur = head;               //  create a pointer to head..
        while (cur -> next != NULL){    //  if cur -> next is not null then continue.. 
            cur = cur -> next;
        }                               //  using tail as tail -> prev -> next = NULL;  0(1)..
        cur -> prev -> next = NULL;     // if cur -> next is null then assign the cur -> prev -> next which means previous node to cur node as NULL..       
        delete cur;                     // delete cur for deallocation..
        return head;                    //  return head..
    }
}




int32_t main(){
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);

    head -> next = t1;
    t1 -> prev = head;
    t1 -> next = t2;
    t2 -> prev = t1;

    head = reverseDll(head);
    printList(head);

    head = delHead(head);
    printList(head);

    head = delLast(head);
    printList(head);


    return 0;
}
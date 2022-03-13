/*

    Deleting kth node of a circular linked list where k is less than or equal to the number of nodes in the list.

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

//      Delete head node :-
Node *delHead(Node *head){
    if (head == NULL){
        return NULL;
    }
    if (head -> next == head){
        delete head;
        return NULL;
    }
    head -> data = head -> next -> data;
    Node *temp = head -> next;
    head -> next = temp -> next;
    delete temp;
    return head;
}

//      Delete_K_th_Node..
Node *K_th(Node *head, int k){
    if (head == NULL){      // if head is NUll then return NULL
        return NULL;
    }
    if (k == 1){            // if k == 1 then call the delHead()..
        return delHead(head);
    }
    Node *cur = head;           //  removing the k node using the prev node like, for 3_rd node we just need 2_nd node.., for this we need to jump from head node to 2_nd node.. 
    for (int i=0; i<k-2; i++){  //   similar if k = 4 we need to jump cur from head to 4_th prev node, so it takes "k-2 jumps"..
        cur = cur -> next;
    }
    Node *t = cur -> next;      //  after jumps cur -> next is the K_th node so, we use temp for dellaction..
    cur -> next = t -> next;    
    delete t;
    return head;
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
//    Creating a singler Circular Linked List :-    
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = head;

    head = K_th(head, 3);
    printList2(head);
    return 0;
}
/*

    Reverse a linked list in groups of size k
        Two methods are discussed here :-
        1) Recursive    =>      TC -> O(N)..     AS -> O(N/k..)
        2) Iterative

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

//      Reverse a linked list in groups of size "K" :-  TC -> O(N)..     AS -> O(N/k..)
Node *k_size(Node *head, int k){        
    Node *prev = NULL, *cur = head, *next = NULL;
    int count = 0; 
    while (count<k && cur != NULL){ //  If K is smaller than (or) equal to No of nodes, then first occurances of K_th node will be head.. if k is lesser than return last node..
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if (next != NULL){
        Node *rest_head = k_size(next, k);
        head -> next = rest_head;
    }
        return prev; 
}
                                    //  TC -> O(N).. AS -> O(1)..
//      Iteration - Solution :-     {first checks connection part and head part..}
Node *k_size2(Node *head, int k){
    Node *cur = head, *prev_first = NULL;   //  prev_first is used for each passes of k.. to connect next reversed node to last prev_first node..
    bool first_pass = true;             //  It is used for check wherther first pass is completed or not.. 
    while (cur != NULL){
        int count = 0;
        Node *first = cur, *prev = NULL;        //  first is used check for the last first of each passes.. and usually rev is initial NULL..
        while (cur != NULL && count < k){
            Node *next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        if (first_pass){    //  If true means, it was the first pass.. then update head and makes false..stment..
            head = prev;
            first_pass = false;
        }
        else {
            prev_first -> next = prev;   //  Because after 1'st pass "prev will be head" then in next pass
        }                                   //   prev_first next will be prev..
        prev_first = first;  //  In each case prev_first is updated by first..
    }
    return head;
}


int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);
    printNode(head); 

    head = k_size(head, 3);
    printNode(head); 
    
    head = k_size2(head, 3);
    printNode(head); 
    return 0;
}
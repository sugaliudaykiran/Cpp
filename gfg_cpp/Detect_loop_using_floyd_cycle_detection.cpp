/* 
    Detect loop using floyd cycle detection
         The problem of detecting a loop using the method of Floyd cycle detection.

    Ref :- https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
  Ref_2 :- https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

Algorithm :- 
    1) Initialize   slow_p = head, fast_p = head;
    2) Move slow_p by one and fast_p by two (twics).. if then pointers meet, then there is loop..

How it works :- 
    >> fast_p will enter into the loop before (or at same time as slow_p).
    >> let fast_p be "k distance ahead" of slow_p, when slow_p enter the loop where k >= 0;
    >> This "distance keeps on increasing by one" in every movement of both pointers.
    >> when distance becomes length of cycle, they meet..

    S/F ->     S        F
    -----    -----    -----    ------   ------  ------
    |   | -> |   | -> |   | -> |   | -> |   | -> |   |
                        ^                          |
                        ````````````````````````````                             
    <-------M---------> <-------------N----------->     TC -> O(M)+O(N).. which is Linear..O(N)..

    K+0         k+1             k+2,       k+3,     k+4, then slow and fast will meet..
      
*/      

#include<bits/stdc++.h>
#include<set>
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

//      Floyd_Cycle :-      //  TC -> O(N).. AS -> O(1)..
bool floyd(Node *head){
    Node *fast = head, *slow = head;            //  O(M) + O(N)     N is cycle length and M is distance from head to cycle.. 

    while (fast != NULL && fast -> next != NULL){   //  In case of No loop and two nodes with no loop..
        slow = slow -> next;
        fast = fast -> next -> next;       
        if (slow == fast){          // If these condition is top slow and fast conditions then it always true.. why because initial slow and fast pointing to head..
            return true;    
        }
    }
    return false;
}

int32_t main(){

    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = new Node(40);
    
    head -> next = t1;
    t1 -> next = t2;
    t2 -> next = t3;
    t3 -> next = t1;
    
    cout << floyd(head) << endl;

    return 0;
}
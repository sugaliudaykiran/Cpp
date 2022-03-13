/*

    Detect and remove loop in linked list :-    {Must check Detect Loop first..}
        The problem of detecting and removing a loop from the linked list by stopping the loop were it starts..
    
    1) Detect loop using floyd's detection algorithm.
    2) Move "slow_p" to the beginnig of the linked list {head} and "fast_p" at the meeting point itself..
    3) Now one by one move slow_p and fast_p (at same speed).
         The point where they meet now is the first node of loop {loop starting node..}

    How does this algo works ?

    S/F ->     S        F
    -----    -----    -----    ------   ------  ------
    |   | -> |   | -> |   | -> |   | -> |   | -> |   |
                        ^                          |
                        ````````````````````````````                             
    <-------M---------> <-------------N----------->   

    **  Here the S/F meets at two points in this case, 
        1) is in the cycle 
        2) is in the start node of loop (cycle) starts..

    ** Proof of Algo on bases of the first meeting point :-
            Before the first meeting point..                                    
        (Distance travelled by slow) *2 = (Distance travelled by fast)  // x -> No of iterations made by slow before the first meeting point..                                                                                
            (m + k + x*n) *2 =  (m + k + y*n);          //   y -> No of iterations made by fast before the first meeting point..
        
    Therefore, (m + k) = n(y - 2x) ==> (m + k) is "multiple of n".
    
    AFTER FIRST MEET :-
    ** If (m+n) is a multiple of n, then second meeting point is going to be the first node of loop..
        >> slow_p takes "m" distances travels from head to starting node of loop.
        >> fast_p takes "m+k" distance is taken the traverse complete and reaches it certain position..
        >> "Then we say that m+k is multiple of n" by these. {m+k -k => m}
        >> "m" is same distance that fast_p need to come at starting node of loop..

    // *** Variations :-
        1) Find length of loop.     //  Cycle detection algo.. using
        2) Find the first node of loop. //  Loop remove logic..
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
void floyd_remove(Node *head){
    Node *fast = head, *slow = head;

    while (fast != NULL && fast -> next != NULL){   //  Loop detection logic..
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow){
            break;
        }
    }
    if (slow != fast){      // In case there never meet, then no loop is present.. // this is comes because of fails of while conditions..
        return; 
    }
    slow = head;                        //      Loop remove logic..
    while (slow -> next != fast -> next){       //  In this we can also use prev pointers..
        slow = slow -> next;    //  both are moving in same speed..
        fast = fast -> next;
    }
    fast -> next = NULL;    //  by this we can say fast -> next is first meet node of cycle so we changed the fast -> next to NULL which break the loop..
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
    
    floyd_remove(head);
    printNode(head);

    return 0;
}
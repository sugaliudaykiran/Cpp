/*

    Recursive reverse a linked list (Part 1) :=
        The problem of reversing a linked list in a recursive manner.

    head-|   ------------------------
        X1 ->| X2 -> X3 ->... -> Xn |   assuming that this part is recursive reversed..
             ------------------------

             ________________________
        X1 ->| X2 <<- X3 <<-... <<- Xn |        //  check clearly..
        ^    ------------------------
        |      ^                     ^
      head     rest_tail         rest_head..

    ** we need to chance the rest_tail next from NULL to head.. and head next rest_tail to NULL, and
                rest_head as updated head..
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


//      Using Recursive Method  :-
Node *rev(Node *head){
    if (head == NULL || head -> next == NULL){  //  in case of NULL node and single node simple return head..
        return head;
    }

    Node *rest_head = rev(head -> next);    // assuming that rest_head is reversed..
    Node *rest_tail = head -> next;         //  assign rest_tail as head next..
    rest_tail -> next = head;               //  then, update rest_tail next NULL to head..
    head -> next = NULL;                    //  modify the head next to NULL..
    return rest_head;                       // then return rev.. node..
}


/*
    Recursive reverse a linked list (Part 2) :-
        In this method a tail recursive solution is discussed to reverse the linked list. This method simply follows the iterative solution.

    ** first recursive reverse the N-1 nodes.. and linking,  end node to the reversed linked list..

    
    head-|   ------------------------------------------
        X1 ->| X2 -> X3 ->...Xi-1 -> Xi -> Xi+1 -> Xn |   assuming that this part is recursive reversed..
             ------------------------------------------

       ____________________________________________________
       | X1 <- X2 <- X3 <-...<- Xi-1    Xi -> Xi+1 ->  Xn |        //  check clearly..
       ----------------------------------------------------
                                ^       ^
                                Prev    Curr

        ** When we are at Xi left were reversed.. upto Xi-1.. and to link Xi to Xi-1 we need extra pointer..
        ** First we link Xi+1 to next.. and break Curr -> next as prev and calls recursive calls..
        ** In making the recursive calls, before we need change "prev as cur and cur as next.."
        ** We stop at last node were cur becomes NULL and return prev..as head.. 

*/ 

Node *rev2(Node *cur, Node *prev){      // initially cur pointing to head and its prev is NULL..
    if (cur == NULL){           //  in case of NULL, single node, and in Last recursive call  last node reaches cur will be NULL and prev as last node.. then return prev..
        return prev;
    }

    Node *next = cur -> next;   //  we store cur -> next in pointer next..
    cur -> next = prev;         //  and change cur's next will be prev..
    return rev2(next, cur);     //  in recursive call change "cur as next and cur as prev"
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
    
    head = rev2(head, NULL);
    printList(head);
    return 0;
}

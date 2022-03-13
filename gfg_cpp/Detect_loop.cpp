/*
    Detect loop :-  Ref :- https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

        The problem of checking whether a linked list contains any loop or not. 
        We would discuss the four methods involved in detecting loops in a linked list, 
        one more efficient than other.

    Method 1 (at any cur_node check with the cur_node next node with cur_node previous nodes from head to cur_node..)   
                // TC -> O(N^2)..

    Method 2 (Using bool reference in each Node as Visited..)
        ** If Modifications to linked list structure are allowed -> O(N).. like :- 
            struct Node{
                int data;
                Node *next;
                bool *visited;
                Node(int d){
                    data = d;
                    next = NULL;
                    visited = false;
                }
            };
        ** 1) Keep all nodes visited as false.. after visiting each node keep visited as true..
        ** 2) In traversal, if node visited is true then loop is detect..

    Method 3 (Changes References/Pointers of Linked list..)     //  TC -> O(N)..
        1) Here we use temp node for checking.. like following steps..
        2) We traverse to each node and stores the next of cur node to a pointer..
        3) after pointing, cur node is changes next to temp node..
        4) If any loop is present, then in traversal we check any cur_node is already pointing to temp node.. then we can say that loop is detect..
    ** In this we changes entire Linked list..

    Method 4 (Hashing)  TC -> O(N).. AS -> O(N).  
        **  Here we stores the Address of node to be inserted..     AS -> O(N)
        **  If inserted node is repeated in set then return true..
    
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

// Method 3 (Changes References/Pointers of Linked list..)     //  TC -> O(N).. extra we used temp node..
bool detect(Node *head){
    Node *cur = head;
    Node *temp = new Node(0);

    while (cur != NULL){
        if (cur -> next == NULL){
            return false;
        }
        if (cur -> next == temp){   //  In this case loop is present.. check any node next is linked to temp..
            return true;
        }
        Node *next = cur -> next;
        cur = cur -> next;
        cur -> next = temp;
    }
    return false;
}

//      Using Hashing :-        TC -> O(N).. AS -> O(N)..
bool det2(Node *head){
    unordered_set <Node *> us;  //  Here we stores the Address of node to be inserted..
    for (Node *cur = head; cur != NULL; cur = cur -> next){
        if (us.find(cur) != us.end()){
            return true;
        }
        us.insert(cur);
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
    
    cout << det2(head) << endl;
    cout << detect(head) << endl;

    return 0;
}
/*
Clone a linked list using a random pointer
    Method (1) Using Hashing :-
        **  In this we traverse the list and creates address of each node in hashmap..
        **  and we traverse again add the next and random link of each node and finally we create the clone list with its links.. 

    Method (2)  Using Algorithm :-  {Using clone nodes in between the original nodes..}
        ** Create a copy node of each node and links the next and random to it particular node..


*/ 

#include<bits/stdc++.h>
#include<map>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *rand;
    Node(int d){
        data = d;
        next = NULL;
        rand = NULL;    //  random..
    }
};

void printNode(Node *start){
    while (start != NULL){
        cout << "Data = " << start -> data << " " << "Random = " << start -> rand -> data << endl;
        start = start -> next;
    }
}

//          Using Hashmap :-    TC -> O(N).. AS -> O(N)..
Node *clone(Node *head){
    unordered_map <Node *, Node *> um;  //  create an hash map which store address of nodes and its links..
    Node *cur;

    for (cur = head; cur != NULL; cur = cur -> next){
        um[cur] = new Node(cur -> data);    //  traverse the list and store data in hash map..
    }
    for (cur = head; cur != NULL; cur = cur -> next){
        Node *clone_cur = um[cur];              //  create an pointer to each node and links its next and random nodes..
        clone_cur -> next = um[cur -> next];    
        clone_cur -> rand = um[cur -> rand];
    }
    Node *h2 = um[head];    //  returns the clone hash map..
    return h2;
}

//      Using clone nodes in between the original nodes..
Node *clone2(Node *head){   
    Node *cur = head;       //      TC -> O(N).. AS -> O(1)..
    
    while (cur != NULL){            //  here we created the clone nodes in btw original nodes..
        Node *next = cur -> next;
        cur -> next = new Node(cur -> data);
        cur -> next -> next = next;
        cur = next;
    }

    for (cur = head; cur != NULL; cur = cur -> next -> next){   //  Here for clone nodes we add random links..
        cur -> next -> rand = cur -> rand -> next;
    }

    Node *original = head;
    Node *clone = head -> next; //          Here we seperating the clone and original nodes..
    Node *temp = clone;

    while (original && clone){
        original -> next = (original -> next)? original -> next -> next: original -> next;

        clone -> next = (clone -> next)? clone -> next -> next: clone -> next;
        
        original = original -> next;
        clone = clone -> next;
    }
    return temp;        // return clone head..
}


int32_t main(){

    Node *head = new Node(10);
    head -> next = new Node(5);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(15);
    head -> next -> next -> next -> next = new Node(20);

    head -> rand = head -> next -> next;
    head -> next -> rand = head -> next -> next -> next;
    head -> next -> next -> rand = head;
    head -> next -> next -> next -> rand = head -> next -> next;
    head -> next -> next -> next -> next -> rand = head -> next -> next -> next;

    //  Original list :=
    printNode(head); 
    cout << endl;
    
    //  Clone List :=
    head = clone2(head);
    printNode(head);
    return 0;
}
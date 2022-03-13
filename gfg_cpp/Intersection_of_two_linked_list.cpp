/*
Intersection of two linked list :-
    There are two methods :-
        1) Hashing :-   (Using Hash_set)    TC -> O(M+N).. AS -> O(M).. where M is len(list_1) and N is len(list_2)..
                a) Create an empty hash set, hs;
                b) Traverse the first list and put all of its nodes into the un_ordered set (hs).
                c) Traverse the second list and look for every node in hs. As soon as we find a node present in hs, 
                        return value of it..
            
        Method - (II)    TC -> O(M+N).. AS -> O(1)..
            a) Count nodes in both the lists, let counts be c1, c2.
            b) Travers the bigger list abs(c1 - c2) times.
            c) Traverse both the list symultaneously until we see a common node.

*/ 
#include <bits/stdc++.h> 
#include<set>
#include<climits>
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

//      Using Hashing :-        TC -> O(M+N).. AS -> O(M).. where M is len(list_1) and N is len(list_2)..
int getInter(Node *head1,Node *head2){
    unordered_set <Node *> us;
    Node *cur;              
    for (cur = head1; cur != NULL; cur = cur -> next){  
        us.insert(cur);
    }
    for (cur = head2; cur != NULL; cur = cur -> next){
        if (us.find(cur) != us.end()){
            return cur -> data;
        }
    }
    return -1;
}

//  Efficient - Solution :-     TC -> O(M+N).. AS -> O(1)..
int getCount(Node *head){
    Node *cur = head;       //  Here we counts of the length of length..
    int count = 0;
    while (cur != NULL){
        count++;
        cur = cur -> next;
    }
    return count;
}

int _get(int d, Node *head1, Node *head2){  //  Here we check intersection part..
    Node *cur1 = head1;
    Node *cur2 = head2;

    for (int i=0; i < d; i++){      //  Here we traverse the "d" distance of largest list and checks with smaller further..
        if (cur1 == NULL){
            return -1;      //  If in middle cur becomes NULL then return -1..
        }
        cur1 = cur1 -> next;
    }

    while (cur1 != NULL && cur2 != NULL){
        if (cur1 == cur2 ){
            return  cur1 -> data;       //  Here we check the same length of both list and
        }                       //   traverse the hole list if any intersect is there..and return node..
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }return -1;
}

//  getIntersection :-  TC -> O(M+N).. AS -> O(1)..
int getinter(Node *head1, Node *head2){
    int c1 = getCount(head1);       //  check the difference.. of h1, h2..lists..
    int c2 = getCount(head2);
    int d;

    if (c1 > c2){                   //  Here we check, the larger list and do traverse the "d" distance..
        d = abs(c1 - c2);
        return _get(d, head1, head2);
    }
    else {
        d = abs(c2 - c1);       //  If List2 is greater than we change the position in arguments..
        return _get(d, head2, head1);   //  Check this clerly..
    }
    return -1;
}

int32_t main() 
{ 
    Node *newNode;

	Node *head1 =new Node(10);
    Node *head2 = new Node(25);

    newNode = new Node(20);
    head1 -> next = newNode;

    newNode = new Node(30);
    head1 -> next -> next = newNode;
    head2 -> next = newNode;

    newNode = new Node(40);
    head1 -> next -> next -> next = newNode;
    head2 -> next -> next = newNode;

	printlist(head1);
	printlist(head2);
    cout << endl;
    cout << getInter(head1, head2);

    cout << endl;
    cout << getinter(head1, head2);
	return 0;
} 
 
 /*  Try :-
		Creation of two linked lists 
	
		1st 3->6->9->15->30 
		2nd 10->15->30 
	
		15 is the intersection point 
	*/
 

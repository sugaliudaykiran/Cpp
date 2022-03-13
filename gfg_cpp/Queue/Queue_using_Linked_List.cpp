/*

    Implementation of Queue using Linked List   :-
        Through this, we will learn the Implementation of a queue using a LinkedList.
    
        Using Single Linked list implementing Queue in O(1)..
    Queue has main two Operations like enque(x) and deque() and additional operations are size(), getFront(), getRear(), isEmpty()..

    Idea :-
    ** Using Two Pointer as like front and rear and insertion on next of rear and remove on front and update the front..
    ** TC -> O(1).. by choosing the head as front and tail as rear..
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

struct Queue{           //  TC -> O(1).. 
    Node *front, *rear;
    int size;
    Queue(){
        front = rear = NULL;
        size = 0;
    }

    void enque(int x){
        Node *temp = new Node(x);
        if (front == NULL){
            front = rear = temp;
            size++;
            return;
        }
        rear -> next = temp;
        rear = temp;
        size++;
    }

    void deque(){
        if (front == NULL){
            return;
        }
        Node *temp = front;
        front = front -> next;
        if (front == NULL){
            rear = NULL;
        }

        delete temp;
        size--;
    }

    int sizes(){
        return size;
    }

    int getFront(){
        return front -> data;
    }
    int getRear(){
        return rear -> data;
    }

    bool isEmpty(){
        return (front == NULL); //  (or) rear == NULL..
    }
};


int32_t main(){

    Queue qu;
    qu.enque(10);
    qu.enque(20);
    qu.enque(30);

    cout << qu.getRear() << endl;
    cout << qu.sizes() << endl;
    qu.deque();
    cout << qu.getFront() << endl;

    return 0;
}
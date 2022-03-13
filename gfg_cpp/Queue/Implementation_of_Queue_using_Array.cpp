/*

        Implementation of Queue using Array :-
    Through this, we will learn the Implementation of a queue using an array.

    enqueue(X) -> Insert new item at next of Cur_rear and update the rear to inserted new item..
    dequeue()  -> remove item of the Cur_front and update front to next of Cur_front..

    additional Operations :-
        size()      -> return size of queue
        getFront()  -> return front item of the queue
        getRear()   -> return rear item of the queue
        isFull()    -> here, we are using array by this we have capacity and size.. if capacity == size, then it is Full..
        isEmpty()   -> if stack is empty return the true else, false..     
*/ 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

    //  Simple Implementation :-    //  Navie - Solution..
struct Queue{
    int cap, size;
    int *ar;
    
    Queue(int c){
        cap = c;
        size = 0;
        ar = new int[cap];
    }

    bool isFull(){
        return (size == cap);
    }
    bool isEmpty(){
        return (size == 0);
    }

    void enque(int x){
        if (isFull()){
            return;
        }
        ar[size] = x;
        size++;
    }
    void deque(){                   //  TC -> O(n).. remaining all operations takes O(1)..
        if (isEmpty()){
            return;
        }
        for (int i=0; i<size-1; i++){
            ar[i] = ar[i+1];
        }
        size--;
    }

    int getFront(){
        if (isEmpty()){
            return -1;
        }
        return 0;
    }
    int getRear(){
        if (isEmpty()){
            return -1;
        }
        return size-1;
    }
};

/*     Efficient Implementation :-  (Circular Array..)  TC -> O(1)..

    ** In this Implementation, we declar an pointer to front and for the position of 
        rear we use the front as  (front + size -1) % cap ..
    ** In enqueu(X) we insert at rear next by using (rear + 1) % cap.. and size++ ..
    ** In dequeu()  we uses the front, as pointing front next as new front..
            new front is (front +1) % cap.. and size-- ..
        
*/
struct Queue2{
    int *ar;
    int front, size;
    unsigned cap;   // only positive.. integers..

    Queue2(int c){
        ar = new int[c];
        cap = c;
        size = 0;
        front = 0;
    }
    bool isEmpty(){
        return (size == 0);
    }
    bool isFull(){
        return (size == cap);
    }
    
    int getFront(){
        if (isEmpty()){
            return -1;
        }   
        else{
            return front;
        }
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        else{    
            return (front + size -1) % cap;     // Which return index of rear with front..
        }
    }

    void enque(int x){
        if (isFull()){   
            return;
        }
        int rear = getRear();
        rear = (rear+1)%cap;
        ar[rear] = x;
        size++;
    }
    void deque(){
        if (isEmpty()){
            return;
        }
        front = (front +1) % cap;
        size--;
    }
};

int32_t main(){

    Queue2 qu(5);
    qu.enque(10);
    qu.enque(20);
    qu.enque(30);

    cout << qu.getFront() << endl;
    qu.deque();
    cout << qu.getRear() << endl;


    // Queue qu(5);
    // qu.enque(10);
    // qu.enque(20);
    // qu.enque(30);

    // cout << qu.getFront() << endl;
    // qu.deque();
    // cout << qu.getRear() << endl;

}


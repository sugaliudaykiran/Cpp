/*
        Array Implementation of Deque :-
    
    ** In Simple Implementation of Deque Using array :-
        1) In array insert/delete at rear are O(1) but where as the insert/delete front are O(N).. where N is size of deque..
        2) So, we use Circular array..
    
    ** In Efficient Solution :-
        1) In this implementation, we assumes the array as the Circular Buffer..
        2) In this we has changes in insert/delect..
            deleteFront()
                front = (front-1) % capacity.
            insertRear(X)
                rear = (rear +1) % capacity.
        
        various from above.. check this clearly..
            insertFront(X)
                front = (front - 1 + cap) % cap.
            deleteRear()
                rear = (rear - 1 + cap) % cap.
        
        ** rear = (front + size -1) % cap.. instead of using rear, we can get by using front.. 


*/      

#include<bits/stdc++.h>
using namespace std;

//          Simple Implementation :-
struct deques{
    int size, cap;
    int *ar;
    deques(int c){
        cap = c;
        size = 0;
        ar = new int[cap];
    }

    bool isEmpty(){
        return (size == 0);
    }
    bool isFull(){
        return (size == cap);
    }
    
    int getSize(){
        return size;
    }

    void deleteRear(){
        if (isEmpty()){
            return;
        }
        size--;
    }
    void deleteFront(){                 //  takes O(n).. remaining all operations are O(1)..
        if (isEmpty()){
            return;
        }
        for (int i=0; i<size-1; i++){
            ar[i] = ar[i+1];
        }
        size--;
    }

    int getRear(){
        if (isEmpty()){
            return -1;
        }
        return ar[size-1];  //  size -1 th index..
    }
    int getFront(){
        if (isEmpty()){
            return -1;
        }
        return ar[0];   // 0 th index..
    }

    void insertRear(int x){
        if (isFull()){
            return;
        }
        ar[size] = x;
        size++;
    }
    void insertFront(int x){        //  takes TC -> O(N)..
        if (isFull()){
            return;
        }
        for (int i=size-1; i>=0; i--){
            ar[i+1] = ar[i];
        }
        ar[0] = x;
        size++;
    }
};

//          Efficient Implementation :-     TC -> O(1).. All the operations..
    /*
            deleteFront()
                front = (front-1) % capacity.
            insertRear(X)
                rear = (rear +1) % capacity.
        
        various from above.. check this clearly..
            insertFront(X)
                front = (front - 1 + cap) % cap.
            deleteRear()
                rear = (rear - 1 + cap) % cap.
        
        ** rear = (front + size -1) % cap.. instead of using rear, we can get by using front
*/

struct Deque{
    int cap, size, front;   // TC -> O(1).. All the operations..
    int *ar;

    Deque(int c){
        cap = c;
        size = front = 0;
        ar = new int[cap];
    }
    bool isEmpty(){
        return (size == 0);
    }
    bool isFull(){
        return (size == cap);
    }

    void deleteFront(){
        if (isEmpty()){
            return;
        }
        front = (front + 1) % cap;
        size--;
    }
    void insertRear(int x){
        if (isFull()){
            return;
        }
        int newRear = (front + size) % cap;     //  (front + size -1) % cap    to get rear index and to insert new item in next to rear.. rear = (rear + 1) % cap..
        ar[newRear] = x;
        size++;  
    }

    int getFront(){
        if (isEmpty()){
            return -1;
        }
        return ar[front];
    }

    void insertFront(int x){
        if (isFull()){
            return;
        }
        front = (front + cap -1) % cap;     // cap because to avoid Negative indexing..
        ar[front] = x;
        size++;
    }

    void deleteRear(){
        if (isEmpty()){
            return;
        }
        size--;     //  Here we are not using rear pointer so, we just decrease the size..
    }
    int getRear(){
        if (isEmpty()){
            return -1;
        }
        return ar[(front + size - 1) % cap];
    } 
}; 

int32_t main(){

    Deque dq(5);           // TC -> O(1).. All the operations..
    // deques dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.insertFront(40);
    dq.insertFront(50);

    cout << dq.getFront() << endl;
    dq.deleteFront();
    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;
    // cout << dq.getSize() << endl;
    return 0;
}

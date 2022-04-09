/*

Binary Heap (Decrease Key, Delete and Build Heap) :- 
In this, discusses the Decrease Key, Delete and Build Heap operation of Binary Heap.

    Code(Decrease Key & Delete) :-
        1) Decrease Key in this we are given 'i' and 'x', on i index we need to modify the value x..
        2) and maintain the Min Heap..
        Ex.,                    
                            10
                          /    \
                        20      40
                      /   \     /
                    80    100  70
        
        **  given i = 3, x = 5;     '80 to 5'
        **  In this we change i th node to 5 and now it, violate the Min heap properities..
                             5
                          /    \
                        10      40
                      /   \     /
                    20    100  70
        Idea :- We first change the x value on i th index and check with it's parent, similiar to insert..
    
    Delete :-
        1) In this we given i and need to delete the i th node in the tree..
        2) and modify the tree to follow the minheap..
                            10
                          /    \
                        20      30
                      /   \    /   \
                    40    50  35   38
                  /
                45
        
        ** given i = 3; on the i_th 40 is the value.. so, we need to delete 40..
    Idea :- In this we assumes that i_th value call the DecreaseKey and change i_th value to INT_MIN, and implements
                Extract.. by this we move i_th value to root and remove the root
                and make to follows the MinHeap..

    Code(Build Heap) :- 
        1) Given a random array, rearrange its elements to form a min Heap, 
            I/p :-  ar[] = [10, 5, 20, 2, 4, 8]
            O/p :-  ar[] = [2, 4, 8, 5, 10, 20]

                            10
                          /   \
                         5     20
                       /  \   /
                      2    4 8 

                            2
                          /   \
                         4     8
                       /  \   /
                      5    10 20 
        
        ** In this we first check, the Bottom most right most internal node  subtree and check, it's balanced or not., then balance it,
            now check on the right subtree and check, it's balanced or not.. balances it and check the next level right subtree..
    
    Idea :-     (Because we assumes that left and right nodes of the i_th node should be MinHeapify)
        1) beign with Bottom most right most internal node and assuming that it's i_th node then we call minHeap for it and ..
        2) Next we check for (i-1) th node.. and soon.
        3) Upto the root of the tree..

    Time Complexity :-  O(n)    [n = size]..
        Maximum number of nodes at height 'h'   :-
                  n
    =>  ceil -----------
               2_pow(h +1)
    
    Total time :-   
        for h = 1 to logn               n
                    ceil          ----------  O(h)
                                    2_pow(h+1)

        =>  O(n * for h=1 to logn)    h
                                    --------
                                    2_pow(h+1)

        if n = 15
            h = 1
                         15
                       --------  =>  4         
                        2^(1+1)
    
    ** Sum of series is 1.. when we put.. then O(n)..
                      h                     1                 2
            s =    --------------     =  ---------    +   ---------   +..
                      2_pow(h+1)          2_pow(2)          2_pow(3)

*/ 

#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int *ar;
    int size;
    int capacity;

    public:
    MinHeap(int c){
        size = 0;
        capacity = c;
        ar = new int[c];
    }

    int left(int i){
        return (2*i +1);
    }
    int right(int i){
        return (2*i +2);
    }
    int parent(int i){
        return (i-1)/2;
    }
    
    void insert(int x){
        if (size == capacity){
            return;
        }
        size++;
        ar[size -1] = x;
        
        for (int i=size-1; i!=0 and ar[parent(i)] > ar[i];){
            swap(ar[i], ar[parent(i)]);
            i = parent(i);
        }
    }
    
    int extractMin(){           //  TC -> O(log n)..    using iterative it takes O(1).. AS
        if (size == 0){     
            return INT_MAX;
        }
        if (size == 1){         // return top and decrease the size..
            size--;
            return ar[0];
        }
        swap(ar[0], ar[size -1]);   
        size--;
        MinHeapify(0);          //  Here we call Heapify for root of tree..

        return ar[size];
    }
   
    //      MinHeapify :-       TC -> O(h) or O(log n)..    AS -> O(h)..    using iteration O(1)..
    void MinHeapify(int i){
        int lt = left(i);
        int rt = right(i);
        int smallest = i;

        if (lt < size and ar[lt] < ar[i]){
            smallest = lt;                      //  Check the smallest left and right of it..
        }
        if (rt < size && ar[rt] < ar[smallest]){
            smallest = rt;
        }
        if (smallest != i){                 //  Check if any smallest one..
            swap(ar[i], ar[smallest]);
            MinHeapify(smallest);
        }
    }

    void decreaseKey(int i, int x){     //  TC -> O(log n)..
        ar[i] = x;
        while (i != 0 and ar[i] < ar[parent(i)]){
            swap(ar[parent(i)], ar[i]);
            i = parent(i);
        }
    }

    void Delete(int i){         //  TC -> O(log n)..
        decreaseKey(i, INT_MIN);
        extractMin();       
    }

    void bulidHeap(){       //  TC -> O(log n)  -> O(n)..
        for (int i=(size - 2)/2; i>= 0; i--){       //  i, for last node we have (size -1) but for parent of it is floor(size - 1)-1/2;
            minHeapify(i);  // and call for each node.. which is O(log n)..
        }
    }

};


int32_t main(){

    MinHeap mh(11);
    mh.insert(10);
    mh.insert(20);
    mh.insert(40);
    mh.insert(80);
    mh.insert(100);
    mh.insert(70);


    return 0;
}
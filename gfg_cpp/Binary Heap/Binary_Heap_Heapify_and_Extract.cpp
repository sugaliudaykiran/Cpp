/*

Binary Heap (Heapify and Extract Min)   :-
    In this, discusses the Heapify and Extract operation and how can it be implemented in a Binary Heap.

    ** Min Heapify :-   Given a Binary Heap with one possible violation, fix the heap..
        
        I/p :-       
                            40
                          /    \
                         20     30          
                       /   \   /  \
                      35   25 80  32
                    /  \   /
                 100   70 60
    
    ** In above Binary tree the node 40 is violating the Min heapify properities.. but it subtree are following the Min heap properities..
                            20
                          /    \
                         40     30      //  Swaping, the left and right node if, it is smaller.. 40 swap with 20
                       /   \   /  \
                      35   25 80  32
                    /  \   /
                 100   70 60

                            20
                          /    \
                         25     30
                       /   \   /  \
                      35   40 80  32        //  again, 40 swap with 25.. and now 40 left is greater then it.. so final it's Min Heap..
                    /  \   /
                 100   70 60

Steps for Min Heapify :-
    1) We compare the i_th node with it's left and right node and check if it's smaller, then swap with
     the smaller one and recursive call, it's left and right node and check whether, any smaller node than it..
    2) Finally stop at root (or) in-case of greater children of it..

Heap Implemtation :-
        ** If we want create heap with out library then, we need to know the capacity and size of array..
        ** size <= capacity
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
    /*  getMin is constant opertions.. in prioity queue.. top is min..
          ExtractMin :-  In this we need to remove the node and perform MinHeapify and maintain Binary Heap..
                       
                            20
                          /    \
                         25     30          
                       /   \   /  \
                      35   40 80  32
                    /  \   /
                 100   70 60
        
        ** In this we need to remove 20 from maintain Binary Heap..
            1) We swap 20 with the last node that is 60, and do size--;
            2) and now call the MinHeapify for 60 which is now root.. in this, it check it's left and right children..

                              25
                            /    \
                           35     30
                         /   \   /  \
                        60   40 80  32
                      /   \                 //  Here 20 is extract and called the MinHeapify for 60..
                    100   70 

    */    

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
};


int32_t main(){
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);

    cout << h.extractMin() << endl;
    
    return 0;
}

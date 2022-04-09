/*

Binary Heap DS :-
    ** Used in HeapSort..
    ** Used to "implement Priority Queue".. used in distrakght shortest path Algo, Prims Minimum spanning tree Algo, Halfman coding ..
    ** For Ex., Doctor queue it based on priority..
    ** Two type :-
        1) Min Heap     (Highest Priority item is assigned lowest value.. which remains on top of queue)
        2) Max Heap     (Highest Priority item is assigned highest value.. which remains on top of queue)
    
    ** Binary heap is complete binary tree which should filled completely and except the last level 
        is partially filled, but it should be filled from left to right..(which should not have gaps from left to right..)

    **** Binary Heap is a Complete Binary tree  (stored as an array..)
    Ex.,                        10
                              /    \
                            20      30
                          /    \    /
                        40     50  60
    
    Index :-   0  1   2   3   4   5 
    O/p :-    10  20  30  40  50  60  

    A complete Binary Tree and it's 'array representation'..

*** Identifing values using indexs..
        left(i)   = 2(i) + 1
        right(i)  = 2(i) + 2
        parent(i) = floor((i-1)/2)

Ex.,  left(1) = 2(1) + 1 = 3 on index of node is left of 1st index's node..
      right(1) = 2(1) + 2 = 4 on index of node is right of 1st index's node..

    Advantages :-   
        1) Random accessing of item.. and stored in contingous.. and without wasting space..
        2) Cache friendly..
        3) It's a completely binary tree, so height of tree is minimum possible which means heapify.. or insert on binary heap..

****   Min Heap DS :-   
    1) Complete Binary tree,
    2) Every node has value smaller than it's descendent.. which means "it's child should be greater than it"..

                            10              {Here 10 is smaller than all it's descendent..}
                          /    \
                        20      15          {Similiar 20 and 15 also..}
                      /   \     /
                    30    40   18
            
    index   :-            0   1   2   3   4   5
      O/p   :-            10  20  15  30  40  18

    ** Min heap is internal representated as array..    left, right, parent..
Ex., 
                    10
                  /   \  
                20    30
                     /
                    40  
        This is not an Completely Binary tree..

                    30
                  /    \ 
                40      50
               /
             15
        This a Completely binary tree but it's doesn't follow second condition -> Every node has value smaller than it's descendent
*/ 

/*
    Heap Implemtation :-
        ** If we want create heap with out library then, we need to know the capacity and size of array..
        ** size <= capacity

        class Minheap{
            int []ar;
            int size;
            int capacity;

            Minheap(int c){
                ar = new int[c];
                size = 0;
                capacity = c;
            }

            int left(int i)     return 2(i) + 1;        //   Base Functions..
            int right(int i)    return 2(i) + 2;
            int parent(int i)   return floor((i - 1)/2); 

Binary Heap Insert  :-
    In this, implements the insertion method of Binary Heap..

      ** Consider that we are using MinHeap  :-    We stop the condition when cur node is greater 
                                                    than it's parent (or) we are at root of tree..

            void insert(int x){             //  TC -> O(log (size of tree..))
                if (size >= capacity){
                    return;
                }
                size++, ar[size-1] = x;     //  increasing size and inserting on the last node position..

                for (int i = size-1; i != 0 && ar[i] < ar[parent(i)];){
                    swap(ar[i], ar[parent(i)]);
                    i = parent(i);
                }
            }
        };      

    Ex.,                    
                             10
                          /     \
                         20      15
                       /   \    /   \
                      40   50  100   25
                    /
                   45   
    Insert(12)..

                             10
                          /     \
                         20      15
                       /   \    /   \
                      40   50  100   25             
                    /   \   
                   45   12                  //  Here 12 is added at last node of tree which follow Binary tree.. and size++..

                             10
                          /     \
                         20      15
                       /   \    /   \
                      12   50  100   25
                    /   \
                   45   40              //  Here we check with it's parent which is greater than we swap both..

                             10
                          /     \
                         12      15         //  Here again swap with 20 and we can see than 10 is smaller than 12 then we stop..
                       /   \    /   \
                      20   50  100   25
                    /   \
                   45   40        

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
};

int32_t main(){
  MinHeap h(11);
  
  h.insert(3);
  h.insert(2);
  h.insert(15);
  h.insert(20);
  
  return 0;
}


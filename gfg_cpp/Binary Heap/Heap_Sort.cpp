/*

Heap Sort   :- The Basic idea of heap sort is Selection sort Algo.. 
    1) In Selection sort we use linear search to find the maximum element, and swap with the last element.. which takes O(n^2)..
    2) Heap sort is upgrade version of Heap sort and in this we use MaxHeap DS instead of Linear search..   which takes O(n Logn)..

Working of Heap Sort with implementation :-
    1) Build max Heap from the random array.. TC -> O(n)..
    2) We swap the last element with root node.. we get the max element which is similiar to selection sort..
    3) After that we do Heapify.. when subtrees are heapify but root is not..

Ex.,    [10, 15, 50, 4, 20]                                             [50, 20, 10, 4, 15]
                10                                 10                           50
               /  \                              /    \                       /    \
              15   50               ->          20    50        ->           20    10
            /   \                             /   \                         /  \
           4    20                           4    15                       4   15
    ** Convert the Binary tree to max Heap..  If we want to sort the array in increase we use max heap..
         in case of decreasing order we use min heap..
    
        Bulid a Max Heap    :-
            1) In this we call the 'BulidHeap' for the array from the internal node of tree.. upto 0 and call 
                the max heapify..
            2) Max heapify means which takes max of parent, left, right among them and swap with it..
            3) And we recursive call the max Heapify for the swapped node..
            4) Until we reached the leaf..


Ex.,    [10, 15, 50, 4, 20]                                             [50, 20, 10, 4, 15]
                10                                 10                           50
               /  \                              /    \                       /    \
              15   50               ->          20    50        ->           20    10
            /   \                             /   \                         /  \
           4    20                           4    15                       4   15

    ** In this we can see that call the max heapify(1).. and next max heapify(0)..
    ** We get max node of the tree..

    [50, 20, 10, 4, 15] 
            50                                          15                              20
          /   \     swap(ar[0], ar[4])                /    \     Heapify(0)           /    \   swap(ar[0], ar[3])    
         20   10        -------------->              20    10    ---------->        15     10  --------------->
       /  \        remove ar[4] from heap           /  `.                         /             remove ar[3] from heap
      4    15                                      4    50                       4

        4                                   15                                          10          Heapify(0)      10                                                  ->        [4]
      /   \         Heapify(0)            /   \        swap(ar[0], ar[2])              /  `.        -------->      /     -> swap(ar[0], ar[1]), remove ar[1] from Heap.         remains..
     15    10      ----------->          4     10       ---------->                   4     15                    4 
    .'                                                  remove ar[2] from Heap..
    20

        Time Complexity :-
             Heap       ->  O(n Logn).. in all cases.
            Merge sort  ->  O(n Logn).. in wrost case.
            Quick sort  ->  O(n Logn).. in average case.

        ** The constants hidden in Heap sort algo is higher than Merge, quick..
        ** Intro sort which is Hybrid algo. uses quick sort and in wrost case uses Heap sort..
        ** Heap is Mainly used for Helper sorting algorithm in Hybrid algo..
*/ 

#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int ar[], int n, int i){        //  TC -> O(log n)..
    int largest = i, left = (i*1)+2, right = (i*2)+2;

    if (left < n and ar[left] > ar[i]){
        largest = left;
    }
    if (right < n and ar[right] > ar[largest]){
        largest = right;
    }

    if (largest != i){
        swap(ar[largest], ar[i]);
        maxHeapify(ar, n, largest);
    }
}

void bulidHeap(int ar[], int n){         //     TC -> O(n)..
    for (int i=(n-2)/2; i>=0; i--){      //  parent of last internal node is ((n-1) -1)/2;
        maxHeapify(ar, n, i);
    }
}
//      Now we swap the largest element to last element, second largest element to second last element..
//  ** Repeatedly swap root with last node, reduce heap size by one, and heapify..

void heapSort(int ar[], int n){     //  TC -> O(n logn)..
    bulidHeap(ar,n);
    for (int i=n-1; i>=1; i--){
        swap(ar[0], ar[i]);
        maxHeapify(ar, i, 0);
    }
}

void printHeap(int ar[]){
    for (int x: ar){
        cout << x << " ";
    }cout << endl;
}

int32_t main(){
    int ar[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(ar)/sizeof(ar[0]);

    heapSort(ar, n);
    printHeap(ar);

    return 0;
}
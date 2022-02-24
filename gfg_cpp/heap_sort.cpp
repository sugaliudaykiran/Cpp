/*
    Heap Sort :- The Basic Idea of the Heap sort is Selection sort..
                In Selection Sort we basic do first find the Maximum element and swap with the Last element..
                and in Selection Sort we do linear Search for Searching so.. it Takes TC --> O(N_square)..

                But In heap sort we use the Selection sort but, we use Heapify for finding the Maximum element 
                instead of Linear search.. Which Takes TC --> O(N)..

                In the Heap Sort :-
                1) Takes the array and we restructure into Max-Heap or Min-Heap {Decresing Order}..
                2) for the Incresing Order we Use Max-Heap..  We swap the last element with root of the Max-Heap..
                3) and repate.. Using Heapify we sort all elements..

    Merge sort -> O(N_logN) in worst case..
    Quick Sort -> O(N_logN) in Average case..
    Heap sort  -> O(N_logN) in All the cases.. used in Intro Sort..
*/

#include<bits/stdc++.h>
using namespace std;

// ** Step -1) Build a Max - Heap..
void max_heapify(int ar[], int n, int i){
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && ar[left] > ar[largest]){
        largest = left;
    }
    if (right < n && ar[right] > ar[largest]){
        largest = right;
    }
    if (largest != i){
        swap(ar[largest], ar[i]);
        max_heapify(ar, n, largest);
    }
}
// Building an Heap..               TC --> O(N)..
void build_Heap(int ar[], int n){
    for (int i = (n-2)/2; i >= 0; i--){         // For the Parent of the Last Node :- (n-1) and for the parent of this is (N-2)/2
        max_heapify(ar, n, i);                 // for parent of i is | (i-1)/2 | and parent of N-1 is ((N-1)-1)/2.. --> (N-2)/2
    } 
}

// ** Step -2) Repatedly Swap root with last node, "reduce Heap size by one", and Heapify..
void heapSort(int ar[], int n){         // TC --> O(N_LogN).. In all cases..
    build_Heap(ar, n);
    for(int i=n-1; i>=1; i--){      // Upto Index 1..
        swap(ar[0], ar[i]);
        max_heapify(ar, i, 0);  // Always assumes that first element as Largest..element..
    }
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    heapSort(ar, n);

    for (int s: ar){
        cout << s << " ";
    }
    return 0;
}



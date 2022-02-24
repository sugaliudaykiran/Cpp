/*
    Insertion sort :=  worst case is O(N_square)
    In-place (Doesn't required any AS..)and stable (which follows order in the case of similar element..)
    Used in practice for small arrays (Tim_Sort -> Hybrid of Merge sort and insertion sort used in python..) 
                                      **(Intro_Sort -> Hybrid of quick sort and heap sort and insertion sort..)
    Takes O(N) in best case..

    Idea of the Insertion sort is array is divides in left side sorted and right side is Unsorted..
    It is start from the index 1 to and assuming the first index is sorted..and compare the it further and gets the sorted array..
*/
    // TC --> In best case is O(N).. and In case of the worst case is 0(N_square)..
#include<bits/stdc++.h>
using namespace std;

void i_s(int ar[], int n){
    for (int i=1; i<n; i++){        // TC -> 0(N_square..)
        int key = ar[i];
        int j = i-1;

        while (j >= 0 && ar[j] > key){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    i_s(ar, n);

    for (int m : ar){
        cout << m << " ";
    }
    return 0;
}
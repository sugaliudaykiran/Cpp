/*
    Selection sort := It is an 0(N_square)..Algorithm..
    Does less memory writes compared to Quick sort,  Merge sort, Insertion sort ,,but is not optimal..
    The Best Optimal one is Cycle sort in terms of the memory write..
    Selection sort is an basic idea for the heap sort 
    It is an "not stable" (order of the equal elements may change..) and it is also an "In place" (does not requires more space..)

*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int ar[], int n){
    int temp[n];

    for (int i=0; i<n; i++){
        int min_idx = 0;
        for (int j=1; j<n; j++){
            if (ar[j] < ar[min_idx]){
                min_idx = j;
            }
        }
        temp[i] = ar[min_idx];
        ar[min_idx] = INT_MAX;
    }

    for (int i=0; i<n; i++){
        ar[i] = temp[i];
    }
}

// In-place Implementation :=   Does not required temparory storage here.. {And it is an Not stable..form}
void in_place(int ar[], int n){
    for (int i=0; i<n-1; i++){
        int min_idx = i;
        for (int j = i+1; j<n; j++){        // TC --> 0(N_square)..
            if (ar[j] < ar[min_idx]){   //  (n-1) + (n-2) + ... + 2 + 1 => (n(n-1))/2 ==> 0(N_square)..
                min_idx = j;
            }
        }
        swap(ar[min_idx], ar[i]);
    }
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    //selection_sort(ar, n);
    in_place(ar, n);

    for (int x : ar){
        cout << x << " ";
    }
    return 0;
}
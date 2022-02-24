// Search in Infinite Sized Array ---> Which also Known as Un-bounded Binary Search..
// Given an infinite sized array, we need to write an efficient solution to search an element. In this video, we have discussed two solutions.

#include<bits/stdc++.h>
using namespace std;

// Navie_Solution :-    Position => Index +1;       TC --> O(position)..
int search_i(int ar[], int n, int k){
    int i = 0;
    while(true){
        if (ar[i] == k){
            return i;
        }
        else if (ar[i] > k){
            return -1;
        }
        i++;
    }
}


// Efficient-Solution :-        TC -> O(Log_position)..
// Using Binary_Search :-
int binary_search(int ar[], int low, int high, int k){
    while (low <= high){
        int mid = (low + high) /2;
        if (ar[mid] == k){
            return mid;
        }
        else if (ar[mid] > k){
            high = mid-1;
        }
        else{
            low = mid +1;
        }
    }
    return -1;
}

// Here searching the element..
int s_i(int ar[], int n, int k){
    if (ar[0] == k){        // here we check the first element is equal to 'k'..
        return 0;
    }
    int i=1;                // we start i from 1 because of the iteration will jumps by multiple of 2..
    while (ar[i] < k){      // in case of element should be less than 'k'..
        i = i * 2;
    }
    if (ar[i] == k){        // check if equal...
        return i;
    }                           // Else Binary_search by low = i/2 +1, high = i-1..because of the range will in between that..
    return binary_search(ar, i/2 +1, i-1, k);
}



int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << search_i(ar, n, k);
    cout << s_i(ar, n, k);
    return 0;
}
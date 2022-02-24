// Index of first Occurrence in Sorted
// Given a sorted array with repetition and an element k, we need to find index of first occurrence of k.

#include<bits/stdc++.h>
using namespace std;

// # Using Recursion :-    TC --> O(Log_N..base_2)..
int first_index(int ar[], int low, int high, int k){
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if (ar[mid] < k){
        return first_index(ar, mid+1, high, k);
    }
    else if (ar[mid] > k){
        return first_index(ar, low, mid-1, k);
    }
    else{
        if (mid == 0 || ar[mid - 1] != ar[mid]){
            return mid;
        }
        else{       // In this Case we again use the left - side recursion.. and check if it is first_occurance..
            return first_index(ar, low, mid-1, k);
        }
    }
}

// # using iterative_Solution :=
int get_first_I(int ar[], int low, int high, int k){
    while (low <= high){
        int mid = (low + high)/2;
        if (ar[mid] > k){
            high = mid - 1;
        }
        else if (ar[mid] < k){
            low = mid + 1;
        }
        else{
            if (ar[mid] == 0 || ar[mid - 1] != ar[mid]){
                return mid;
            }
            else{   // In this Case we again use the left - side iteration.. and check if it is first_occurance..
                high = mid - 1;
            }
        }
    }
    return -1;
}


int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    int low = 0, high = n-1;

    // cout << first_index(ar, low, high, k);
    cout << get_first_I(ar, low, high, k);
    return 0;
}

// Count 1s in a Sorted Binary Array
// Given a sorted binary array, we need to count 1s in this array. This video talks about two solutions.

// Navie-Solutio is travers to the array and which is sorted and when we find the first time and we subtract the (Length of Array - Index of first_occurance)..
// (Length of Array - Index of first_occurance of the key)..

#include<bits/stdc++.h>
using namespace std;

// Using Binary_search :- TC --> O(log_N) and AS --> O(1)..
int count_1(int ar[], int n){
    int low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (ar[mid] == 0){
            low = mid+1;
        }
        else{
            if (mid == 0 || ar[mid -1] == 0){
                return (n-mid);
            }
            else{
                high = mid-1;
            }
        }
    }
    return 0; 
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << count_1(ar, n);
    return 0;
}
// Index of last Occurrence in Sorted
// Given a sorted array with repetition and an element x, we need to find index of last occurrence of x.

#include<bits/stdc++.h>
using namespace std;

// Navie_Solution is iterating the loop from right to left and checking the element is found and return it..

// Recursion - Solution :-  TC --> O(Log_N) and AS --> O(Log_N)..

int l_o(int ar[], int low, int high, int n, int k){
    if (low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if (ar[mid] > k){
        return l_o(ar, low, mid-1, n, k);
    }
    else if (ar[mid] < k){
        return l_o(ar, mid+1, high, n, k);
    }
    else{
        if (mid == n-1 || ar[mid] != ar[mid+1]){
            return mid;
        }
        else{               // In case of the last_occurance we go to the right_half..
            return l_o(ar, mid+1, high, n, k);
        }
    }
}

// Iteration-Solution :-        TC --> O(log_N).. and AS --> O(1)..
int l_s(int ar[], int low, int high, int n, int k){
    while(low <= high){
        int mid = (low+high)/2;

        if (ar[mid] > k){
            high = mid-1;
        }
        else if (ar[mid] < k){
            low = mid+1;
        }
        else{
            if (mid == n-1 || ar[mid +1] != ar[mid]){
                return mid;
            }
            else{
                low = mid+1;
            }
        }
    }
    return -1;
}

int32_t main(){

    int n, k;
    cin >> n >> k;

    int ar[n];
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }

    int low = 0, high = n-1;

    //cout << l_o(ar, low, high, n, k);
    cout << l_s(ar, low, high, n, k);
}
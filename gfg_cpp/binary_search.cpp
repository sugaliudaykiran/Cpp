#include<bits/stdc++.h>
using namespace std;
 
// Navie-Solution :-        |   Linear_Solution :-  TC --> O(N) and AS -> O(1)..  |
int b_s(int ar[], int n, int k){
    for(int i=0; i<n; i++){
        if (ar[i] == k){
            return i;
        }
    }
    return -1;
}

// Binary-Solution :-  Array is Sorted..        TC --> O(log N).. AS -> O(1)..
int b_ss(int ar[], int low, int high, int k){
    // int n = sizeof(ar) / sizeof(ar[0]);
    while(low <= high){
        int mid = (low + high)/2;
        if (ar[mid] == k){
            return mid;
        }
        else if (ar[mid] > k){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

// Recursive_Binary_Search :- TC --> O(log N).. AS -> Extral_space than iteration..O(log_N)
int b_sr(int ar[], int low, int high, int k){
    // Base-case..
    if (low > high){
        return -1;
    }
    
    int mid = (low+high)/2;
    if (ar[mid] == k){
        return mid;
    }
    else if (ar[mid] > k){
        b_sr(ar, low, mid-1, k);
    }
    else{
        b_sr(ar, mid+1, high, k);
    }
}

/*
    Height of the binary_search of the successful search in iterative is ceil of (log_N.. Base 2)..
                                and the unsuccessful search is also same..

*/

int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int low = 0, high = n-1;

    // cout << b_s(ar, n, k);
    // cout << b_ss(ar, low, high, k);
    cout << b_sr(ar, low, high, k);
    return 0;
}
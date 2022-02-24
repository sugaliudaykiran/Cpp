// Search in Sorted Rotated Array
// This talks about O(Log n) approach to search an element in a sorted and rotated array.

#include<bits/stdc++.h>
using namespace std;

// Navie-Solution :-    TC --> O(N).. AS -> O(1)..
int s_r(int ar[], int n, int k){
    for (int i=0; i<n; i++){
        if (ar[i] == k){
            return i;
        }
    }
    return -1;
}

// Efficient-Solution :-        TC --> O(Log_N) and AS --> O(1)..
int b_s(int ar[], int n, int k){
    int low = 0, high = n-1;

    while (low <= high){
        int mid = (low + high)/2;
        if (ar[mid] == k){
            return mid;
        }
        if (ar[mid] > ar[low]){     // First Check left half is sorted ..
            if (k >= ar[low] && k < ar[mid]){   // Check will first element.. and it should be less than Mid_element..
                high = mid-1;       // Check with the left half upto the mid..
            }
            else{
                low = mid+1;        // Check the right half of updated mid..
            }
        }
        else{                       // In this case right half is sorted..
            if (k > ar[mid] && k <= ar[high]){
                low = mid+1;        // this case right half and check the right half..
            }
            else{                   // check the left-half of the updated of mid..
                high = mid -1;
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

    // cout << s_r(ar, n, k);
    cout << b_s(ar, n, k);
    
    return 0;
}
// Count Occurrences in Sorted
// Given a sorted array and an element x, we need to count occurrences of x in the array.

#include<bits/stdc++.h>
using namespace std;

int first_occ(int ar[], int n, int k){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low + high)/2;
        
        if(ar[mid] > k){
            high = mid-1;
        }
        else if (ar[mid] < k){
            low = mid+1;
        }
        else{
            if (mid == 0 || ar[mid] != ar[mid-1]){
                return mid;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int last_occ(int ar[], int n, int k){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low + high)/2;
        
        if(ar[mid] > k){
            high = mid-1;
        }
        else if (ar[mid] < k){
            low = mid+1;
        }
        else{
            if (mid == n-1 || ar[mid] != ar[mid+1]){
                return mid;
            }
            else{
                low = mid+1;
            }
        }
    }
    return -1;
}

int count_occ(int ar[], int n, int k){  // TC --> O(Log_N)..
    int first  = first_occ(ar, n , k);
    if (first == -1){
        return 0;
    }
    else{           // when first and last occurance of 'K' for freq of we can do (last_occ - first_occ +1);
        return (last_occ(ar, n, k) - first +1);
    }
}


int32_t main(){

    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << count_occ(ar, n, k);

    return 0;
}
// Allocate Minimum Pages (Binary Search)..

#include<bits/stdc++.h>
using namespace std;

bool is_feasible(int ar[], int n, int k, int ans){
    int req = 1, sum = 0;           // starting from including the 1 person of the k..
    for (int i = 0; i<n; i++){          
        if (sum + ar[i] > ans){         // checking the condition..
            req++;
            sum = ar[i];
        }
        else {
            sum += ar[i];           // if not increment to the sum..
        }
    }
    return (req <= k);          // is true or false..
}
                                        // TC --> O(n * Log (sum-mx)).. => O(n * Log(sum))..
int minpages(int ar[], int n, int k){
    int sum = 0, mx = 0;

    for (int i=0; i<n; i++){
        sum += ar[i];               // Total Sum of array..
        mx = max(mx, ar[i]);        // Max of array..
    }

    int low = mx, high = sum, res = 0;      // Taking low from max, and high upto sum...
    while (low <= high){
        int mid = (low+high)/2;         
        if (is_feasible(ar, n, k, mid)){       // Checking the condition..         
            res = mid;
            high = mid -1;                      // for the minimize the res..and moving toward the left_side..
        }
        else{
            low = mid+1;                    // moving toward the right_side..
        }
    }
    return res;
}


int32_t main(){
    int n, k;
    cin >> n >> k;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << minpages(ar, n, k);
    return 0;
}
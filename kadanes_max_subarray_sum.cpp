#include<bits/stdc++.h>
#include<climits>
using namespace std;

int kadanes(int ar[], int n){
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i=0; i<n; i++){
        currentSum += ar[i];
        if (currentSum < 0){
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    cout << maxSum << endl;
}

int32_t main(){
    int n;
    cin >> n;
    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }
    
    // int currentSum[n+1];
    // currentSum[0] = 0;

    // for (int i=1; i<=n; i++){
    //     currentSum[i] = currentSum[i-1] + ar[i-1];
    // }
    // int maxSum = INT_MIN;
    // for (int i=1; i<=n; i++){
    //     int sum = 0;
    //     for (int j=0; j<i; j++){
    //         sum = currentSum[i] - currentSum[j];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // cout << maxSum << endl;

    kadanes(ar, n);
    return 0;
}
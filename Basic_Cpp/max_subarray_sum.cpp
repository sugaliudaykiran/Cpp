#include<bits/stdc++.h>
#include<climits>
using namespace std;

int Subarray_pattern(int ar[], int n){
    int maxSum = INT_MIN;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            int sum = 0;
            for (int k=i; k<=j; k++){
                sum += ar[k];
                // cout << ar[k] << " ";
            }// cout << endl;
        maxSum = max(maxSum, sum);
        }
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
    Subarray_pattern(ar, n);
    return 0;
}
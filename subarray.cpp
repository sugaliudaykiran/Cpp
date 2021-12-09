#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cout << "n : ";
    cin >> n;

    int ar[n];

    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    int current_sum = 0;
    cout << "Sub_array : " << endl;
    for(int i=0; i<n; i++){
        current_sum = 0;
        for(int j=i; j<n; j++){
            current_sum += ar[j];
            cout << current_sum << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
Subarray :- continuous part of the array..
=>  no of subarray of an array with n elements :- nc2 + n --> (n * (n+1))/2 ;
=>  Every subarray is a Subsequence but every Subsequence is not a Subarray.
*/
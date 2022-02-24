#include<bits/stdc++.h>
using namespace std;

int unique_num(int ar[], int n){
    int xor_sum = 0;
    for (int i=0; i<n; i++){
        xor_sum = xor_sum ^ ar[i]; // xor => 0 ^ 1 -> 1 or 1 ^ 0 -> 1 ;
    }
    return xor_sum;
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    cout << unique_num(ar, n) << endl;

    return 0;
}
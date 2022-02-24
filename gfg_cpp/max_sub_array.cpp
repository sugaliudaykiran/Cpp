#include<bits/stdc++.h>
using namespace std;

// Navie_Solution :-        TC --> O(N_square)
int MSA(int ar[], int n){
    int res = 0;
    for (int i=0; i<n; i++){
        int cur = 0;
        for (int j=i; j<n; j++){
            cur += ar[j];
            res = max(cur, res);
        }
    }
    return res;
}

//  Efficient_Solution :-       TC --> O(N)..
int MSAs(int ar[], int n){
    int res = ar[0];
    int max_ending = ar[0];

    for (int i=1; i<n; i++){
        max_ending = max(max_ending + ar[i], ar[i]);
        res = max(res, max_ending);
    }
    return res;
}


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << MSA(ar, n);
    cout << MSAs(ar, n);
    return 0;
}
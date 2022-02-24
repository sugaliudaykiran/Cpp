#include<bits/stdc++.h> 
using namespace std;
// Navie - Solution..
void only_odd(int ar[], int n){     //  TC --> 0(N_square)
    
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=0; j<n; j++){
            if (ar[i] == ar[j]){
                count++;
            }
        }
        if (count % 2 != 0){
            cout << ar[i] << endl;
        }
    }
}
// Efficient-Solution :=            TC --> 0(N) and AS --> 0(1)..
void only_odds(int ar[], int n){
    int res = 0;
    for (int i=0; i<n; i++){    // TC --> 0(N)
        res ^= ar[i];
    }
    cout << res << endl;
}
/*
    Xor --> is mostly used like...
    example -->  x ^ 0 --> x;
            **   x ^ y --> y ^ x;
                (x ^ y) ^ z --> x ^ (y ^ z);
            **   x ^ x --> 0;
*/

// Variation-Question :-- Find the Missing number of array and values in range of [1 to n+1]..

void Vq(int ar[], int n){
    int res = 0;
    int arr[n+1];

    for (int i=1; i<=n+1; i++){
        arr[i] = i;
        res ^= arr[i];
    }

    for(int i=0; i<n; i++){
        res ^= ar[i];
    }
    cout << res << endl;
}
// Solution by From  (Xor_[ 1 to N+1 ])  ^ (Xor_[ar[0]..ar[N-1])...
// These depends on Only N. Tc --> O(N)


int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // only_odd(ar, n);
    // only_odds(ar, n);
    Vq(ar, n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int sums(int n){        // TC --> 0(N)..        AS --> 0(N)..
    if (n == 0){
        return;
    }
    return n + sums(n-1);   // for N sum we need sums(N-1) by this larger one we need to get the smaller one to it..
}

int32_t main(){
    int n;
    cin >> n;

    return 0;
}
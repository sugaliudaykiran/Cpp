// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max_pieces(int n, int a, int b, int c){     // TC --> 0(3_power_N);
    if (n == 0){
        return 0;
    }
    if (n < 0){
        return -1;
    }
    int res = max(max_pieces(n-a, a, b, c), max_pieces(n-b, a, b, c));
    res = max(res, max_pieces(n-c, a, b, c));
    
    if (res == -1){
        return -1;
    }
    res += 1;

    return res;
}

int32_t main(){
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << max_pieces(n, a, b, c) << endl;

    return 0;
}
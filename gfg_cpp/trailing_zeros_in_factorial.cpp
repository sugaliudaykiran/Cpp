#include<bits/stdc++.h>
using namespace std;

// TC --> 0(n);
int trailing_zeros(int n){
    int fact = 1;
    for (int i = 2; i<=n; i++){
        fact *= i; 
    }
    int res = 0;
    while (fact % 10 == 0){
        res++;
        fact /= 10;
    }
    return res;
}

// Efficient-method :- 
// 1 2 3 4 |5| 6 7 8 9 10..15..21 22 .. |25|.. 100..|125|  -> 5 is 1 time, 25 is 2 time of 5, 125 is 3 time .. andsoon
// TC -> 0(logN)  --> k = log5(N)--> 0(logN)..
int trailing_zeros2(int n){
    int res = 0;
    for (int i=5; i<= n; i*=5){ // start from i = 5...and increment of 5 times..
        res = res + (n/i);
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
    // cout << trailing_zeros(n) << endl; // not workes on high values..
    cout << trailing_zeros2(n) << endl; // for more value like ..200..251..300..
    return 0;
}
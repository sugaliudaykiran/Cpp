#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return (n * fact(n-1));
}

// N th Fibonacci Number  where N >= 0..
int fib(int n){
    if (n <= 1){
        return n;
    }               // 0 1 1 2 3 5 8 13  if N is 5 then ans -> 5.. if N is 3 --> 2..
    return fib(n-1) + fib(n-2);
}
// fails if it goes segment-fault..

int32_t main(){
    int n;
    cin >> n;
    
    cout << fact(n) << endl;
    cout << fib(n) << endl;
    return 0;
}
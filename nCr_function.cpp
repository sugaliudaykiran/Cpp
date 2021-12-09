#include<bits/stdc++.h>
using namespace std;

int fact(int N){
    int factorial = 1;

    for(int i = 2; i <= N; i++){
        factorial *= i;
    }
    return factorial;
}

int32_t main(){
    int n,r;
    cout << "n, r : ";
    cin >> n >> r;

    int ans = fact(n) / (fact(r)*fact(n-r));
    cout << "nCr : "<< ans << endl;

    return 0;
}
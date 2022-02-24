#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if (n == 0)         // Base Condition..
        return 0;
    int prev_sum = sum(n-1);
    return n + prev_sum;
}


int32_t main(){
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}
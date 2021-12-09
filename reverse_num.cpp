#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;
    int reverse = 0, lastnum = 0;

    while(N > 0){
        lastnum = N % 10;
        reverse = reverse * 10 + lastnum;
        N = N / 10;
    }
    cout << "reverse : ";
    cout << reverse << endl; 

    return 0;
}
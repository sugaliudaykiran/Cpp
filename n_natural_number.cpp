#include<bits/stdc++.h>
using namespace std;

int n_natural(int N){
    return ((N * (N+1))/2);
}


int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    int x = n_natural(N);
    cout << "natural_numbers_upto_N : ";
    cout << x << endl;

    return 0;
}
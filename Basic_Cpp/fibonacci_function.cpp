#include<bits/stdc++.h>
using namespace std;

void fib(int n){
    int first_ele = 0;
    int secound_ele = 1;
    int next_ele = 0;

    for (int i = 1; i <= n; i++){
        cout << "\t" << first_ele << endl;
        next_ele = first_ele + secound_ele;
        first_ele = secound_ele;
        secound_ele = next_ele;
    }
    return;
}

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    fib(N);
    return 0;
}
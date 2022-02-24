#include<bits/stdc++.h>
using namespace std;

int fact(int N){
    int factorial = 1;

    for (int i = 2; i <= N; i++){
        factorial *= i;
    }
    return factorial;
}



int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            cout << fact(i) / (fact(j) * fact(i-j)) << " ";
        }
        cout << endl;
    }
    return 0;
}
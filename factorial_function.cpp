#include<bits/stdc++.h>
using namespace std;

int fact(int N){
    int facts = 1;

    for (int i = 2; i<= N; i++){
        facts *= i;
    }
    cout << "Factorial is : " << facts << endl;
}

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    fact(N);
    return 0;
}
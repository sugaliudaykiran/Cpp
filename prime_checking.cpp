#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;
    bool flag = 0;

    for (int i = 2; i < sqrt(N); i++){
        if (N % i == 0){
            cout << "Non-Prime No.";
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        cout << "Prime No.";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    // for (int i = N; i >= 1; i--){
    //     for (int j = 1; j <= i; j++){
    //         cout << j <<" ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N+1-i; j++){
            // for colums here N + 1 -i(for each row..)
            cout << j <<" ";
        }
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    for (int i = 1; i <= N; i++){
        // for space j goes for N-i ...
        for(int j = 1; j <= N-i; j++){
            cout << "  ";
        }
        for (int k = 1; k <= N; k++){
            cout << "* "<< " ";
        }
        cout <<endl;
    }
    return 0;
}
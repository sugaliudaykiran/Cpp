#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;


    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            cout << "*" << " ";
        }
        // space will be 2 * N - 2 * i;
        int space = (2 * N) - (2 * i) ;
        
        for (int k = 1; k <= space; k++){
            cout << "  " ;
        }

        for (int j = 1; j <= i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }

    for (int i = N; i >= 1; i--){
        for (int j = 1; j <= i; j++){
            cout << "*" << " ";
        }
        // space = 2 * N - 2 * i;
        int space = (2 * N) - (2 * i) ;
        
        for (int k = 1; k <= space; k++){
            cout << "  ";
        }
        for (int j = 1; j <= i; j++){
            cout << "*" << " ";
        }cout << endl;
    }
    return 0;
}
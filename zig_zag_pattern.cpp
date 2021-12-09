#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";     // N = 9;
    cin >> N;

    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= N; j++){
            if ((i+j)% 4 == 0){                 // sum(i,j) % 4 == 0 
                cout << "* " ;
            }
            else if (i == 2 && j % 4 == 0){     // row = 2 and column no. % 4 == 0
                cout << "* " ;
            }
            else{                               // remainder will be space.
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
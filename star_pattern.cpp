#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout <<"N : ";
    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N-i; j++){
            cout << "  ";
        }
        for (int k = 1; k <= 2*i - 1; k++){     // element_count = 2 * row_no - 1 (gives 1,3,5,7 [odd_Numbers])
            cout << "*" << " ";
        }
        cout << endl;
    }

    for (int i = N; i >= 1; i--){
        for (int j = 1; j <= N-i; j++){
            cout << "  ";
        }
        for (int k = 1; k <= 2*i - 1; k++){
            cout << "*" <<" ";
        }
        cout << endl;

    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "Enter the N_value : ";
    cin >> N;

    for (int i=1; i <= N; i++){
        for (int j=1; j <= N; j++){
            if (j <= N-i){
                cout << "  ";
            }
            else{
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}
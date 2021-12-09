#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    for (int i = 1; i <= N; i++){          
        for (int k = 1; k <= N-i; k++){     // space = upto N - i
            cout <<" ";
        }
        for (int j = 1; j <= i; j++){       // element = upto i
            cout << j << " ";
        }cout << endl;
    }

    return 0;
}
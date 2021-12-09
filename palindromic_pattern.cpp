#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    for (int i = 1; i <= N; i++){
        int j;
        for (j = 1; j <= N-i; j++){         // space = 1 to n - row no.
            cout << " ";
        }
        int k = i;
        for (; j <= N; j++){                // k = row no. and k--
            cout << k-- << " ";             // n - row no. to n
        }
        k = 2;
        for (; j <= N+i-1; j++){            // k = from '2' and k ++
            cout << k++ << " ";             // n to n+i - 1;
        }cout << endl;
    }

    return 0;
}
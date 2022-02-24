#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;
    int count = 1;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            cout << count << " ";
            count++;

        }
        cout << endl;
    }
    return 0;
}


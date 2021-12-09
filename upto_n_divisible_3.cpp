# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cin >> N;

    for (int i = 1;i <= N; i++){
        if (i % 3 == 0){
            continue;
        }
        cout << i << endl;
    }
}
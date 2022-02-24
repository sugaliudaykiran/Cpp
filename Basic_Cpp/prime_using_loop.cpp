# include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cin >> N;
    int i;

    for(i=2; i < N; i++){
        if (N % i == 0){
            cout << "NOT an Prime Number."<<endl;
            break;
        }
    }
    if (i == N){
        cout << "YES an Prime Number." << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#include<climits>
using namespace std;

int32_t main(){
    int n;
    
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // const int N = 1e6 +2;
    int N = 100;   // 1e6 --> 10 to power 6. 
    int idx[N];
    for (int i=0; i<N; i++){
        idx[i] = -1;
    }

    int Minidx = INT_MAX;

    for (int i=0; i<n; i++){
        if (idx[ar[i]] != -1){
            Minidx = min(Minidx, idx[ar[i]]);
        }
        else{
            idx[ar[i]] = i;
        }
    }

    if (Minidx == INT_MAX){
        cout << "-1" << endl;
    }
    else{
        cout << Minidx +1<< endl;
    }
    return 0;
}
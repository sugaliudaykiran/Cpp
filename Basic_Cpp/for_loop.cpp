#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int N;
    cin >> N;
    int sum = 0;
    // sum of N terms...
    
    for(int i=1; i <= N; i++){
        sum = sum + i;
    }

    cout << sum << endl;

    return 0;
}
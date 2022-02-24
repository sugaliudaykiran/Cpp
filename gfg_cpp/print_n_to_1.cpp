// Using Recursion...
#include<bits/stdc++.h>
using namespace std;
//                      TC --> T(N) = T(N-1) + 0(1)..  AS --> 0(N)
void N_upto1(int n){
    if (n == 0){
        return;
    }
    cout << n << " ";
    N_upto1(n-1);
}

int32_t main(){
    int n;
    cin >> n;
    
    N_upto1(n);
    return 0;
}
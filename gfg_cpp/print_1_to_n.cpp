#include<bits/stdc++.h>
using namespace std;

void print_1_toN(int n){    // TC --> T(N) = T(N-1) + 0(1).. AS --> 0(N)
    
    if (n == 0){
        return;
    }

    print_1_toN(n-1);

    cout << n << " ";

}

int32_t main(){
    int n;
    cin >> n;
    
    print_1_toN(n);

    return 0;
}
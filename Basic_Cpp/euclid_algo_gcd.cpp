#include<bits/stdc++.h>
using namespace std;

void gcd(int a, int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    cout << a << endl;
}

int32_t main(){
    int a, b;
    cin >> a >> b;
    gcd(a, b);
    return 0;
}
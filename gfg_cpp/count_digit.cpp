#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int digit, count = 0;
    cin >> digit;

    while(digit){
        ++count;
        digit /= 10;
    }
    cout << count << endl;

    return 0;
}

// Time Complexity -> 0(input) => Tetha..
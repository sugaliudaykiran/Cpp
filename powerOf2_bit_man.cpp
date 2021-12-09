#include<bits/stdc++.h>
using namespace std;
// Power of 2 using bit-manipulation..
bool powerof_2(int n){
    return (n && !(n & n-1)); // when n => is 0 then it is diffcult to get 0-1 value .. so (n && !(n & n-1));
}


int32_t main(){
    int n;
    cin >> n; // n => 6;
    cout << powerof_2(n) << endl; // ans => 0 which provide that n is power_of_2;

    return 0;
}

/*
n = 6 => 0110;
n-1 = 5 => 0101;
(n & n-1) has same bit as n "except" the right-most set bit..
means (6) n => 0 1 1 0 => 0 1 _ _ => will change to 0 1 0 1 will give n-1 (5) ;
0110 & 0101 => 0100;
n has only one set-bit, and n-1 will have all set bits after that position.. 
*/
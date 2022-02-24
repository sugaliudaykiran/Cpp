#include<bits/stdc++.h>
using namespace std;
// navie-solution...                TC --> 0(Total_bits_in_N)
void count_of_set_bit(int n){
    int res = 0;
    while(n){
        if (n & 1 == 1){    // n % 2 != 0  That is it will be Odd Number.. [Or] 
            res++;          // res += (n & 1); when it odd then it will add to res else won't..
        }
        n = n >> 1;         // n /= 2;
    }
    cout << res << endl;
}

// Brain Kerningam's Algorithm :-  Each iteration which turning the left-Most-set_bit.. 1--> 0
void BKA(int n){                   // 0(set-bit-count)..
    int res = 0;
    while (n){
        n = (n & (n-1));   // were (N & N-1) --> if N is 5 --> 0 1 0 1 (&) 0 1 0 0 ==> 0 1 0 0 (&) 0 0 1 1 ==> 0 0 0 0 
        res++;
    }cout << res << endl;
}

// Lookup-Table-Method for 32-bit Number..  :-  TC --> 0(1)
int table[256];     // 0 to 2_topower(7) -1 ==> 256 - 1
void initialize(){
    table[0] = 0;
    for (int i=1; i<256; i++){
        table[i] = (i & 1) + table[i/2];
    }
}
int count(int n){
    int res = table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    return res;
}


int32_t main(){
    int n;
    cin >> n;
    // count_of_set_bit(n);
    // BKA(n);

    return 0;
}
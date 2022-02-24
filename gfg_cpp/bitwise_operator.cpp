// There are 6 bitwise-Operator..

#include<bits/stdc++.h>
using namespace std;

void bitwise_operator(int x, int y){        // 32-bit..
    cout << (x & y) << endl;    // AND --> Both Input is True...then condition is True.
    cout << (x | y) << endl;    // OR  --> Anyone Input is True...then condition is True.
    cout << (x ^ y) << endl;    // XOR --> Both Input is " Different "..then condition is True.
    cout << (x << y) << endl; // Left-Shift --> X is shifted towards left by Y..and Zero is add at end..
    cout << (x >> y) << endl; // Right-Shift --> X is shifted towards right by Y..
    cout << (~x) << " "<<(~y) << endl; // Not --> Which gives the oppsite of its.. 
}
/*
    Left-Shift   --> X * (2_toPower(Y))
    Right-Shift  --> floor (X / (2_toPower(Y)))
    Unsigned int --> range from 0 to 2_topower(n)-1..
                    if n is 1 then value (~n) is 2_topower(32)-1 that is 4294967295 - 1
                             => 4294967294..
    Signed_int   --> main looks on MSB (Most-siginfied bit) 
                    For Using Negation..Which MSB is 1. that why we use..2_toPower(N) - X..
                    if it is 1 then it is Negative(-)
                    if it is 0 then it is Positive(+)
                    ** 2's Complement of X in N bits representation..
                     ==> 2_toPower(N) - X..
                    if N = 3_Bit.. then to representation of -2 is -> 2(to_Power(3)) - 1 
                        which is 8-1 => 7.. --> 1 1 0 -> MSB is ~1 the it is -2..
                    then for N = 32_Bit.. then to representation of ~5 is -> 2(to_Power(32)) -1 - 5 ==> -6...

*/

int un_signed(unsigned int x){
    cout << (~x) << endl;
}
int sig_ned(signed int x){
    cout << (~x) << endl;
}


int32_t main(){
    int x, y;
    cin >> x >> y;
    bitwise_operator(x, y);
    un_signed(x);
    sig_ned(x);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int get_bit(int n, int pos){ // position
    return ((n & (1 << pos)) != 0); // left -shift by pos;
}

int set_bit(int n, int pos){
    return (n | (1 << pos));
}

int clear_bit(int n, int pos){
    // int mask = ~(1 << pos);
    return (n &(~(1 << pos)));
}

int update_bit(int n, int pos, int value){
    int mask = ~(1 << pos);
    n = (n & mask); // clear_bit..
    return (n | (value << pos)); // set_bit..by value as 1.
}
int32_t main(){
    int n, pos;
    int value; // value to set like 0 or 1 in that position..
    cin >> n >> pos >> value;     
    // cout << get_bit(n, pos) << endl;
    // cout << set_bit(n, pos) << endl;
    //cout << clear_bit(n, pos) << endl;
    cout << update_bit(n, pos, value) << endl;
    return 0;
}

/*

1) Get_Bit :-
n = 0101 => n = 5;
where 0-> 3, 1-> 2, 0->1, 1->0 as Indexing..
suppose  we need to get bit at position i = 2; where 0-> 3, 1-> 2, 0->1, 1->0 are Indexing..  
1 << i (left-shif by 2)=> 0100;
0101 & 0100 => 0100;
if n &(1 << i) != 0 => then bits is 1; or it is 0;

2) Set-Bit :-
n = 0101 => n = 5;
suppose we need to set bit at position, i=1;
set => means to setting '1' and unset is setting '0';
1 << i  = 0010;
0101 | 0010 => 0111 (7 is the result..);

3) Clear-Bit :-
n = 0101 => n = 5;
suppose we need to clear bit at position, i=2;
1 << i => 0100;
~(0100) (not-of) => 1011;
0101 & 1011 => 0001; Clear the bit at index 2; 
and give the => 0001;

4) Update-Bit :- (clear-bit + set-bit);
n = 0101;
suppose we need ti update bit at position, i = 1;
first.. Clear-bit the i = 1;
1 << i => 0010 ;
~(0010) => 1101 ;
0101 & 1101 => 0101;
secound.. Set-bit the i = 1;
1 << i => 0010;
0101 | 0010 => 0111; => 7..

*/
#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char a, char b, char c){
    if (n == 1){
        cout << "Move 1 from " << a <<  " to " << c << endl;
        return;
    }
    TOH(n-1, a, c, b);
    cout << "Move " << n << " from " << a <<" to " <<  c << endl;
    TOH(n-1, b, a, c);
}

int32_t main(){
    int n; 
    char a, b, c;
    cin >> n >> a >> b >> c;
    TOH(n, a, b, c);
    return 0;
}

/*
     TOH(n, a, b, c) :=         -->   TOH(Size, From_tower, Auxiliary_tower, Destination_tower).. 
        1) TOH(n-1, a, c, b)
        2) move Disc n from a to c;
        3) TOH(n-1, b, a, c) 

        No of  movements  :-
        T(1) = 1;
        T(N) = 2T(N-1) + 1;

        ==> sum of recusion_series ==> 2(power(N-1))..

        ex -> i/0   => if N is 2 then 1 2 3
              o/0   
              =>  Move 1 from 1 to 2
                  Move 2 from 1 to 3
                  Move 1 from 2 to 3
*/
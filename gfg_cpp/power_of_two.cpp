#include<bits/stdc++.h> 
using namespace std;

// Navie-Solution :-        // TC --> 0(log N)
int power_of2(int n){ 
    if (n == 0){
        return false;
    }
    while(n != 1){          // if N == 1 then STOP.
        if (n % 2 != 0){
            return false;
        }
        n /= 2;
    }return true;
}
// Efficient - Solution...
int powerof_2(int n){               // TC --> 0(1)
    if (n == 0){
        return false;
    }
    return (n & (n-1) == 0);
}

/*
    In one we write as -> return(N != 0)&&((N & (N-1)) == 0);
*/

int32_t main(){
    int n;
    cin >> n;
    cout << power_of2(n) << endl;

    return 0;
}
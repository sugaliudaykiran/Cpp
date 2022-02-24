#include<bits/stdc++.h>
using namespace std;
// Navie-Solution..
void power(int x, int n){           // TC --> 0(N)..
    int res = 1;
    for (int i=0; i<n; i++){
        res *= x;
    }
    cout << res;
}
/* Efficient-Solution..
Power(x, n) --> if (N % 2 == 0) --> Power(x, N/2) * Power(x, N/2);
            --> if (N is Odd) ----> Power(x, N-1) * x;
Using Recusion..
*/

int Power(int x, int n){        // T(n) --> T(floor(N/2)) + 0(1)..  ===> TC --> 0(logN).. AS--> O(1).
    if (n == 0){
        return 1;
    }
    int temp = Power(x, n/2);      // T(floor(N/2))
    temp = temp * temp;
    if (n % 2 == 0){
        return temp;
    }
    else {
        return temp * x;
    }
}


int32_t main(){
    int n, x;
    cin >> x >> n;
    // power(x, n);
    // cout << Power(x, n); 
    // Using Iteration :         TC --> For Binary_representation takes O(log N)..
    int res = 1;               // AS --> O(1).. 
    while(n > 0){
        if (n % 2 != 0){       // N is Odd Number.. In Binary value of Current bit is '1' value..
            res = res * x;
        }                       // In Binary value  of Current bit is '0' Value..
        x *= x;
        n /= 2;                 // For the binary Convertion to LSB towards MSB..
    }
    cout << res << endl;
    /*
    # Every Number can be written as sum of Power of 2..(Setting the Binary_representation)..
    # We can traverse through  all bits of a Number (From LSB to MSB) in O(log N) Time..

    # we can use (N % 2 != 0) --> (N & 1)..
    # we can use (N /= 2)  -----> (N >> 1)..
    */



    return 0;
}
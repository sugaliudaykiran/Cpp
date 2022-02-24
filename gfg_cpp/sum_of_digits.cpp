#include<bits/stdc++.h>
using namespace std;

int sum_digit(int n){           // TC and AS --> 0(Digit_length) here it takes More overhead TC and AS..
    if (n <= 9){
        return n;
    }
    return sum_digit(n/10) + n%10;      // N % 10 --> Gives the last digit..
                                            // N / 10 --> Removes the Last digit..
}

// Using Iteration :-           TC --> 0(Digit_len).. AS --> 0(1)..
int sum_digits(int n){
    int res = 0;
    while(n > 0){
        res = res + n % 10;
        n /= 10;
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;

    cout << sum_digit(n) << endl;
    cout << sum_digits(n) << endl;
    return 0;
}
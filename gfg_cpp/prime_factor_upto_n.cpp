#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if (n == 1){
        return false;
    }
    else if (n == 2 || n == 3){
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
    else {
        for(int i=5; i*i <= n; i+=6){
            if (n % i == 0 || n % (i+2) == 0){
                return false;
            }
        }
        return true;
    }
}
// Naive_Solution.. TC -> O(N(square) log N);
void primefactor(int n){
    for (int i=2; i<n; i++){
        if (isPrime(i)){
            int x = i;              // for 2:  -> which repate in again in i square which divisible to n.
            while (n % x == 0){
                cout << i << ' ';   // divisor only the prime Number.
                x = x * i;
            }
        }
    }
}

/* 
Efficient-Solution :-
****    Ways   ****
1) Divisors always appear in pairs => 30 -> (1, 30), (2, 15), (3, 10), (6, 5).. => i <= (sqrt(N));
2) A number n can be written  as multiplications of powers of prime factors 
    => 12 --> (2*2) * (3*1)..
    => 450 --> (2*1) * (3*2) * (5*1)..
    => 13 --> (13*1)./.
    we can do by divide the N with first occuring prime number..till it can't.. and upgrade the N to it.. and 
    continue with next prime Number..until it can't..
*/

// Efficient_Solution..
void primefactor2(int n){
    if (n == 1)
        return;
    for (int i=2; i*i <= n; i++){
        while(n % i == 0){
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1){
        cout << n ;     // were 'i'(square) is greater than N;
    }
}

// More Efficient_Solution.. TC --> 0(sqrt_N);
void primefactor3(int n){
    if (n == 1){
        return;
    }
    while (n % 2 == 0){
        cout << 2 << ' ' ;
        n /= 2;
    }
    while (n % 3 == 0){
        cout << 3 << ' ';
        n /= 3;
    }
    for (int i=5; i*i <= n; i += 6){
        while (n % i == 0){
            cout << i << ' ';
            n /= i;
        }
        while (n % (i+2) == 0){
            cout << i << ' ';
            n /= i;
        }
    }
    if (n > 3){         // Because it should be greater than 3..
        cout << n ;
    }
}
// TC --> 0(sqrt_N);

int32_t main(){
    int n;
    cin >> n;
    // primefactor(n);
    // primefactor2(n);
    primefactor3(n);
    return 0;
}
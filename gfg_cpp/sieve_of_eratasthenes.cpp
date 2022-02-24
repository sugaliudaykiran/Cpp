// Prime Number Upto _ N :-
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
    else{
        for (int i=5; i*i <= n; i += 6){
            if (n % i == 0 || n % (i+2) == 0){
                return false;
            }
        }return true;
    }
}


// Navie - Solution...     TC -->  O(N*sqrt(N)) --> N_pow(3/2)
void print_prime_upto(int n){
    for (int i=2; i<=  n; i++){
        if (isPrime(i)){
            cout << i << ' ';
        }
    }
}

// Using Sieve :-
void sieve (int n){
    // vector <type> Vname(size, values)...
    vector <bool> is_prime(n+1, true);

    for (int i=2; i*i <= n; i++){   // prime Number start from 2.. by sqrt(N)
        if(is_prime[i]){
            for (int j = 2*i; j <= n; j += i){   // Multiple of the Number..
                is_prime[j] = false;
            }
        }
    }
    for(int i=2; i<= n; i++){
        if (is_prime[i]){
            cout << i << " ";
        }
    }
}

// Using Optimal Sieve :=       // O(n log logn)
void sieve2(int n){
    // vector <type> name(size, value)..
    vector <bool> is_prime(n+1, true);

    for (int i=2; i<=n; i++){
        if (is_prime[i]){
            cout << i << " ";
            for (int j = i*i; j <= n; j+= i){
                is_prime[j] = false;
            }
        }
    }
}

int32_t main(){
    int n;
    cin >> n;
    //print_prime_upto(n);
    // sieve(n);
    sieve2(n);
    return 0;

}
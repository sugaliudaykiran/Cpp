// prime numbers upto n using sieve..

#include<bits/stdc++.h>
using namespace std;

void primeSieve(int n){
    int prime[100] = {0}; // for prime number to store..

    for (int i=2; i<=n; i++){ // i should start from 2 because it is first prime no..
        if (prime[i] == 0) {
            for (int j = i*i; j <= n; j += i){  // we start square of it because to effective.. 
                prime[j] = 1;             //and increment by itself..
            } 
        }
    }
    for (int i=2; i<= n; i++){      // i should start from 2 because it is first prime no..
        if (prime[i] == 0){
            cout << i << " ";
        }
    }cout << endl;
}

int32_t main(){
    int n;
    cin >> n;
    primeSieve(n);
    return 0;
}
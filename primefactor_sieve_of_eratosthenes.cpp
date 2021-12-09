// primeFactorization...
// ex -> 20 --> 10 --> 5 --> 1;
//           2      2     5      ---> smallest prime factor..

#include<bits/stdc++.h>
using namespace std;

void primeFact(int n){
    int spf[100] = {0};
    for (int i=2; i<= n; i++){
        spf[i] = i;  // prime factor of 2 is 2 and 3 is 3.. and soon...
    }
    for (int i=2; i<= n; i++){
        if (spf[i] == i){
            for (int j = i * i ; j<= n; j+= i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n != 1){
        cout << spf[n] << " ";
        n = n/spf[n];
    }

}

int32_t main(){
    int n;
    cin >> n;       // 42 -> 2, 3, 7
    primeFact(n);
    return 0;
}

/*
spf[i] => smallest prime factor of i;
while(n != 1){
    print spf[n];
    n = n/ spf[n];
}

ex -> 20 --> 10 --> 5 --> 1;
          2      2     5      ---> smallest prime factor..

*/
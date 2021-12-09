#include<bits/stdc++.h>
#include<cmath>
using namespace std;

bool isprime(int N){
    for (int i =2; i <= sqrt(N); i++){
        if (N % i == 0){
            return false;
        }
    }
    return true;
}

int32_t main(){
    int a,b;
    cout << "a, b : ";
    cin >> a>> b;

    cout << "prime number between a to b : "<< endl;
    for (int i = a; i <= b; i++){
        if (isprime(i)){
            
            cout << "\t" << i << endl;
        }
    }

    return 0;
}
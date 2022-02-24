#include<bits/stdc++.h>
using namespace std;
// Navie-Solution..         // TC --> 0(N) and AS --> 0(1)..
void divisor_byN(int n){
    for (int i=1; i<=n; i++){
        if (n % i == 0){
            cout << i << " ";
        }
    }
} // Solution --> In sorted Order..

/* Efficient - ways :-
1) Divisor always appear in pairs
        => 30 -> (1,30), (5,6), (2, 15), (3, 10)..
2) one of the divisors in every pair is smaller than or equal to sqrt(N)..
        => for a pair (x,y) --->  x * y = n;
        => let x be smaller , i.e ., x <= y;
                => x * x <= N;
                => x = sqrt(N);
   ** Here It doesn't give sorted Order..
*/ 
void divisor_byN2(int n){       // TC ->  0(sqrt(N)).. AS -> 0(1)..
    for (int i=1; i*i <= n; i++){
        if (n % i == 0){
            cout << i << " ";
        }                       //  ** Here It doesn't give sorted Order..
        if (i != n/i){
            cout << n/i << " ";
        } 
    }
}

// For the Sorting Order...     // TC -> 0(sqrt(N)).. AS --> 0(1)..
void divisor_byN3(int n){
    int i;
    for (i=1; i*i < n; i++){
        if (n % i == 0){
            cout << i << " ";
        }
    } // we start from the i*i we it is not less than N.. In above case..
    for ( ; i>= 1; i--){
        if(n % i == 0){
            cout << n/i << " ";
        }
    }
}


int32_t main(){
    int n;
    cin >> n;
    
    // divisor_byN(n);
    // divisor_byN2(n); 
    divisor_byN3(n);
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Naive-Method :-  TC -> O(N)
bool prime_orNot(int n){
    if (n == 1){
        return false;
    }
    else{
        for (int i=2; i<n; i++){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }
}

// Efficient-Method :- Idea := Divisors always appear in the pairs..
// 30 -> (1, 30), (2, 15), (6,5) --> this are pairs..
// If (x,y) is a pair x*y = n;
// and if x <= y, then x*x <= n, then x <= sqrt(n);
// TC -> O(sqrt(N));
bool prime_orNot2(int n){
    if (n == 1){
        return false;
    }
    else{
        for (int i=2; i <= sqrt(n); i++){       // or (i * i <= n);
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }
}

// " More-Efficient-Method "..(For Larger N);
// Idea -> by checking n % 2 == 0 || n % 3 == 0 then return False..

bool prime_orNot3(int n){
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
        for(int i=5; i * i <= n; i += 6){
            if (n % i == 0 || n % (i+2) == 0){
                return false;
            }
        }
        return true;
    }
}

int32_t main(){
    int n;
    cin >> n;
    // cout << prime_orNot(n) << endl;
    // cout << prime_orNot2(n) << endl;
    cout << prime_orNot3(n) << endl;
    return 0;
}
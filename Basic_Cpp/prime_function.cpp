#include<bits/stdc++.h>
using namespace std;

bool prime (int N)
    {
        if (N == 1) return false;
        if (N == 2 || N == 3) return true;
        if (N % 2 == 0 || N % 3 == 0) return false;
        for (int i = 5; i*i <= N; i = i+6){             // sqrt(N) times --> O(sqrt(N))
            if (N%i == 0 || N%(i+2) == 0){
                return false;
            }
        return true;
        }
    }

int32_t main(){
    int N;
    cout << "N : ";
    cin >> N;

    if (prime(N)){
        cout << "Yes, prime No." << endl;
    }
    else cout << "Not,an prime No." << endl;
    
    return 0;
}
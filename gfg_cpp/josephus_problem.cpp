#include<bits/stdc++.h>
using namespace std;
// # using Recursion..

// In circle of N-people should  kill the "K th person" and after kill the person the next recursion
// start kill to the next person on K th position  by start position on to next to Died one 
// and Including him and start position towards kth person... # JOSEPHUS_Problem.

int jose(int n, int k){
    if (n == 1){        // If N = 1 then k will be any thing but at last he use to kill himself..right.
        return 0;
    }
            // N-1 to move the next small recursion..
    return (jose(n-1, k) + k) % n;
}   // .. -> If N is starts from 1 position then then we ADD 1 to finally result..



int32_t main(){
    int n, k;
    cin >> n >> k;
    cout << jose(n, k) << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void Using_Left_shift(int n, int k){        // if n = 5 -> 0 1 0 1, k = 3 -> 0 0 1 1;
    if (n & (1 << (k-1)) != 0){             // (1 << k-1) --> 1 << 2 --> 0 0 0 1 --> 0 1 0 0
        cout << "Yes" << endl;              //  n & (1 << k-1)  -> 0 1 0 1 (&) 0 1 0 0 -> 0 1 0 0 --> "Yes"..
    }
    else{
        cout << "No" << endl;
    }
}

void Using_Right_shift(int n, int k){       // if n = 5 -> 0 1 0 1, k = 3 -> 0 0 1 1;
    if ((n >> k-1) & 1 == 1) {              // (n >> k-1) --> 0 1 0 1 (>>) 2 --> 0 0 0 1
        cout << "Yes" << endl;              // (0 0 0 1) (&) 0 0 0 1 --> 0 0 0 1 --> "Yes"..
    }
    else{
        cout << "No" << endl;
    }
}

int32_t main(){     // K ' <= ' No.of_bits in binary representation..
    int n, k;       // from LSB in ckeck of k is set or not..
    cin >> n >> k;
    Using_Left_shift(n, k);
    Using_Right_shift(n, k);
    return 0;
}
// Square root          ---------> Floor of the Value ....
// Given an integer, we need to find floor of its square root. This video talks about two methods.

#include<bits/stdc++.h>
using namespace std;

// Navie-Solution :-       TC --> O(sqrt_N)..
int sq_rt(int n){
    int i = 1;
    while (i * i <= n){     //--------> Floor of the Value ....
        i++;
    }
    return i-1;
}

// Using Binary_search :-  Tc --> O(log_N).. and AS --> O(1)..--> Floor of the Value ....
int sqrts(int n){
    int low = 1, high = n, res = -1;   // Here low start from 1 ..and high = N..
    while (low <= high){                // Upto Low <= High//
        int mid = (low + high) / 2;
        int m_sqt = mid * mid;          // we use Mid_sqrt which checks to N..
        if (m_sqt == n){
            return mid;
        }
        else if (m_sqt > n){            // If Mid_sqrt is greater move to left-side..
            high = mid -1;
        }
        else{                          // Else to Left-side and store the recant value..
            low = mid + 1;
            res = mid;
        }
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;

    // cout << sq_rt(n);
    cout << sqrts(n);
    return 0;
}
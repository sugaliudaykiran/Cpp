// Minimum Difference in an Array :=    The Difference between two elements should be Min and return it..
//                                      If the N == 1 then return INT_MAX..then it Should contain Alteast Two elements..

#include<bits/stdc++.h>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

// Navie - Solution :-          TC --> 0(N_square)..
int min_dif(int ar[], int n){
    int res = INT_MAX;

    for (int i=1; i<n; i++){            // For the i-itertion we loop from "0 to i-1"..
        for (int j=0; j<i; j++){
            res = min(res, abs(ar[i] - ar[j]));
        }
    }
    return res;
}

/*  
    Efficient - Solution :-     TC is O(N_LogN)..
        A) First we sort the Array..
        B) Compute Difference Between the Adjacent elements..
        C) And return Minimum Differences..
*/ 
int min_d(int ar[], int n){       //  TC -->  O(N_LogN)..
    sort(ar, ar+n);         // TC is O(N_LogN)..

    int res = INT_MAX;

    for(int i=1; i<n; i++){             // TC is 0(N)..
        res = min(res, abs(ar[i] - ar[i-1]));
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;

    int ar[n];
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // cout << min_dif(ar, n);
    cout << min_d(ar, n);
    return 0;
}
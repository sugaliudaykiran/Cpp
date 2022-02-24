#include<bits/stdc++.h>
using namespace std;
// Navie_Solution :-
int max_d(int ar[], int n){     // TC ---> 0(N_square)
    int res = ar[1] - ar[0];
    
    for (int i=0; i<n-1; i++){          // Upto N-1 because of last to iterate..
        for (int j=i+1; j<n; j++){      // j > i  => j start with i+1.. upto N
            res = max(res, ar[j] - ar[i]);
        }
    }
    return res;
}
// Efficient-Solution :-        TC --> 0(N)..
int maxDif(int ar[], int n){
    int res = ar[1] - ar[0];    
    int minval = ar[0];

    for (int j=1; j<n; j++){            // Checking from the first_Index..
        res = max(res, ar[j] - minval); 
        minval = min(minval, ar[j]);
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

    // cout << max_d(ar, n) << endl;
    cout << maxDif(ar, n) << endl;
    return 0;
}